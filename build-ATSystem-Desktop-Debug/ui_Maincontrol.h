/********************************************************************************
** Form generated from reading UI file 'Maincontrol.ui'
**
** Created: Tue Sep 10 22:26:22 2019
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
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Maincontrol
{
public:
    QLabel *label;
    QPushButton *AddCard;
    QPushButton *DeleteCard;
    QPushButton *UpdateCard;
    QPushButton *SelectCard;
    QPushButton *AdminCard;
    QPushButton *backhome;
    QPushButton *back;

    void setupUi(QWidget *Maincontrol)
    {
        if (Maincontrol->objectName().isEmpty())
            Maincontrol->setObjectName(QString::fromUtf8("Maincontrol"));
        Maincontrol->resize(750, 468);
        Maincontrol->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(Maincontrol);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 140, 181, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("ADMUI3Lg"));
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        AddCard = new QPushButton(Maincontrol);
        AddCard->setObjectName(QString::fromUtf8("AddCard"));
        AddCard->setGeometry(QRect(130, 290, 101, 71));
        DeleteCard = new QPushButton(Maincontrol);
        DeleteCard->setObjectName(QString::fromUtf8("DeleteCard"));
        DeleteCard->setGeometry(QRect(240, 290, 101, 71));
        UpdateCard = new QPushButton(Maincontrol);
        UpdateCard->setObjectName(QString::fromUtf8("UpdateCard"));
        UpdateCard->setGeometry(QRect(350, 290, 91, 71));
        SelectCard = new QPushButton(Maincontrol);
        SelectCard->setObjectName(QString::fromUtf8("SelectCard"));
        SelectCard->setGeometry(QRect(450, 290, 91, 71));
        AdminCard = new QPushButton(Maincontrol);
        AdminCard->setObjectName(QString::fromUtf8("AdminCard"));
        AdminCard->setGeometry(QRect(550, 290, 91, 71));
        backhome = new QPushButton(Maincontrol);
        backhome->setObjectName(QString::fromUtf8("backhome"));
        backhome->setGeometry(QRect(140, 20, 101, 31));
        back = new QPushButton(Maincontrol);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 20, 91, 31));
        back->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(Maincontrol);

        QMetaObject::connectSlotsByName(Maincontrol);
    } // setupUi

    void retranslateUi(QWidget *Maincontrol)
    {
        Maincontrol->setWindowTitle(QApplication::translate("Maincontrol", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Maincontrol", "\345\220\216\345\217\260\347\256\241\347\220\206\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
        AddCard->setText(QApplication::translate("Maincontrol", "\346\267\273\345\212\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        DeleteCard->setText(QApplication::translate("Maincontrol", "\345\210\240\351\231\244\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        UpdateCard->setText(QApplication::translate("Maincontrol", "\344\277\256\346\224\271\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        SelectCard->setText(QApplication::translate("Maincontrol", "\346\237\245\350\257\242\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        AdminCard->setText(QApplication::translate("Maincontrol", "\347\256\241\347\220\206\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        backhome->setText(QApplication::translate("Maincontrol", "\350\277\224\345\233\236\346\211\223\345\215\241\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
        back->setText(QApplication::translate("Maincontrol", "\347\231\273\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Maincontrol: public Ui_Maincontrol {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCONTROL_H
