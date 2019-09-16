#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "Maincontrol.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_pushButton_2_clicked();

    void on_login_clicked();

private:
    Ui::Login *ui;
    Maincontrol ml;
};

#endif // LOGIN_H
