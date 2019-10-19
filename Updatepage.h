#ifndef UPDATEPAGE_H
#define UPDATEPAGE_H

#include <QWidget>
#include "IEEE14443/IEEE14443Control.h"
#include "ChannelMan/RFIDChannelMan.h"

namespace Ui {
class Updatepage;
}

class Updatepage : public QWidget
{
    Q_OBJECT

public:
    explicit Updatepage(QWidget *parent = 0);
    ~Updatepage();


private slots:
    void load();

    void on_updateback_clicked();

    void on_btn_dbselect_clicked();

    void on_pbn_addName_clicked();

    void on_pbn_start_clicked();
    void onNewCard(qlonglong decID);
    void on_search_error(int cmdType, const QString &result);// 用来处理寻卡失败
    void on_search_success(const QByteArray &cardid);// 用来处理寻卡成功
    void on_ted_showID(int block, const QByteArray &data);// 显示卡号

private:
    Ui::Updatepage *ui;
    IEEE14443Control *rfid;
};

#endif // UPDATEPAGE_H
