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
    void on_sel_back_clicked();

private:
    Ui::Selectpage *ui;
};

#endif // SELECTPAGE_H
