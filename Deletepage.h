#ifndef DELETEPAGE_H
#define DELETEPAGE_H

#include <QWidget>
#include "ChannelMan/RFIDChannelMan.h"
#include "IEEE14443/IEEE14443Control.h"

namespace Ui {
class Deletepage;
}

class Deletepage : public QWidget
{
    Q_OBJECT

public:
    explicit Deletepage(QWidget *parent = 0);
    ~Deletepage();


private slots:
    void load();
    void onNewCard(qlonglong decID);
    void on_delback_clicked();


    void on_btn_dbselect_clicked();


    void on_ptn_delete_clicked();

    void on_ptn_release_clicked();
    void on_search_error(int cmdType, const QString &result);// 用来处理寻卡失败
    void on_search_success(const QByteArray &cardid);// 用来处理寻卡成功
    void on_ted_showID(int block, const QByteArray &data);// 显示卡号

    void on_pushButton_4_clicked();

private:
    Ui::Deletepage *ui;
    IEEE14443Control *rfid;
};

#endif // DELETEPAGE_H
