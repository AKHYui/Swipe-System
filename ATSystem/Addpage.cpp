#include "Addpage.h"
#include "ui_Addpage.h"
#include "Maincontrol.h"

Addpage::Addpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Addpage)
{
    ui->setupUi(this);
}

Addpage::~Addpage()
{
    delete ui;
}

//返回
void Addpage::on_pbn_back_clicked()
{
    Maincontrol *mcl = new Maincontrol;
    mcl->show();
    this->hide();
}
