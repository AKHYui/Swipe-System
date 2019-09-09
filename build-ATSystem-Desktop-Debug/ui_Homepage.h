/********************************************************************************
** Form generated from reading UI file 'Homepage.ui'
**
** Created: Mon Sep 9 19:07:21 2019
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
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Homepage
{
public:
    QPushButton *ctrl;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Homepage)
    {
        if (Homepage->objectName().isEmpty())
            Homepage->setObjectName(QString::fromUtf8("Homepage"));
        Homepage->resize(702, 497);
        ctrl = new QPushButton(Homepage);
        ctrl->setObjectName(QString::fromUtf8("ctrl"));
        ctrl->setGeometry(QRect(40, 40, 111, 71));
        pushButton_2 = new QPushButton(Homepage);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(50, 260, 151, 81));

        retranslateUi(Homepage);

        QMetaObject::connectSlotsByName(Homepage);
    } // setupUi

    void retranslateUi(QWidget *Homepage)
    {
        Homepage->setWindowTitle(QApplication::translate("Homepage", "Form", 0, QApplication::UnicodeUTF8));
        ctrl->setText(QApplication::translate("Homepage", "\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Homepage", "\346\211\223\345\215\241", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Homepage: public Ui_Homepage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
