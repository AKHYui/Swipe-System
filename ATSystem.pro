#-------------------------------------------------
#
# Project created by QtCreator 2019-09-09T15:29:22
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ATSystem
TEMPLATE = app


SOURCES += main.cpp\
        Login.cpp \
    Maincontrol.cpp \
    Homepage.cpp \
    Addpage.cpp \
    Deletepage.cpp \
    Updatepage.cpp \
    Selectpage.cpp \
    Adminlogin.cpp \
    Adminpage.cpp  \
    ATSysDatabaseControl.cpp

HEADERS  += Login.h \
    Maincontrol.h \
    Homepage.h \
    Addpage.h \
    Deletepage.h \
    Updatepage.h \
    Selectpage.h \
    Adminlogin.h \
    Adminpage.h  \
    ATSysDatabaseControl.h

FORMS    += Login.ui \
    Maincontrol.ui \
    Homepage.ui \
    Addpage.ui \
    Deletepage.ui \
    Updatepage.ui \
    Selectpage.ui \
    Adminlogin.ui \
    Adminpage.ui

RESOURCES += \
    resource.qrc
