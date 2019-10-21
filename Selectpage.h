#ifndef SELECTPAGE_H
#define SELECTPAGE_H

#include <QWidget>
#include"IEEE14443/IEEE14443Control.h"
#include"ChannelMan/RFIDChannelMan.h"


namespace Ui {
class Selectpage;
}

class Selectpage : public QWidget
{
    Q_OBJECT

public:
    explicit Selectpage(QWidget *parent = 0);
    ~Selectpage();

private slots:
    void load();
    //定义槽函数，一个是寻卡失败的函数error(带2个参数，一个是失败类型，一个是失败返回的结果)
    void on_search_error(int cmdType, const QString &result);
    //定义槽函数，一个是寻卡成功的函数success(带1个参数，用来存储获取到的卡号)
    void on_ted_showID(int block, const QByteArray &data);// 显示卡号
    void onNewCard(qlonglong decID, const QByteArray &byteID);
    void on_search_success(const QByteArray &cardid);
    void on_sel_back_clicked();

    void on_btn_dbselect_clicked();

    void on_btn_dbrefresh_clicked();

    void on_pbn_search_clicked();

    void on_pbn_searchLog_clicked();
    void log_load(qlonglong card);

    void on_readcard_clicked();

private:
    Ui::Selectpage *ui;
    IEEE14443Control *rfid;
};

#endif // SELECTPAGE_H
