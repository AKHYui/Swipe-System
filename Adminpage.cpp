#include "Adminpage.h"
#include "ui_Adminpage.h"
#include "Maincontrol.h"
#include "QFileDialog"
#include "ATSysDatabaseControl.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDebug>

Adminpage::Adminpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Adminpage)
{
    ui->setupUi(this);
    Adminpage::setWindowTitle(QString("Admin Permission!Power it!"));

    // 选择13.56M读写器
    RFIDChannelMan::setChannel(RFIDChannelMan::ChannelIEEE14443);
    // 创建13.56M读写器操作类对象
    rfid = new IEEE14443Control(this);
    // 连接出错、寻卡成功以及读卡成功的信号
    connect(rfid, SIGNAL(error(int,QString)),
            this, SLOT(on_search_error(int,QString)));
    connect(rfid, SIGNAL(foundCard(QByteArray)),
            this, SLOT(on_search_success(QByteArray)));
    connect(rfid, SIGNAL(dataReaded(int,QByteArray)),
            this, SLOT(on_ted_showID(int,QByteArray)));

// rfid->start(RFIDChannelMan::getRfidPort());
    //rfid->start("COM4");

    rfid->start("/dev/ttyUSB0");
}

Adminpage::~Adminpage()
{
    delete ui;
}

//加载管理员信息
void Adminpage::load()
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
    rfid->stop();
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
        load();
}

//刷新数据库
void Adminpage::on_btn_dbrefresh_clicked()
{
    load();
}


//添加管理员
void Adminpage::on_pbn_addName_clicked()
{
    QString uname;
    qlonglong manid;
    uname =ui->ted_showName->text();
    manid =ui->ted_showNumber->text().toLongLong();
    manage_info info = ATSysDatabaseControl::manageload(uname);
     manage_info info1 = ATSysDatabaseControl::manageload(manid);
    if(ui->ted_showNumber->text().isEmpty() ||ui->ted_showPassword->text().isEmpty())
    {
        QMessageBox::warning(this, "警告", "卡号或密码不能为空");
        return;
     }
        //如果数据表中该姓名已经存在，则无法注册
    else if(uname == info.name )
        {
            QMessageBox::warning(this, "警告", "该姓名已注册");
            ui->ted_showName->clear();
            return;
        }
    else if(manid == info1.manageid)
        {
            QMessageBox::warning(this, "警告", "该卡号已注册");
            ui->ted_showNumber->clear();
            return;
        }

    else if( ui->ted_showName->text().isEmpty())
      {
        QMessageBox::warning(this, "警告", "姓名不能为空");
        return;
    }

    //添加管理员信息的时候，权限默认为1（普通管理员）
    ATSysDatabaseControl::manageadd(ui->ted_showNumber->text().toLongLong(),
                                    ui->ted_showName->text(),
                                    ui->ted_showSex->currentText(),
                                    ui->ted_showPassword->text(),
                                    "管理员" );
     load();
    ui->ted_showNumber->clear();
    ui->ted_showName->clear();
    ui->ted_showSex->currentIndex();
    ui->ted_showPassword->clear();

    QMessageBox::information(this, "提示", "注册完成");
}

//删除管理员
void Adminpage::on_ptn_delete_clicked()
{
    QList<QTableWidgetItem *> sel = ui->db_table->selectedItems();
    if(sel.isEmpty())
    {
        QMessageBox::warning(this, "警告", "没有选择任何信息");
        return;
    }
    int row = sel[0]->row();
    qlonglong manageid = ui->db_table->item(row, 1)->text().toLongLong();
    ATSysDatabaseControl::manageremove(manageid);
    ui->db_table->removeRow(row);
    load();
}


/*---------------------------13.56M读卡-----------------*/
/**
 * @brief onNewCard
 * 获取到ID卡时执行的槽函数
 *
 * @param decID 由newCard()信号传递过来的卡号
 * @param byteID 由newCard()信号传递过来的卡号
 */
void Adminpage::onNewCard(unsigned long decID)
{
    QList<QTableWidgetItem*> lists =
            ui->db_table->findItems(QString::number(decID), Qt::MatchExactly);
    if(lists.isEmpty())
    {
        return;
    }
    else
    {
        ui->db_table->selectRow(lists.at(0)->row());
        QList<QTableWidgetItem*> items = ui->db_table->selectedItems();//获取选中的行信息
        ui->ted_showNumber->setText(items.at(1)->text());
        ui->ted_showName->setText(items.at(2)->text());
        ui->ted_showPassword->setText(items.at(4)->text());
//        ui->ted_showSex->setText(items.at(3)->text());

    }
}

//------------------------13.56M读卡-----------------------//
//槽函数，获取卡号失败的函数
void Adminpage::on_search_error(int cmdType, const QString &result)
{

    if(cmdType == IEEE14443Control::GetCardId)
//        rfid->getCardId();
       QMessageBox::information(this, "提示", "读卡错误！");
}
void Adminpage::on_search_success(const QByteArray &cardid)
{

    qlonglong decID;
    bool ok;

    qDebug()<<"==[on_search_success]==get cardID:"<<cardid.toHex();
    decID = cardid.toHex().toLongLong(&ok,16);

    qDebug()<<"====get cardID:"<<QString::number(decID);
    // 读卡过程中获得卡号，显示卡号
    ui->ted_showNumber->setText(QString::number(decID));
    onNewCard(decID);

}

//读卡完成，显示读取到到数据
void Adminpage::on_ted_showID(int block, const QByteArray &data)
{
  QMessageBox::information(this, "提示", data.toHex());

}

void Adminpage::on_pbn_start_clicked()
{
    // 点击按钮时，启动寻卡操作
    rfid->getCardId();
}
