#include "Updatepage.h"
#include "ui_Updatepage.h"
#include "Maincontrol.h"

Updatepage::Updatepage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Updatepage)
{
    ui->setupUi(this);
    Updatepage::setWindowTitle(QString("Update"));
}

Updatepage::~Updatepage()
{
    delete ui;
}


//返回
void Updatepage::on_updateback_clicked()
{
    Maincontrol *mcl = new Maincontrol;
    mcl->show();
    this->hide();
}
