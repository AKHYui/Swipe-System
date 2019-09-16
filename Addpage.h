#ifndef ADDPAGE_H
#define ADDPAGE_H

#include <QWidget>


namespace Ui {
class Addpage;
}

class Addpage : public QWidget
{
    Q_OBJECT

public:
    explicit Addpage(QWidget *parent = 0);
    ~Addpage();


private slots:
    void on_pbn_back_clicked();

    void on_pbn_addName_clicked();

    void on_btn_dbselect_clicked();

private:
    Ui::Addpage *ui;
};

#endif // ADDPAGE_H
