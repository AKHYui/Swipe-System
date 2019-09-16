#include "Login.h"
#include "ui_Login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
    setStyleSheet("background-color: gray");
}

//重置功能
void Login::on_pushButton_2_clicked()
{
    ui->username->setText("");
    ui->pwd->setText("");
}

//登陆功能
void Login::on_login_clicked()
{
    if(ui->username->text()=="1" && ui->pwd->text()=="1")
    {
        //跳转到主界面
        ml.show();//显示主界面
        this->hide();//隐藏当前界面
    }
    else
    {
        ui->username->setText("404 Not Found!");//登陆失败
    }
}
