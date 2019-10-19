#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <QTimer>s
#include "ChannelMan/RFIDChannelMan.h"
#include "IEEE14443/IEEE14443Control.h"

namespace Ui {
class Homepage;
}

class Homepage : public QWidget
{
    Q_OBJECT

public:
    explicit Homepage(QWidget *parent = 0);
    ~Homepage();

private slots:
    void on_ctrl_clicked();
    void on_pushButton_2_clicked();
    void showTime();//显示时间
    void on_search_error(int cmdType, const QString &result);
    void on_search_success(const QByteArray &cardid);
    void on_show_data(int block, const QByteArray &data);
    void showTip(const QString &tip, bool valid);
    void hideTip();
    void onNewCard(qlonglong decID, const QByteArray &byteID);

private:
    Ui::Homepage *ui;
    IEEE14443Control *rfid;
    QTimer *timer1;
    QTimer *timer2;

};

#endif // HOMEPAGE_H
