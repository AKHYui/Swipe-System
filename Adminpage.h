#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QWidget>

namespace Ui {
class Adminpage;
}

class Adminpage : public QWidget
{
    Q_OBJECT

public:
    explicit Adminpage(QWidget *parent = 0);
    ~Adminpage();

private slots:
    void manageload();

    void on_pbn_back_clicked();

    void on_btn_dbselect_clicked();

    void on_btn_dbrefresh_clicked();

    void on_pbn_addName_clicked();

    void on_ptn_delete_clicked();

private:
    Ui::Adminpage *ui;
};

#endif // ADMINPAGE_H
