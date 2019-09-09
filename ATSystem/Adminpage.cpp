#include "Adminpage.h"
#include "ui_Adminpage.h"
#include "Maincontrol.h"

Adminpage::Adminpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Adminpage)
{
    ui->setupUi(this);
}

Adminpage::~Adminpage()
{
    delete ui;
}

//返回界面
void Adminpage::on_pbn_back_clicked()
{
    Maincontrol *mcl = new Maincontrol();
    mcl->show();
    this->hide();
}
