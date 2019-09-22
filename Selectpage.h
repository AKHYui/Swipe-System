#ifndef SELECTPAGE_H
#define SELECTPAGE_H

#include <QWidget>

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

    void on_sel_back_clicked();

    void on_btn_dbselect_clicked();

    void on_btn_dbrefresh_clicked();

private:
    Ui::Selectpage *ui;
};

#endif // SELECTPAGE_H
