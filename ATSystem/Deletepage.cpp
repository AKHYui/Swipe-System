#include "Deletepage.h"
#include "ui_Deletepage.h"
#include "Maincontrol.h"

Deletepage::Deletepage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deletepage)
{
    ui->setupUi(this);
}

Deletepage::~Deletepage()
{
    delete ui;
}


//返回
void Deletepage::on_delback_clicked()
{
    Maincontrol *mcl = new Maincontrol();
    mcl->show();
    this->hide();
}
