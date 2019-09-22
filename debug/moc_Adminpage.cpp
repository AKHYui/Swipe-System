/****************************************************************************
** Meta object code from reading C++ file 'Adminpage.h'
**
** Created: Sun Sep 22 13:47:55 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Adminpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Adminpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Adminpage[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      18,   10,   10,   10, 0x08,
      40,   10,   10,   10, 0x08,
      66,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Adminpage[] = {
    "Adminpage\0\0load()\0on_pbn_back_clicked()\0"
    "on_btn_dbselect_clicked()\0"
    "on_btn_dbrefresh_clicked()\0"
};

const QMetaObject Adminpage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Adminpage,
      qt_meta_data_Adminpage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Adminpage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Adminpage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Adminpage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Adminpage))
        return static_cast<void*>(const_cast< Adminpage*>(this));
    return QWidget::qt_metacast(_clname);
}

int Adminpage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: load(); break;
        case 1: on_pbn_back_clicked(); break;
        case 2: on_btn_dbselect_clicked(); break;
        case 3: on_btn_dbrefresh_clicked(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
