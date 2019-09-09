#ifndef DELETEPAGE_H
#define DELETEPAGE_H

#include <QWidget>

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
    void on_delback_clicked();

private:
    Ui::Deletepage *ui;
};

#endif // DELETEPAGE_H
