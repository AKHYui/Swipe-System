#include "Updatepage.h"
#include "ui_Updatepage.h"
#include "Maincontrol.h"
#include "ATSysDatabaseControl.h"
#include "QMessageBox"
#include "QFileDialog"
#include "QTableWidgetItem"
#include <QDebug>

Updatepage::Updatepage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Updatepage)
{
    ui->setupUi(this);
    Updatepage::setWindowTitle(QString("Update"));

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

//    rfid->start(RFIDChannelMan::getRfidPort());
//    rfid->start("COM4");
     rfid->start("/dev/ttyUSB0");
}

Updatepage::~Updatepage()
{
    delete ui;
}

//将数据库中信息显示在界面上
void Updatepage::load()
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
void Updatepage::on_updateback_clicked()
{
    Maincontrol *mcl = new Maincontrol;
    mcl->show();
    this->hide();
    rfid->stop();
}

//选择数据库
void Updatepage::on_btn_dbselect_clicked()
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

//修改提交按钮
void Updatepage::on_pbn_addName_clicked()
{
    if(ui->ted_showNumber->text().isEmpty() || ui->ted_showName->text().isEmpty())
    {
        QMessageBox::warning(this, "warning", "no Empty");
        return;
    }
    //修改用户信息
    ATSysDatabaseControl::update(ui->ted_showNumber->text().toLongLong(),
                                 ui->ted_showName->text(),
                                 ui->ted_showSex->currentText(),
                                 ui->cb_updateState->currentText());
    ui->ted_showNumber->clear();
    ui->ted_showName->clear();
    ui->ted_showSex->currentIndex();
    ui->cb_updateState->clear();
    load();
    QMessageBox::information(this, "information", "OK");
}

/*---------------------------13.56M读卡-----------------*/
/**
 * @brief onNewCard
 * 获取到ID卡时执行的槽函数
 *
 * @param decID 由newCard()信号传递过来的卡号
 * @param byteID 由newCard()信号传递过来的卡号
 */
void Updatepage::onNewCard(qlonglong decID)
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
        ui->db_table->selectRow(lists.at(0)->row());    //先选中某一行
        QList<QTableWidgetItem*> items = ui->db_table->selectedItems();//获取选中的行信息
        ui->ted_showNumber->setText(items.at(0)->text());
        ui->ted_showName->setText(items.at(1)->text());
//        ui->cb_updateSex->setText(items.at(2)->text());
  //    ui->cb_updateState->setItemText(0,items.at(3)->text());
    }
}

//------------------------13.56M读卡-----------------------//
//槽函数，获取卡号失败的函数
void Updatepage::on_search_error(int cmdType, const QString &result)
{

    if(cmdType == IEEE14443Control::GetCardId)
    //    rfid->getCardId();
       QMessageBox::information(this, "提示", "读卡错误！");
}
void Updatepage::on_search_success(const QByteArray &cardid)
{

    qlonglong decID;
    bool ok;

    qDebug()<<"==[on_search_success]==get cardID:"<<cardid.toHex();
    decID = cardid.toHex().toLongLong(&ok, 16);
    qDebug()<<"====get cardID:"<<QString::number(decID);
    //读卡成功，将卡号显示在文本框中
    ui->ted_showNumber->setText(QString::number(decID));
    // 读卡过程中获得卡号，显示卡号
    onNewCard(decID);

}

//读卡完成，显示读取到到数据
void Updatepage::on_ted_showID(int block, const QByteArray &data)
{
  QMessageBox::information(this, "提示", data.toHex());

}

void Updatepage::on_pbn_start_clicked()
{
    // 点击按钮时，启动寻卡操作
    rfid->getCardId();

}
