#include "Adminpage.h"
#include "ui_Adminpage.h"
#include "Maincontrol.h"
#include "QFileDialog"
#include "ATSysDatabaseControl.h"
#include <QMessageBox>
#include <QTableWidgetItem>

Adminpage::Adminpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Adminpage)
{
    ui->setupUi(this);
    Adminpage::setWindowTitle(QString("Admin Permission!Power it!"));
}

Adminpage::~Adminpage()
{
    delete ui;
}

//加载管理员信息
void Adminpage::manageload()
{
    QList<manage_info> list = ATSysDatabaseControl::manageload();
    while(ui->db_table->rowCount() > 0)
        ui->db_table->removeRow(0);
    for(int i = 0; i < list.count(); i++)
    {
        const manage_info &info = list.at(i);
        ui->db_table->insertRow(i);
        ui->db_table->setItem(i, 0,
                              new QTableWidgetItem(info.id));
        ui->db_table->setItem(i, 1,
                              new QTableWidgetItem(QString::number(info.manageid)));
        ui->db_table->setItem(i, 2,
                              new QTableWidgetItem(info.name));
        ui->db_table->setItem(i, 3,
                              new QTableWidgetItem(info.sex));
        ui->db_table->setItem(i, 4,
                              new QTableWidgetItem(info.pwd));
        ui->db_table->setItem(i, 5,
                              new QTableWidgetItem(info.permission));
    }

}

//返回界面
void Adminpage::on_pbn_back_clicked()
{
    Maincontrol *mcl = new Maincontrol();
    mcl->show();
    this->hide();
}

//选择数据库
void Adminpage::on_btn_dbselect_clicked()
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
        manageload();
}

//刷新数据库
void Adminpage::on_btn_dbrefresh_clicked()
{
    manageload();
}


//添加管理员
void Adminpage::on_pbn_addName_clicked()
{
    if(ui->ted_showNumber->text().isEmpty() || ui->ted_showName->text().isEmpty() || ui->ted_showPassword->text().isEmpty())
    {
        QMessageBox::warning(this, "warning", "It's Empty");
        return;
    }
    //添加管理员信息
    ATSysDatabaseControl::manageadd(ui->ted_showNumber->text().toLongLong(),
                                    ui->ted_showName->text(),
                                    ui->ted_showSex->currentText(),
                                    ui->ted_showPassword->text(),
                                    "管理员");
    manageload();
    ui->ted_showNumber->clear();
    ui->ted_showName->clear();
    ui->ted_showPassword->clear();
    ui->ted_showSex->currentIndex();
    QMessageBox::information(this, "information", "OK");
}

//删除管理员
void Adminpage::on_ptn_delete_clicked()
{
    if(ui->ted_showNumber->text().isEmpty())
    {
        QMessageBox::warning(this, "warning", "It's Empty");
        return;
    }
    //删除管理员信息
    ATSysDatabaseControl::manageremove(ui->ted_showNumber->text().toLongLong());
    manageload();
    ui->ted_showName->clear();
    ui->ted_showPassword->clear();
    ui->ted_showSex->currentIndex();
    QMessageBox::information(this, "information", "OK");
}
