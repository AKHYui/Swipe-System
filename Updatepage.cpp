#include "Updatepage.h"
#include "ui_Updatepage.h"
#include "Maincontrol.h"
#include "ATSysDatabaseControl.h"
#include "QMessageBox"
#include "QFileDialog"
#include "QTableWidgetItem"

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

//将数据库中信息显示在界面上
void Updatepage::load()
{
    QList<employee_info> list = ATSysDatabaseControl::load();
    while(ui->db_table->rowCount() > 0)
        ui->db_table->removeRow(0);
    for(int i = 0; i < list.count(); i++)
    {
        const employee_info &info = list.at(i);
        ui->db_table->insertRow(i);
        ui->db_table->setItem(i, 0,
                              new QTableWidgetItem(QString::number(info.card))
                              );
        ui->db_table->setItem(i, 1,
                              new QTableWidgetItem(info.name));
        ui->db_table->setItem(i, 2,
                              new QTableWidgetItem(info.sex));
        ui->db_table->setItem(i, 3,
                              new QTableWidgetItem(info.state));
    }
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
        load();
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
    load();
    QMessageBox::information(this, "information", "OK");
}
