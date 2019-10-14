#include "Addpage.h"
#include "ui_Addpage.h"
#include "Maincontrol.h"
#include "ATSysDatabaseControl.h"

#include <QMessageBox>
#include "QFileDialog"
#include <QTableWidgetItem>
#include "QDebug"

Addpage::Addpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Addpage)
{
    ui->setupUi(this);
    Addpage::setWindowTitle(QString("Add information"));
    // 选择13.56M读写器
    RFIDChannelMan::setChannel(RFIDChannelMan::ChannelIEEE14443);
    // 创建13.56M读写器操作类对象
    rfid = new IEEE14443Control(this);
    // 连接出错、寻卡成功以及读卡成功的信号
    //connect系统函数，连接信号和槽的桥梁
    //只要触发rfid对象中的error信号(只去掉用)，系统会自动执行this中的on_search_error函数，可以开发
    connect(rfid, SIGNAL(error(int,QString)),
            this, SLOT(on_search_error(int,QString)));
    connect(rfid, SIGNAL(foundCard(QByteArray)),
            this, SLOT(on_search_success(QByteArray)));
    connect(rfid, SIGNAL(dataReaded(int,QByteArray)),
            this, SLOT(on_ted_showID(int,QByteArray)));
    //Windows使用第一个，Linux使用第二个
    //rfid->start("COM4");
    rfid->start("/dev/ttyUSB0");
}

Addpage::~Addpage()
{
    delete ui;
}

//将数据库中信息显示在界面上
void Addpage::load()
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
void Addpage::on_pbn_back_clicked()
{
    Maincontrol *mcl = new Maincontrol;
    mcl->show();
    this->hide();
    rfid->stop();
}

//按下登记所产生的效果
void Addpage::on_pbn_addName_clicked()
{
    if(ui->ted_showNumber->text().isEmpty() || ui->ted_showName->text().isEmpty())
    {
        QMessageBox::warning(this, "Warning", "no Empty");
        return;
    }
    //添加用户信息，默认正常
    ATSysDatabaseControl::add(ui->ted_showNumber->text().toLongLong(),
                              ui->ted_showName->text(),
                              ui->ted_showSex->currentText(),
                              "正常");
    load();
    ui->ted_showNumber->clear();
    ui->ted_showName->clear();
    ui->ted_showSex->currentIndex();
    QMessageBox::information(this, "information", "OK");
}

//选择数据库按钮
void Addpage::on_btn_dbselect_clicked()
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

/*---------------------------13.56M读卡-----------------*/
/**
 * @brief onNewCard
 * 获取到ID卡时执行的槽函数
 *
 * @param decID 由newCard()信号传递过来的卡号
 * @param byteID 由newCard()信号传递过来的卡号
 */
void Addpage::onNewCard(qlonglong decID, const QByteArray &byteID)
{
    QList<QTableWidgetItem*> lists =
            ui->db_table->findItems(QString::number(decID), Qt::MatchExactly);
    if(!lists.isEmpty())//如果列表中存在对应的卡号信息，则选中表中的信息
        ui->db_table->selectRow(lists.at(0)->row());
    ui->ted_showNumber->setFocus();
}

//------------------------13.56M读卡-----------------------//
//槽函数，获取卡号失败的函数
void Addpage::on_search_error(int cmdType, const QString &result)
{

    if(cmdType == IEEE14443Control::GetCardId)
        //获取卡号的时候炸了
//        rfid->getCardId();
       QMessageBox::information(this, "提示", "读卡错误！");
}
void Addpage::on_search_success(const QByteArray &cardid)
{

    qlonglong decID;
    bool ok;
    qDebug()<<"==[on_search_success]==get cardID:"<<cardid.toHex();
    decID = cardid.toHex().toLongLong(&ok,16);
    qDebug()<<"====get cardID:"<<QString::number(decID);
    // 读卡过程中获得卡号，显示卡号
    ui->ted_showNumber->setText(QString::number(decID));
    onNewCard(decID,cardid);

}

//读卡完成，显示读取到到数据
void Addpage::on_ted_showID(int block, const QByteArray &data)
{
  QMessageBox::information(this, "提示", data.toHex());

}

void Addpage::on_pbn_start_clicked()
{
    // 点击按钮时，启动寻卡操作
    rfid->getCardId();
}
