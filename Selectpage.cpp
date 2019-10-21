#include "Selectpage.h"
#include "ui_Selectpage.h"
#include "Maincontrol.h"
#include "QFileDialog"
#include "ATSysDatabaseControl.h"
#include "QMessageBox"
#include "QTableWidgetItem"
#include<QDebug>

Selectpage::Selectpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Selectpage)
{
    ui->setupUi(this);
    Selectpage::setWindowTitle(QString("Select it!"));

    // 选择13.56M读写器
    //IEEE14443是一个RFID的ISO标准，用来读取13.56M频率的IC卡
    RFIDChannelMan::setChannel(RFIDChannelMan::ChannelIEEE14443);
    // 创建13.56M读写器操作类对象
    rfid = new IEEE14443Control(this);
    // 连接出错和寻卡成功的信号
    //信号槽机制：connect(A,A1,B,B1);
    //其中A代表的是发出信号的对象，A1代表的是发出的信号
    //其中B代表的是接受信号的对象，B1代表的是接受到信号后需要调用或执行的函数
    //error信号代表的是读卡器操作过程中有错误。
    connect(rfid, SIGNAL(error(int,QString)),
            this, SLOT(on_search_error(int,QString)));
     //foundCard信号代表的是读卡器获取到了卡号信息，并存储到参数QByteArray中。
    connect(rfid, SIGNAL(foundCard(QByteArray)),
            this, SLOT(on_search_success(QByteArray)));
    connect(rfid, SIGNAL(dataReaded(int,QByteArray)),
            this, SLOT(on_ted_showID(int,QByteArray)));
    //start函数代表打开与13.56M读写器相连的串口，并初始化
    //RFIDChannelMan::getRfidPort()代表获取与读卡器相连接的串口，即设备文件路径
//     rfid->start(RFIDChannelMan::getRfidPort());
    rfid->start("/dev/ttyUSB0");
     //rfid->start("COM4");
}

Selectpage::~Selectpage()
{
    delete ui;
}

//将数据库中信息显示在界面上
void Selectpage::load()
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
void Selectpage::on_sel_back_clicked()
{
    Maincontrol *mcl = new Maincontrol();
    mcl->show();
    this->hide();
    rfid->stop();
}

//选择数据库
void Selectpage::on_btn_dbselect_clicked()
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

//刷新
void Selectpage::on_btn_dbrefresh_clicked()
{
    load();
}

//查询功能
void Selectpage::on_pbn_search_clicked()
{
    /*if(ui->ted_showNumber->text().isEmpty())
    {
        QMessageBox::warning(this, "warning", "ID is empty");
        return;
    }*/
    //查询功能实现
    qlonglong card = ui->ted_showNumber->text().toLongLong();
    QList<employee_info> list = ATSysDatabaseControl::loadAllEmploy(card);
    while (ui->db_table->rowCount() > 0)
        ui->db_table->removeRow(0);
    for(int i = 0;i < list.count();i++){
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

//查看日志
void Selectpage::on_pbn_searchLog_clicked()
{
    QList<QTableWidgetItem *> sel = ui->db_table->selectedItems();
    if(sel.isEmpty())
    {
        QMessageBox::warning(this, "警告", "请选择要查看日志的员工信息");
        return;
    }
    int row = sel[0]->row();
    qlonglong card = ui->db_table->item(row, 0)->text().toLongLong();//卡号在第0列，之前：item(row, 1)
    qDebug()<<"card:"<<QString::number(card);
    log_load(card); //调用加载日志信息列表的函数
}

//加载日志信息列表的函数
void Selectpage::log_load(qlonglong card)
{
   qDebug()<<"log_load card:"<<QString::number(card);
    QList<log_info> loglist = ATSysDatabaseControl::loadAllLog(card);
    while(ui->logTable->rowCount() > 0)
        ui->logTable->removeRow(0);//?
    for(int i = 0; i < loglist.count(); i++)
    {
        const log_info &info = loglist.at(i);
        QString dt = info.date.toString("yyyy-MM-dd hh:mm:ss");
//        qDebug<<"dt:"<<dt;
//          qDebug<<"card:"<<info.card;
        ui->logTable->insertRow(i);
        ui->logTable->setItem(i, 0,
                            new QTableWidgetItem(QString::number(info.card)));
        ui->logTable->setItem(i, 1,
                            new QTableWidgetItem(info.name));
        ui->logTable->setItem(i, 2,
                            new QTableWidgetItem(dt));
    }
 }


/*---------------------------13.56M读卡-----------------*/
/**
 * @brief onNewCard
 * 获取到ID卡时执行的槽函数
 *
 * @param decID 由newCard()信号传递过来的卡号
 * @param byteID 由newCard()信号传递过来的卡号
 */
void Selectpage::onNewCard(qlonglong decID, const QByteArray &byteID)
{
    QList<QTableWidgetItem*> lists =
            ui->db_table->findItems(QString::number(decID), Qt::MatchExactly);
    if(lists.isEmpty())
    {
        ui->ted_showNumber->setText(QString::number(decID));
        ui->ted_showNumber->setFocus();
    }
    else
    {
        ui->db_table->selectRow(lists.at(0)->row());
        ui->ted_showNumber->setFocus();
    }
}

//------------------------13.56M读卡-----------------------//
//槽函数，获取卡号失败的函数
void Selectpage::on_search_error(int cmdType, const QString &result)
{

    if(cmdType == IEEE14443Control::GetCardId)
       QMessageBox::information(this, "提示", "读卡错误！");
}
void Selectpage::on_search_success(const QByteArray &cardid)
{

    qlonglong decID;
    bool ok;

    qDebug()<<"==[on_search_success]==get cardID:"<<cardid.toHex();
    decID = cardid.toHex().toLongLong(&ok, 16);

    qDebug()<<"====get cardID:"<<QString::number(decID);
    // 读卡过程中获得卡号，显示卡号
    ui->ted_showNumber->setText(QString::number(decID));
    onNewCard(decID,cardid);
}

//读卡完成，显示读取到到数据
void Selectpage::on_ted_showID(int block, const QByteArray &data)
{
  QMessageBox::information(this, "提示", data.toHex());

}

void Selectpage::on_readcard_clicked()
{
    // 点击按钮时，启动寻卡操作
    rfid->getCardId();
}
