/****************************************************************************
** Meta object code from reading C++ file 'Maincontrol.h'
**
** Created: Sun Sep 22 13:53:39 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Maincontrol.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Maincontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Maincontrol[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      35,   12,   12,   12, 0x08,
      56,   12,   12,   12, 0x08,
      80,   12,   12,   12, 0x08,
     104,   12,   12,   12, 0x08,
     122,   12,   12,   12, 0x08,
     146,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Maincontrol[] = {
    "Maincontrol\0\0on_backhome_clicked()\0"
    "on_AddCard_clicked()\0on_DeleteCard_clicked()\0"
    "on_UpdateCard_clicked()\0on_back_clicked()\0"
    "on_SelectCard_clicked()\0on_AdminCard_clicked()\0"
};

const QMetaObject Maincontrol::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Maincontrol,
      qt_meta_data_Maincontrol, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Maincontrol::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Maincontrol::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Maincontrol::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Maincontrol))
        return static_cast<void*>(const_cast< Maincontrol*>(this));
    return QWidget::qt_metacast(_clname);
}

int Maincontrol::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_backhome_clicked(); break;
        case 1: on_AddCard_clicked(); break;
        case 2: on_DeleteCard_clicked(); break;
        case 3: on_UpdateCard_clicked(); break;
        case 4: on_back_clicked(); break;
        case 5: on_SelectCard_clicked(); break;
        case 6: on_AdminCard_clicked(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
