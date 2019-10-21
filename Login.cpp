#include "Login.h"
#include "ui_Login.h"
#include "ATSysDatabaseControl.h"
#include<QMessageBox>
#include <Maincontrol.h>

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
    //ATSysDatabaseControl::setNewDatabase()是将路径设置成为固定的路径了。
    if(ATSysDatabaseControl::setDatabase(ATSysDatabaseControl::setNewDatabase()))
    {
        QString uname;
        QString upwd;
        uname = ui->username->text();//获取用户名e
        upwd = ui->pwd->text();//获取密码
        manage_info info = ATSysDatabaseControl::manageload(uname);
        //    if(info.manageid == user &&  QString::compare(pwd, info.pwd, Qt::CaseInsensitive)==0)//字符串的比较
        //       qDebug() << "uname:"<<uname;
        //       qDebug() << "info.name:"<<info.name;
        //       qDebug() << "upwd:"<<upwd;
        //       qDebug() << "info.pwd:"<<info.pwd;
        if(((info.name == uname)&&(info.pwd == upwd)&&(uname != "")&&(upwd != ""))||((uname == "admin")&&(upwd=="123456")))
            //在这里修改超级管理员账号，密码
        {
            Maincontrol *uid = new Maincontrol();
            uid->show();
            this->hide();
        }
        else if(ui->username->text() == "")
            QMessageBox::warning(this,"提示","用户名不能为空！");
        else if(upwd == "")
            QMessageBox::warning(this,"提示","密码不能为空！");
        else
            QMessageBox::warning(NULL,"提示","用户名或密码错误！");
    }
}

