/********************************************************************************
** Form generated from reading UI file 'Homepage.ui'
**
** Created: Sat Oct 19 15:36:32 2019
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Homepage
{
public:
    QWidget *widget;
    QPushButton *pushButton_2;
    QPushButton *ctrl;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_show;
    QLabel *lb_red;
    QSpacerItem *horizontalSpacer_5;
    QLabel *lb_tip;
    QSpacerItem *horizontalSpacer_6;
    QLabel *lb_green;
    QLCDNumber *lcdNumber;
    QLabel *date;

    void setupUi(QWidget *Homepage)
    {
        if (Homepage->objectName().isEmpty())
            Homepage->setObjectName(QString::fromUtf8("Homepage"));
        Homepage->resize(692, 453);
        widget = new QWidget(Homepage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 691, 461));
        widget->setStyleSheet(QString::fromUtf8("#widget{image: url(:/new/prefix1/img/home.png);}"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 50, 91, 71));
        ctrl = new QPushButton(widget);
        ctrl->setObjectName(QString::fromUtf8("ctrl"));
        ctrl->setGeometry(QRect(10, 10, 91, 31));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 340, 571, 62));
        horizontalLayout_show = new QHBoxLayout(layoutWidget);
        horizontalLayout_show->setObjectName(QString::fromUtf8("horizontalLayout_show"));
        horizontalLayout_show->setContentsMargins(0, 0, 0, 0);
        lb_red = new QLabel(layoutWidget);
        lb_red->setObjectName(QString::fromUtf8("lb_red"));
        lb_red->setMinimumSize(QSize(60, 60));
        lb_red->setMaximumSize(QSize(60, 60));
        lb_red->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"border-radius: 30px;"));

        horizontalLayout_show->addWidget(lb_red);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_show->addItem(horizontalSpacer_5);

        lb_tip = new QLabel(layoutWidget);
        lb_tip->setObjectName(QString::fromUtf8("lb_tip"));
        lb_tip->setMinimumSize(QSize(0, 0));
        lb_tip->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(30);
        lb_tip->setFont(font);

        horizontalLayout_show->addWidget(lb_tip);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_show->addItem(horizontalSpacer_6);

        lb_green = new QLabel(layoutWidget);
        lb_green->setObjectName(QString::fromUtf8("lb_green"));
        lb_green->setMinimumSize(QSize(60, 60));
        lb_green->setMaximumSize(QSize(60, 60));
        lb_green->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"border-radius: 30px;"));

        horizontalLayout_show->addWidget(lb_green);

        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(50, 200, 621, 101));
        date = new QLabel(widget);
        date->setObjectName(QString::fromUtf8("date"));
        date->setGeometry(QRect(170, 130, 421, 41));
        date->setStyleSheet(QString::fromUtf8("font: 75 24pt \"\346\226\260\345\256\213\344\275\223\";"));

        retranslateUi(Homepage);

        QMetaObject::connectSlotsByName(Homepage);
    } // setupUi

    void retranslateUi(QWidget *Homepage)
    {
        Homepage->setWindowTitle(QApplication::translate("Homepage", "Form", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Homepage", "\346\211\223\345\215\241", 0, QApplication::UnicodeUTF8));
        ctrl->setText(QApplication::translate("Homepage", "\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        lb_tip->setText(QApplication::translate("Homepage", "TextLabel", 0, QApplication::UnicodeUTF8));
        date->setText(QApplication::translate("Homepage", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Homepage: public Ui_Homepage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
