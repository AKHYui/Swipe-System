#include "Addpage.h"
#include "ui_Addpage.h"
#include "Maincontrol.h"
#include "ATSysDatabaseControl.h"

#include <QMessageBox>
#include "QFileDialog"
#include <QTableWidgetItem>

Addpage::Addpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Addpage)
{
    ui->setupUi(this);
    Addpage::setWindowTitle(QString("Add information"));
}

Addpage::~Addpage()
{
    delete ui;
}

//将数据库中信息显示在界面上
void Addpage::load()
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
void Addpage::on_pbn_back_clicked()
{
    Maincontrol *mcl = new Maincontrol;
    mcl->show();
    this->hide();
}

//按下登记所产生的效果
void Addpage::on_pbn_addName_clicked()
{
    if(ui->ted_showNumber->text().isEmpty() || ui->ted_showName->text().isEmpty())
    {
        QMessageBox::warning(this, "Warning", "no Empty");
        return;
    }
    //添加用户信息，默认正常
    ATSysDatabaseControl::add(ui->ted_showNumber->text().toLongLong(),
                              ui->ted_showName->text(),
                              ui->ted_showSex->currentText(),
                              "正常");
    load();
    ui->ted_showNumber->clear();
    ui->ted_showName->clear();
    ui->ted_showSex->clear();
    QMessageBox::information(this, "information", "OK");
}

//选择数据库按钮
void Addpage::on_btn_dbselect_clicked()
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
