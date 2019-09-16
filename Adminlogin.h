#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QWidget>
#include "Adminpage.h"

namespace Ui {
class Adminlogin;
}

class Adminlogin : public QWidget
{
    Q_OBJECT

public:
    explicit Adminlogin(QWidget *parent = 0);
    ~Adminlogin();

private slots:
    void on_alogback_clicked();

    void on_ptn_reset_clicked();

    void on_ptn_login_clicked();

private:
    Ui::Adminlogin *ui;
    Adminpage ae;
};

#endif // ADMINLOGIN_H
