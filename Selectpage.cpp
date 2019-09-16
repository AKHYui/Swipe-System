#include "Selectpage.h"
#include "ui_Selectpage.h"
#include "Maincontrol.h"
#include "QFileDialog"
#include "ATSysDatabaseControl.h"
#include "QMessageBox"

Selectpage::Selectpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Selectpage)
{
    ui->setupUi(this);
    Selectpage::setWindowTitle(QString("Select it!"));
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

//选择数据库
void Selectpage::on_btn_dbselect_clicked()
{
    QString dbPath = QFileDialog::getSaveFileName(
                    this, "选择文件",
                    ui->ted_dbpath->text(),
                    "数据库(*.db *.db3)",
                    NULL,
                    QFileDialog::DontConfirmOverwrite);
        if(dbPath.isEmpty())
            return;
        if(ATSysDatabaseControl::setDatabase(dbPath))
        {
            ui->ted_dbpath->setText(dbPath);
        }
}
