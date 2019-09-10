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
    hl.show();
    this->hide();
}

//增添界面
void Maincontrol::on_AddCard_clicked()
{
    al.show();
    this->hide();
}

//删除界面
void Maincontrol::on_DeleteCard_clicked()
{
    dl.show();
    this->hide();
}

//编辑界面
void Maincontrol::on_UpdateCard_clicked()
{
    ul.show();
    this->hide();
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
    sl.show();
    this->hide();
}

//登录管理信息
void Maincontrol::on_AdminCard_clicked()
{
    an.show();
    this->hide();
}
