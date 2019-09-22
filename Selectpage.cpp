#include "Selectpage.h"
#include "ui_Selectpage.h"
#include "Maincontrol.h"
#include "QFileDialog"
#include "ATSysDatabaseControl.h"
#include "QMessageBox"
#include "QTableWidgetItem"

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

//将数据库中信息显示在界面上
void Selectpage::load()
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
        load();
}

//刷新
void Selectpage::on_btn_dbrefresh_clicked()
{
    load();
}
