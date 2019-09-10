/********************************************************************************
** Form generated from reading UI file 'Updatepage.ui'
**
** Created: Tue Sep 10 22:16:44 2019
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEPAGE_H
#define UI_UPDATEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Updatepage
{
public:
    QPushButton *updateback;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *db_select;
    QLabel *lb_db;
    QLineEdit *ted_dbpath;
    QPushButton *btn_dbselect;
    QPushButton *btn_dbrefresh;
    QTableWidget *db_table;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout;
    QPushButton *pbn_start;
    QLabel *lb_cardID;
    QPushButton *pbn_addName;
    QLineEdit *ted_showNumber;
    QLabel *lb_cardName;
    QLineEdit *ted_showName;
    QLabel *lb_cardSex;
    QComboBox *ted_showSex;
    QLabel *label_2;
    QComboBox *cb_updateState;

    void setupUi(QWidget *Updatepage)
    {
        if (Updatepage->objectName().isEmpty())
            Updatepage->setObjectName(QString::fromUtf8("Updatepage"));
        Updatepage->resize(696, 421);
        updateback = new QPushButton(Updatepage);
        updateback->setObjectName(QString::fromUtf8("updateback"));
        updateback->setGeometry(QRect(10, 10, 93, 28));
        label = new QLabel(Updatepage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 0, 161, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        label->setFont(font);
        layoutWidget = new QWidget(Updatepage);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 60, 631, 30));
        db_select = new QHBoxLayout(layoutWidget);
        db_select->setObjectName(QString::fromUtf8("db_select"));
        db_select->setContentsMargins(0, 0, 0, 0);
        lb_db = new QLabel(layoutWidget);
        lb_db->setObjectName(QString::fromUtf8("lb_db"));

        db_select->addWidget(lb_db);

        ted_dbpath = new QLineEdit(layoutWidget);
        ted_dbpath->setObjectName(QString::fromUtf8("ted_dbpath"));
        ted_dbpath->setReadOnly(true);

        db_select->addWidget(ted_dbpath);

        btn_dbselect = new QPushButton(layoutWidget);
        btn_dbselect->setObjectName(QString::fromUtf8("btn_dbselect"));

        db_select->addWidget(btn_dbselect);

        btn_dbrefresh = new QPushButton(layoutWidget);
        btn_dbrefresh->setObjectName(QString::fromUtf8("btn_dbrefresh"));

        db_select->addWidget(btn_dbrefresh);

        db_table = new QTableWidget(Updatepage);
        if (db_table->columnCount() < 4)
            db_table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        db_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        db_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        db_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        db_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        db_table->setObjectName(QString::fromUtf8("db_table"));
        db_table->setGeometry(QRect(50, 110, 631, 161));
        db_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        db_table->setSelectionMode(QAbstractItemView::SingleSelection);
        db_table->setSelectionBehavior(QAbstractItemView::SelectRows);
        layoutWidget_2 = new QWidget(Updatepage);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(50, 290, 631, 101));
        gridLayout = new QGridLayout(layoutWidget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pbn_start = new QPushButton(layoutWidget_2);
        pbn_start->setObjectName(QString::fromUtf8("pbn_start"));

        gridLayout->addWidget(pbn_start, 0, 0, 1, 1);

        lb_cardID = new QLabel(layoutWidget_2);
        lb_cardID->setObjectName(QString::fromUtf8("lb_cardID"));

        gridLayout->addWidget(lb_cardID, 0, 1, 1, 1);

        pbn_addName = new QPushButton(layoutWidget_2);
        pbn_addName->setObjectName(QString::fromUtf8("pbn_addName"));

        gridLayout->addWidget(pbn_addName, 1, 0, 1, 1);

        ted_showNumber = new QLineEdit(layoutWidget_2);
        ted_showNumber->setObjectName(QString::fromUtf8("ted_showNumber"));
        ted_showNumber->setEnabled(false);

        gridLayout->addWidget(ted_showNumber, 0, 2, 1, 1);

        lb_cardName = new QLabel(layoutWidget_2);
        lb_cardName->setObjectName(QString::fromUtf8("lb_cardName"));

        gridLayout->addWidget(lb_cardName, 0, 3, 1, 1);

        ted_showName = new QLineEdit(layoutWidget_2);
        ted_showName->setObjectName(QString::fromUtf8("ted_showName"));

        gridLayout->addWidget(ted_showName, 0, 4, 1, 1);

        lb_cardSex = new QLabel(layoutWidget_2);
        lb_cardSex->setObjectName(QString::fromUtf8("lb_cardSex"));

        gridLayout->addWidget(lb_cardSex, 1, 1, 1, 1);

        ted_showSex = new QComboBox(layoutWidget_2);
        ted_showSex->setObjectName(QString::fromUtf8("ted_showSex"));
        ted_showSex->setMinimumSize(QSize(140, 0));

        gridLayout->addWidget(ted_showSex, 1, 2, 1, 1);

        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("ADMUI3Lg"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 1, 3, 1, 1);

        cb_updateState = new QComboBox(layoutWidget_2);
        cb_updateState->setObjectName(QString::fromUtf8("cb_updateState"));
        cb_updateState->setMinimumSize(QSize(175, 25));

        gridLayout->addWidget(cb_updateState, 1, 4, 1, 1);


        retranslateUi(Updatepage);

        QMetaObject::connectSlotsByName(Updatepage);
    } // setupUi

    void retranslateUi(QWidget *Updatepage)
    {
        Updatepage->setWindowTitle(QApplication::translate("Updatepage", "Form", 0, QApplication::UnicodeUTF8));
        updateback->setText(QApplication::translate("Updatepage", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Updatepage", "\347\274\226\350\276\221\344\277\241\346\201\257\345\271\263\345\217\260", 0, QApplication::UnicodeUTF8));
        lb_db->setText(QApplication::translate("Updatepage", "<html><head/><body><p align=\"right\"><span style=\" font-size:10pt; font-weight:600;\">\346\225\260\346\215\256\345\272\223</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        btn_dbselect->setText(QApplication::translate("Updatepage", "\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        btn_dbrefresh->setText(QApplication::translate("Updatepage", "\345\210\267\346\226\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = db_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Updatepage", "\345\215\241\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = db_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Updatepage", "\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = db_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Updatepage", "\346\200\247\345\210\253", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = db_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Updatepage", "\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        pbn_start->setText(QApplication::translate("Updatepage", "\350\257\273\345\215\241", 0, QApplication::UnicodeUTF8));
        lb_cardID->setText(QApplication::translate("Updatepage", "<html><head/><body><p align=\"right\"><span style=\" font-size:10pt; font-weight:600;\">  \345\215\241\345\217\267\357\274\232</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pbn_addName->setText(QApplication::translate("Updatepage", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        lb_cardName->setText(QApplication::translate("Updatepage", "<html><head/><body><p align=\"right\"><span style=\" font-size:10pt; font-weight:600;\">     \345\247\223\345\220\215\357\274\232</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        lb_cardSex->setText(QApplication::translate("Updatepage", "<html><head/><body><p align=\"right\"><span style=\" font-size:10pt; font-weight:600;\">      \346\200\247\345\210\253\357\274\232</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        ted_showSex->clear();
        ted_showSex->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("Updatepage", "\347\224\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Updatepage", "\345\245\263", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("Updatepage", "\347\212\266\346\200\201\357\274\232", 0, QApplication::UnicodeUTF8));
        cb_updateState->clear();
        cb_updateState->insertItems(0, QStringList()
         << QApplication::translate("Updatepage", "\346\255\243\345\270\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Updatepage", "\345\267\262\346\263\250\351\224\200", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class Updatepage: public Ui_Updatepage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEPAGE_H
