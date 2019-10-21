#include "Maincontrol.h"
#include "ui_Maincontrol.h"
#include "Login.h"


Maincontrol::Maincontrol(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Maincontrol)
{
    ui->setupUi(this);
    Maincontrol::setWindowTitle(QString("Welcome!"));
    setAutoFillBackground(true);
}

Maincontrol::~Maincontrol()
{
    delete ui;
}

//返回主页面
void Maincontrol::on_backhome_clicked()
{
    hl=new Homepage();
    this->hide();
    hl->show();
}

//增添界面
void Maincontrol::on_AddCard_clicked()
{
    al=new Addpage();
    this->hide();
    al->show();
}

//删除界面
void Maincontrol::on_DeleteCard_clicked()
{
    dl = new Deletepage();
    this->hide();
    dl->show();
}

//编辑界面
void Maincontrol::on_UpdateCard_clicked()
{
    ul = new Updatepage();
    this->hide();
    ul->show();
}

//登出
void Maincontrol::on_back_clicked()
{
    Login *ln = new Login();
    ln->show();
    this->hide();
}

//查找界面
void Maincontrol::on_SelectCard_clicked()
{
    sl = new Selectpage();
    this->hide();
    sl->show();
}

//登录管理信息
void Maincontrol::on_AdminCard_clicked()
{
    an = new Adminlogin();
    this->hide();
    an->show();
}
