    #include "Login.h"
#include <QApplication>
#include <QApplication>
#include <QTextCodec>
#include <Homepage.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    //Login w;
    Homepage h;
    h.show();

    return a.exec();
}
