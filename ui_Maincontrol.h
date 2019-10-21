/********************************************************************************
** Form generated from reading UI file 'Maincontrol.ui'
**
** Created: Mon Oct 21 17:15:18 2019
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCONTROL_H
#define UI_MAINCONTROL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Maincontrol
{
public:
    QWidget *widget;
    QPushButton *backhome;
    QPushButton *DeleteCard;
    QPushButton *AddCard;
    QPushButton *SelectCard;
    QPushButton *UpdateCard;
    QPushButton *AdminCard;
    QPushButton *back;

    void setupUi(QWidget *Maincontrol)
    {
        if (Maincontrol->objectName().isEmpty())
            Maincontrol->setObjectName(QString::fromUtf8("Maincontrol"));
        Maincontrol->resize(750, 468);
        Maincontrol->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(Maincontrol);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 751, 471));
        widget->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/main.png);"));
        backhome = new QPushButton(widget);
        backhome->setObjectName(QString::fromUtf8("backhome"));
        backhome->setGeometry(QRect(20, 80, 91, 61));
        DeleteCard = new QPushButton(widget);
        DeleteCard->setObjectName(QString::fromUtf8("DeleteCard"));
        DeleteCard->setGeometry(QRect(230, 270, 101, 71));
        AddCard = new QPushButton(widget);
        AddCard->setObjectName(QString::fromUtf8("AddCard"));
        AddCard->setGeometry(QRect(120, 270, 101, 71));
        SelectCard = new QPushButton(widget);
        SelectCard->setObjectName(QString::fromUtf8("SelectCard"));
        SelectCard->setGeometry(QRect(440, 270, 91, 71));
        UpdateCard = new QPushButton(widget);
        UpdateCard->setObjectName(QString::fromUtf8("UpdateCard"));
        UpdateCard->setGeometry(QRect(340, 270, 91, 71));
        AdminCard = new QPushButton(widget);
        AdminCard->setObjectName(QString::fromUtf8("AdminCard"));
        AdminCard->setGeometry(QRect(540, 270, 91, 71));
        back = new QPushButton(widget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 40, 91, 31));
        back->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(Maincontrol);

        QMetaObject::connectSlotsByName(Maincontrol);
    } // setupUi

    void retranslateUi(QWidget *Maincontrol)
    {
        Maincontrol->setWindowTitle(QApplication::translate("Maincontrol", "Form", 0, QApplication::UnicodeUTF8));
        backhome->setText(QApplication::translate("Maincontrol", "\351\246\226\351\241\265", 0, QApplication::UnicodeUTF8));
        DeleteCard->setText(QApplication::translate("Maincontrol", "\345\210\240\351\231\244\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        AddCard->setText(QApplication::translate("Maincontrol", "\346\267\273\345\212\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        SelectCard->setText(QApplication::translate("Maincontrol", "\346\237\245\350\257\242\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        UpdateCard->setText(QApplication::translate("Maincontrol", "\344\277\256\346\224\271\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        AdminCard->setText(QApplication::translate("Maincontrol", "\347\256\241\347\220\206\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        back->setText(QApplication::translate("Maincontrol", "\347\231\273\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Maincontrol: public Ui_Maincontrol {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCONTROL_H
