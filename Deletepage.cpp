#include "Deletepage.h"
#include "ui_Deletepage.h"
#include "Maincontrol.h"
#include "QFileDialog"
#include "ATSysDatabaseControl.h"
#include "QMessageBox"
#include <QTableWidgetItem>
#include "ChannelMan/RFIDChannelMan.h"
//#include "ID125K/ID125KControl.h"
#include "IEEE14443/IEEE14443Control.h"
#include<QDebug>

Deletepage::Deletepage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deletepage)
{
    ui->setupUi(this);
    Deletepage::setWindowTitle(QString("Delete information"));
    // 选择13.56M读写器
    RFIDChannelMan::setChannel(RFIDChannelMan::ChannelIEEE14443);
    // 创建13.56M读写器操作类对象
    rfid = new IEEE14443Control(this);

    // 连接出错、寻卡成功以及读卡成功的信号
    connect(rfid, SIGNAL(error(int,QString)),
            this, SLOT(on_search_error(int,QString)));
    connect(rfid, SIGNAL(foundCard(QByteArray)),
            this, SLOT(on_search_success(QByteArray)));
    connect(rfid, SIGNAL(dataReaded(int,QByteArray)),
            this, SLOT(on_ted_showID(int,QByteArray)));

     //rfid->start("COM4");
    rfid->start("/dev/ttyUSB0");
}

Deletepage::~Deletepage()
{
    delete ui;
}

//将数据库中信息显示在界面上
void Deletepage::load()
{
    QList<employee_info> list = ATSysDatabaseControl::load();
    while(ui->db_table->rowCount() > 0)
        ui->db_table->removeRow(0);
    for(int i = 0; i < list.count(); i++)
    {
        const employee_info &info = list.at(i);
        ui->db_table->insertRow(i);
        ui->db_table->setItem(i, 0,
                              new QTableWidgetItem(QString::number(info.card))
                              );
        ui->db_table->setItem(i, 1,
                              new QTableWidgetItem(info.name));
        ui->db_table->setItem(i, 2,
                              new QTableWidgetItem(info.sex));
        ui->db_table->setItem(i, 3,
                              new QTableWidgetItem(info.state));
    }
}

//返回
void Deletepage::on_delback_clicked()
{
    Maincontrol *mcl = new Maincontrol();
    mcl->show();
    this->hide();
    rfid->stop();
}

//选择数据库
void Deletepage::on_btn_dbselect_clicked()
{
    QString dbPath = QFileDialog::getSaveFileName(
                    this, "选择文件",
                    ui->ted_dbpath->text(),
                    "数据库(*.db *.db3)",
                    NULL,
                    QFileDialog::DontConfirmOverwrite);
        if(dbPath.isEmpty())
            return;
        if(ATSysDatabaseControl::setDatabase(dbPath))
        {
            ui->ted_dbpath->setText(dbPath);
        }
    load();
}

//删除员工信息
void Deletepage::on_ptn_delete_clicked()
{
    QList<QTableWidgetItem *> sel = ui->db_table->selectedItems();
    if(sel.isEmpty())
    {
        QMessageBox::warning(this, "警告", "没有选择任何信息");
        return;
    }
    //删除用户信息
    int row = sel[0]->row();
    qlonglong card = ui->db_table->item(row, 0)->text().toLongLong();
    ATSysDatabaseControl::remove(card);
    ui->db_table->removeRow(row);
    load();
    QMessageBox::information(this, "information", "OK");
}

//注销功能
void Deletepage::on_ptn_release_clicked()
{
    QList<QTableWidgetItem *> sel = ui->db_table->selectedItems();
    if(sel.isEmpty())
    {
        QMessageBox::warning(this, "警告", "没有选择任何信息");
        return;
    }
    //注销用户信息
    int row = sel[0]->row();
    qlonglong card = ui->db_table->item(row, 0)->text().toLongLong();
    ATSysDatabaseControl::cancel(card);
    load();
    QMessageBox::information(this, "information", "OK");
}

/*-----------------------13.56M 寻卡---------------------*/
/**
 * @brief onNewCard
 * 获取到ID卡时执行的槽函数
 *
 * @param decID 由newCard()信号传递过来的卡号
 * @param byteID 由newCard()信号传递过来的卡号
 */
void Deletepage::onNewCard(qlonglong decID)
{
    QList<QTableWidgetItem*> lists =
            ui->db_table->findItems(QString::number(decID), Qt::MatchExactly);
    if(lists.isEmpty())
    {
    QMessageBox::information(this, "提示", "此卡号未注册");
      return;
    }
    else
    {
        ui->db_table->selectRow(lists.at(0)->row());
        QList<QTableWidgetItem*> items = ui->db_table->selectedItems();//获取选中的行信息
        ui->btn_card->setText(items.at(0)->text());
        ui->btn_name->setText(items.at(1)->text());
//        ui->ted_showName->setFocus();
    }
}


//槽函数，获取卡号失败的函数
void Deletepage::on_search_error(int cmdType, const QString &result)
{

    if(cmdType == IEEE14443Control::GetCardId)
        //rfid->getCardId();
        QMessageBox::information(this, "提示", "读卡错误！");
}
void Deletepage::on_search_success(const QByteArray &cardid)
{
    qlonglong decID;
    bool ok;

    qDebug()<<"==[on_search_success]==get cardID:"<<cardid.toHex();
    decID = cardid.toHex().toLongLong(&ok, 16);
    //读卡成功，将卡号显示在文本框中
     ui->btn_card->setText(QString::number(decID));

    qDebug()<<"====get cardID:"<<QString::number(decID);
    // 读卡过程中获得卡号，显示卡号
    onNewCard(decID);
}

//读卡完成，显示读取到到数据
void Deletepage::on_ted_showID(int block, const QByteArray &data)
{
    QMessageBox::information(this, "提示", data.toHex());
}

void Deletepage::on_pushButton_4_clicked()
{
    // 点击按钮时，启动寻卡操作
    rfid->getCardId();
}
