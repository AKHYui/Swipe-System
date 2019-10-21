/****************************************************************************
** Meta object code from reading C++ file 'Selectpage.h'
**
** Created: Sun Oct 20 13:45:47 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Selectpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Selectpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Selectpage[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      34,   19,   11,   11, 0x08,
      74,   63,   11,   11, 0x08,
     117,  104,   11,   11, 0x08,
     156,  149,   11,   11, 0x08,
     186,   11,   11,   11, 0x08,
     208,   11,   11,   11, 0x08,
     234,   11,   11,   11, 0x08,
     261,   11,   11,   11, 0x08,
     285,   11,   11,   11, 0x08,
     317,  312,   11,   11, 0x08,
     337,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Selectpage[] = {
    "Selectpage\0\0load()\0cmdType,result\0"
    "on_search_error(int,QString)\0block,data\0"
    "on_ted_showID(int,QByteArray)\0"
    "decID,byteID\0onNewCard(qlonglong,QByteArray)\0"
    "cardid\0on_search_success(QByteArray)\0"
    "on_sel_back_clicked()\0on_btn_dbselect_clicked()\0"
    "on_btn_dbrefresh_clicked()\0"
    "on_pbn_search_clicked()\0"
    "on_pbn_searchLog_clicked()\0card\0"
    "log_load(qlonglong)\0on_readcard_clicked()\0"
};

const QMetaObject Selectpage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Selectpage,
      qt_meta_data_Selectpage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Selectpage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Selectpage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Selectpage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Selectpage))
        return static_cast<void*>(const_cast< Selectpage*>(this));
    return QWidget::qt_metacast(_clname);
}

int Selectpage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: load(); break;
        case 1: on_search_error((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: on_ted_showID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 3: onNewCard((*reinterpret_cast< qlonglong(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 4: on_search_success((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 5: on_sel_back_clicked(); break;
        case 6: on_btn_dbselect_clicked(); break;
        case 7: on_btn_dbrefresh_clicked(); break;
        case 8: on_pbn_search_clicked(); break;
        case 9: on_pbn_searchLog_clicked(); break;
        case 10: log_load((*reinterpret_cast< qlonglong(*)>(_a[1]))); break;
        case 11: on_readcard_clicked(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
