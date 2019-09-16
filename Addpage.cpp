#include "Addpage.h"
#include "ui_Addpage.h"
#include "Maincontrol.h"
#include "ATSysDatabaseControl.h"

#include <QMessageBox>
#include "QFileDialog"

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
}
