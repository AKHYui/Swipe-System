#include "Updatepage.h"
#include "ui_Updatepage.h"
#include "Maincontrol.h"
#include "ATSysDatabaseControl.h"
#include "QMessageBox"
#include "QFileDialog"

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

//选择数据库
void Updatepage::on_btn_dbselect_clicked()
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

//修改提交按钮
void Updatepage::on_pbn_addName_clicked()
{
    if(ui->ted_showNumber->text().isEmpty() || ui->ted_showName->text().isEmpty())
    {
        QMessageBox::warning(this, "warning", "no Empty");
        return;
    }
    //修改用户信息
    ATSysDatabaseControl::update(ui->ted_showNumber->text().toLongLong(),
                                 ui->ted_showName->text(),
                                 ui->ted_showSex->currentText(),
                                 ui->cb_updateState->currentText());
    ui->ted_showNumber->clear();
    ui->ted_showName->clear();
    ui->ted_showSex->clear();
    ui->cb_updateState->clear();
    QMessageBox::information(this, "information", "OK");
}
