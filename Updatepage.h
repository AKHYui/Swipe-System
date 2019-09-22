#ifndef UPDATEPAGE_H
#define UPDATEPAGE_H

#include <QWidget>

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

private:
    Ui::Updatepage *ui;
};

#endif // UPDATEPAGE_H
