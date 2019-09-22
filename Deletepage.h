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
    void load();

    void on_delback_clicked();


    void on_btn_dbselect_clicked();


    void on_ptn_delete_clicked();

    void on_ptn_release_clicked();

private:
    Ui::Deletepage *ui;
};

#endif // DELETEPAGE_H
