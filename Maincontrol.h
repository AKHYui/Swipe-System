#ifndef MAINCONTROL_H
#define MAINCONTROL_H

#include <QWidget>
#include "Homepage.h"
#include "Addpage.h"
#include "Deletepage.h"
#include "Updatepage.h"
#include "Selectpage.h"
#include "Adminlogin.h"

namespace Ui {
class Maincontrol;
}

class Maincontrol : public QWidget
{
    Q_OBJECT

public:
    explicit Maincontrol(QWidget *parent = 0);
    ~Maincontrol();

private slots:
    void on_backhome_clicked();


    void on_AddCard_clicked();

    void on_DeleteCard_clicked();

    void on_UpdateCard_clicked();

    void on_back_clicked();

    void on_SelectCard_clicked();

    void on_AdminCard_clicked();

private:
    Ui::Maincontrol *ui;
    Homepage *hl;
    Addpage *al;
    Deletepage *dl;
    Updatepage *ul;
    Selectpage *sl;
    Adminlogin *an;
};

#endif // MAINCONTROL_H
