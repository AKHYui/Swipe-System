#include "Homepage.h"
#include "ui_Homepage.h"
#include "Maincontrol.h"
#include "ATSysDatabaseControl.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include "Login.h"
//#include <QDateTime>

Homepage::Homepage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Homepage)
{
    ui->setupUi(this);
    Homepage::setWindowTitle(QString("Index"));


    timer1 = new QTimer(this);
    //在界面上显示时间
    connect(timer1,SIGNAL(timeout()),this,SLOT(showTime()));
    timer1->start(500);//启动定时器


    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(hideTip()));
    timer2->setSingleShot(true);
    timer2->setInterval(3000);//设置定时器每个多少毫秒发送一个timeout()信号

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
            this, SLOT(on_show_data(int,QByteArray)));

    rfid->start("/dev/ttyUSB0");

    //rfid->start("COM4");



    hideTip();
}

Homepage::~Homepage()
{
    delete ui;
}

/**
 * @brief Widget::onNewCard
 * 获取到ID卡时执行的槽函数
 * @param decID 由newCard()信号传递过来的卡号
 * @param byteID 由newCard()信号传递过来的卡号
 */
void Homepage::onNewCard(qlonglong decID, const QByteArray &byteID)
{
    employee_info info = ATSysDatabaseControl::load(decID);
    qDebug()<<"card:"<<QString::number(decID);
    qDebug()<<"id:"<<QString::number(info.id);
    if(info.id > 0 && info.state == "正常" )
    {
        showTip("欢迎你 " + info.name, true);
        ATSysDatabaseControl::checkIn(decID, info.name);
    }
    else if(info.id > 0 && info.state == "已注销" )
    {
        showTip("此卡已注销 " ,false);
    }
    else
        showTip("此卡无效", false);
    timer2->start();
}


//显示时间
void Homepage::showTime()
{
    QTime time = QTime ::currentTime(); //当前时间
    QDateTime dt = QDateTime::currentDateTime();//当前日期
    QString txtTime = time.toString("hh:mm");
    ui->lcdNumber->display(txtTime); //LCD时间显示
    ui->date->setText(dt.toString("yyyy-MM-dd ddd"));//日期显示
}


/**
 * @brief Widget::showTip
 * 用于显示刷卡后的提示信息
 * @param tip 提示信息
 * @param valid 绿色指示灯是否点亮
 */
void Homepage::showTip(const QString &tip, bool valid)
{
    ui->lb_tip->setText(tip);
    ui->lb_tip->show();
    if(valid)
    {
        ui->lb_red->setStyleSheet("");
        ui->lb_green->setStyleSheet(
                    "background-color: rgb(0, 255, 0);\n"
                    "border-radius: 30px;");
    }
    else
    {
        ui->lb_red->setStyleSheet("background-color: rgb(255, 0, 0);\n"
                                  "border-radius: 30px;");
        ui->lb_green->setStyleSheet("");
    }
}

/**
 * @brief Widget::hideTip
 * 关闭刷卡后的提示信息的显示
 */
void  Homepage::hideTip()
{
    ui->lb_tip->hide();
    ui->lb_red->setStyleSheet("");
    ui->lb_green->setStyleSheet("");
}


//fanhui
void Homepage::on_ctrl_clicked()
{
    Login *mcl = new Login();
    mcl->show();
    this->hide();
    rfid->stop();
}





/*--------------------读卡功能--------------------------------*/
//槽函数，获取卡号失败的函数
void Homepage::on_search_error(int cmdType, const QString &result)
{

    if(cmdType == IEEE14443Control::GetCardId)
        qDebug()<<"==[on_search_success]";
    QMessageBox::information(this, "提示", "读卡错误！");
}
void Homepage::on_search_success(const QByteArray &cardid)
{
    qlonglong decID;
    bool ok;
    qDebug()<<"success";

    qDebug()<<"==[on_search_success]==get cardID:"<<cardid.toHex();
    decID = cardid.toHex().toLongLong(&ok, 16);

    qDebug()<<"====get cardID:"<<QString::number(decID);
    // 读卡过程中获得卡号，显示卡号
    onNewCard(decID,cardid);

}
//
void Homepage::on_show_data(int block, const QByteArray &data)
{
    //读卡完成，显示读取到到数据
    QMessageBox::information(this, "提示", data.toHex());
}

//daka
void Homepage::on_pushButton_2_clicked()
{
    //ATSysDatabaseControl::setNewDatabase()是将路径设置成为固定的路径了。
    if(ATSysDatabaseControl::setDatabase(ATSysDatabaseControl::setNewDatabase()))
    {
        // 点击按钮时，启动寻卡操作
        rfid->getCardId();
        qDebug()<<"punsh button";
    }
    else
    {
        //数据库连接失败
        QMessageBox::information(this, "提示", "数据库初始化失败！");
    }
}
