/****************************************************************************
** Meta object code from reading C++ file 'Addpage.h'
**
** Created: Tue Sep 24 10:09:24 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Addpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Addpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Addpage[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      16,    8,    8,    8, 0x08,
      38,    8,    8,    8, 0x08,
      63,    8,    8,    8, 0x08,
     102,   89,    8,    8, 0x08,
     149,  134,    8,    8, 0x08,
     185,  178,    8,    8, 0x08,
     226,  215,    8,    8, 0x08,
     256,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Addpage[] = {
    "Addpage\0\0load()\0on_pbn_back_clicked()\0"
    "on_pbn_addName_clicked()\0"
    "on_btn_dbselect_clicked()\0decID,byteID\0"
    "onNewCard(qlonglong,QByteArray)\0"
    "cmdType,result\0on_search_error(int,QString)\0"
    "cardid\0on_search_success(QByteArray)\0"
    "block,data\0on_ted_showID(int,QByteArray)\0"
    "on_pbn_start_clicked()\0"
};

const QMetaObject Addpage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Addpage,
      qt_meta_data_Addpage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Addpage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Addpage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Addpage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Addpage))
        return static_cast<void*>(const_cast< Addpage*>(this));
    return QWidget::qt_metacast(_clname);
}

int Addpage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: load(); break;
        case 1: on_pbn_back_clicked(); break;
        case 2: on_pbn_addName_clicked(); break;
        case 3: on_btn_dbselect_clicked(); break;
        case 4: onNewCard((*reinterpret_cast< qlonglong(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 5: on_search_error((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: on_search_success((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 7: on_ted_showID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 8: on_pbn_start_clicked(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
