#include "Adminlogin.h"
#include "ui_Adminlogin.h"
#include "Maincontrol.h"
#include "Adminpage.h"

Adminlogin::Adminlogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Adminlogin)
{
    ui->setupUi(this);
    Adminlogin::setWindowTitle(QString("Give me your admin password please!"));
}

Adminlogin::~Adminlogin()
{
    delete ui;
}

//返回
void Adminlogin::on_alogback_clicked()
{
    Maincontrol *mcl = new Maincontrol();
    mcl->show();
    this->hide();
}

//重置
void Adminlogin::on_ptn_reset_clicked()
{
    ui->user->setText("");
    ui->pwd->setText("");
}

//登录
void Adminlogin::on_ptn_login_clicked()
{
    if(ui->user->text()=="111111" && ui->pwd->text()=="111111"){//账号正确时
        ae = new Adminpage();
        ae->show();
        this->hide();
    }
    else{//账号错误时
        ui->user->setText("404 Not Found!");
    }
}
