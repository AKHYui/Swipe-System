/********************************************************************************
** Form generated from reading UI file 'Adminpage.ui'
**
** Created: Mon Oct 21 17:15:18 2019
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPAGE_H
#define UI_ADMINPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Adminpage
{
public:
    QWidget *widget;
    QWidget *layoutWidget;
    QHBoxLayout *Function;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pbn_addName;
    QSpacerItem *horizontalSpacer;
    QPushButton *ptn_delete;
    QSpacerItem *horizontalSpacer_3;
    QWidget *layoutWidget_2;
    QHBoxLayout *db_select;
    QLabel *lb_db;
    QLineEdit *ted_dbpath;
    QPushButton *btn_dbselect;
    QPushButton *btn_dbrefresh;
    QTableWidget *db_table;
    QSplitter *splitter;
    QPushButton *pbn_start;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout;
    QLabel *lb_cardID;
    QLineEdit *ted_showNumber;
    QLabel *lb_cardName;
    QLineEdit *ted_showName;
    QWidget *layoutWidget_4;
    QFormLayout *formLayout;
    QLabel *lb_cardID_2;
    QLineEdit *ted_showPassword;
    QLabel *lb_cardSex;
    QComboBox *ted_showSex;
    QPushButton *pbn_back;
    QLabel *label;

    void setupUi(QWidget *Adminpage)
    {
        if (Adminpage->objectName().isEmpty())
            Adminpage->setObjectName(QString::fromUtf8("Adminpage"));
        Adminpage->resize(735, 508);
        widget = new QWidget(Adminpage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 741, 511));
        widget->setStyleSheet(QString::fromUtf8("#widget{background-image: url(:/new/prefix1/img/addpage.png);}"));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 370, 661, 30));
        Function = new QHBoxLayout(layoutWidget);
        Function->setObjectName(QString::fromUtf8("Function"));
        Function->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Function->addItem(horizontalSpacer_2);

        pbn_addName = new QPushButton(layoutWidget);
        pbn_addName->setObjectName(QString::fromUtf8("pbn_addName"));

        Function->addWidget(pbn_addName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Function->addItem(horizontalSpacer);

        ptn_delete = new QPushButton(layoutWidget);
        ptn_delete->setObjectName(QString::fromUtf8("ptn_delete"));

        Function->addWidget(ptn_delete);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Function->addItem(horizontalSpacer_3);

        layoutWidget_2 = new QWidget(widget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(40, 100, 651, 30));
        db_select = new QHBoxLayout(layoutWidget_2);
        db_select->setObjectName(QString::fromUtf8("db_select"));
        db_select->setContentsMargins(0, 0, 0, 0);
        lb_db = new QLabel(layoutWidget_2);
        lb_db->setObjectName(QString::fromUtf8("lb_db"));

        db_select->addWidget(lb_db);

        ted_dbpath = new QLineEdit(layoutWidget_2);
        ted_dbpath->setObjectName(QString::fromUtf8("ted_dbpath"));
        ted_dbpath->setMinimumSize(QSize(0, 25));
        ted_dbpath->setReadOnly(true);

        db_select->addWidget(ted_dbpath);

        btn_dbselect = new QPushButton(layoutWidget_2);
        btn_dbselect->setObjectName(QString::fromUtf8("btn_dbselect"));

        db_select->addWidget(btn_dbselect);

        btn_dbrefresh = new QPushButton(layoutWidget_2);
        btn_dbrefresh->setObjectName(QString::fromUtf8("btn_dbrefresh"));

        db_select->addWidget(btn_dbrefresh);

        db_table = new QTableWidget(widget);
        if (db_table->columnCount() < 6)
            db_table->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        db_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        db_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        db_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        db_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        db_table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        db_table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        db_table->setObjectName(QString::fromUtf8("db_table"));
        db_table->setGeometry(QRect(40, 140, 651, 161));
        db_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        db_table->setSelectionMode(QAbstractItemView::SingleSelection);
        db_table->setSelectionBehavior(QAbstractItemView::SelectRows);
        splitter = new QSplitter(widget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(40, 300, 651, 61));
        splitter->setOrientation(Qt::Horizontal);
        pbn_start = new QPushButton(splitter);
        pbn_start->setObjectName(QString::fromUtf8("pbn_start"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        pbn_start->setFont(font);
        splitter->addWidget(pbn_start);
        layoutWidget_3 = new QWidget(splitter);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        gridLayout = new QGridLayout(layoutWidget_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lb_cardID = new QLabel(layoutWidget_3);
        lb_cardID->setObjectName(QString::fromUtf8("lb_cardID"));
        lb_cardID->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(lb_cardID, 0, 0, 1, 1);

        ted_showNumber = new QLineEdit(layoutWidget_3);
        ted_showNumber->setObjectName(QString::fromUtf8("ted_showNumber"));
        ted_showNumber->setEnabled(true);
        ted_showNumber->setMinimumSize(QSize(150, 25));

        gridLayout->addWidget(ted_showNumber, 0, 1, 1, 2);

        lb_cardName = new QLabel(layoutWidget_3);
        lb_cardName->setObjectName(QString::fromUtf8("lb_cardName"));
        lb_cardName->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(lb_cardName, 1, 0, 1, 1);

        ted_showName = new QLineEdit(layoutWidget_3);
        ted_showName->setObjectName(QString::fromUtf8("ted_showName"));
        ted_showName->setMinimumSize(QSize(150, 25));

        gridLayout->addWidget(ted_showName, 1, 1, 1, 2);

        splitter->addWidget(layoutWidget_3);
        layoutWidget_4 = new QWidget(splitter);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        formLayout = new QFormLayout(layoutWidget_4);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        lb_cardID_2 = new QLabel(layoutWidget_4);
        lb_cardID_2->setObjectName(QString::fromUtf8("lb_cardID_2"));
        lb_cardID_2->setMinimumSize(QSize(0, 25));

        formLayout->setWidget(0, QFormLayout::LabelRole, lb_cardID_2);

        ted_showPassword = new QLineEdit(layoutWidget_4);
        ted_showPassword->setObjectName(QString::fromUtf8("ted_showPassword"));
        ted_showPassword->setMinimumSize(QSize(150, 25));

        formLayout->setWidget(0, QFormLayout::FieldRole, ted_showPassword);

        lb_cardSex = new QLabel(layoutWidget_4);
        lb_cardSex->setObjectName(QString::fromUtf8("lb_cardSex"));
        lb_cardSex->setMinimumSize(QSize(0, 25));

        formLayout->setWidget(1, QFormLayout::LabelRole, lb_cardSex);

        ted_showSex = new QComboBox(layoutWidget_4);
        ted_showSex->setObjectName(QString::fromUtf8("ted_showSex"));
        ted_showSex->setMinimumSize(QSize(150, 25));

        formLayout->setWidget(1, QFormLayout::FieldRole, ted_showSex);

        splitter->addWidget(layoutWidget_4);
        pbn_back = new QPushButton(widget);
        pbn_back->setObjectName(QString::fromUtf8("pbn_back"));
        pbn_back->setGeometry(QRect(10, 40, 93, 28));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 40, 381, 51));

        retranslateUi(Adminpage);

        QMetaObject::connectSlotsByName(Adminpage);
    } // setupUi

    void retranslateUi(QWidget *Adminpage)
    {
        Adminpage->setWindowTitle(QApplication::translate("Adminpage", "Form", 0, QApplication::UnicodeUTF8));
        pbn_addName->setText(QApplication::translate("Adminpage", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        ptn_delete->setText(QApplication::translate("Adminpage", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        lb_db->setText(QApplication::translate("Adminpage", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">\346\225\260\346\215\256\345\272\223</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        btn_dbselect->setText(QApplication::translate("Adminpage", "\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        btn_dbrefresh->setText(QApplication::translate("Adminpage", "\345\210\267\346\226\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = db_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Adminpage", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = db_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Adminpage", "\345\215\241\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = db_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Adminpage", "\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = db_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Adminpage", "\346\200\247\345\210\253", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = db_table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Adminpage", "\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = db_table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Adminpage", "\346\235\203\351\231\220", 0, QApplication::UnicodeUTF8));
        pbn_start->setText(QApplication::translate("Adminpage", "\350\257\273\345\215\241", 0, QApplication::UnicodeUTF8));
        lb_cardID->setText(QApplication::translate("Adminpage", "<html><head/><body><p align=\"right\"><span style=\" font-size:10pt; font-weight:600;\">\345\215\241\345\217\267\357\274\232</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        lb_cardName->setText(QApplication::translate("Adminpage", "<html><head/><body><p align=\"right\"><span style=\" font-size:10pt; font-weight:600;\">\345\247\223\345\220\215\357\274\232</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        lb_cardID_2->setText(QApplication::translate("Adminpage", "<html><head/><body><p align=\"right\"><span style=\" font-size:10pt; font-weight:600;\">  \345\257\206\347\240\201\357\274\232</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        ted_showPassword->setText(QString());
        lb_cardSex->setText(QApplication::translate("Adminpage", "<html><head/><body><p align=\"right\"><span style=\" font-size:10pt; font-weight:600;\">       \346\200\247\345\210\253\357\274\232</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        ted_showSex->clear();
        ted_showSex->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("Adminpage", "\347\224\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Adminpage", "\345\245\263", 0, QApplication::UnicodeUTF8)
        );
        pbn_back->setText(QApplication::translate("Adminpage", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Adminpage", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:600;\">\350\200\203\345\213\244\347\263\273\347\273\237\347\256\241\347\220\206\345\221\230\347\256\241\347\220\206\345\271\263\345\217\260</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Adminpage: public Ui_Adminpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPAGE_H
