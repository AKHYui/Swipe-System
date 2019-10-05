#-------------------------------------------------
#
# Project created by QtCreator 2019-09-09T15:29:22
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ATSystem
TEMPLATE = app

QMAKE_LIBDIR += ../ATSystem/qextserialport/lib

unix {
LIBS += -lqextserialport
} else:win32 {
        CONFIG(debug, debug|release) {
                   LIBS += -lqextserialportd1
        } else {
                   LIBS += -lqextserialport1
        }
}
SOURCES += main.cpp\
        Login.cpp \
    QRFID/ChannelMan/RFIDChannelMan.cpp \
    QRFID/IEEE14443/IEEE14443Package.cpp \
    QRFID/IEEE14443/IEEE14443Control.cpp \
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
    QRFID/ChannelMan/RFIDChannelMan.h \
    QRFID/IEEE14443/IEEE14443Package.h \
    QRFID/IEEE14443/IEEE14443Control.h \
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

#LIBS +=  \
#    -lqextserialport

RESOURCES += \
    resource.qrc

INCLUDEPATH +=  \
    ../ATSystem/qextserialport/include \
    ../ATSystem/QRFID


linux-arm-gnueabi-g++ {
    target.path=/root
    INSTALLS += target
}
