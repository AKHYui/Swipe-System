#include "Selectpage.h"
#include "ui_Selectpage.h"
#include "Maincontrol.h"

Selectpage::Selectpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Selectpage)
{
    ui->setupUi(this);
}

Selectpage::~Selectpage()
{
    delete ui;
}

void Selectpage::on_sel_back_clicked()
{
    Maincontrol *mcl = new Maincontrol();
    mcl->show();
    this->hide();
}
