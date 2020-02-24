/****************************************************************************
** Meta object code from reading C++ file 'myconfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../New folder lol/qregr/myconfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myconfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyConfig_t {
    QByteArrayData data[12];
    char stringdata0[238];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyConfig_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyConfig_t qt_meta_stringdata_MyConfig = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyConfig"
QT_MOC_LITERAL(1, 9, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 24), // "on_radioButton_3_clicked"
QT_MOC_LITERAL(4, 57, 7), // "checked"
QT_MOC_LITERAL(5, 65, 24), // "on_radioButton_4_clicked"
QT_MOC_LITERAL(6, 90, 24), // "on_radioButton_5_clicked"
QT_MOC_LITERAL(7, 115, 24), // "on_radioButton_7_clicked"
QT_MOC_LITERAL(8, 140, 24), // "on_radioButton_6_clicked"
QT_MOC_LITERAL(9, 165, 24), // "on_radioButton_2_clicked"
QT_MOC_LITERAL(10, 190, 22), // "on_radioButton_clicked"
QT_MOC_LITERAL(11, 213, 24) // "on_radioButton_8_clicked"

    },
    "MyConfig\0on_pushButton_clicked\0\0"
    "on_radioButton_3_clicked\0checked\0"
    "on_radioButton_4_clicked\0"
    "on_radioButton_5_clicked\0"
    "on_radioButton_7_clicked\0"
    "on_radioButton_6_clicked\0"
    "on_radioButton_2_clicked\0"
    "on_radioButton_clicked\0on_radioButton_8_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyConfig[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    1,   65,    2, 0x08 /* Private */,
       5,    1,   68,    2, 0x08 /* Private */,
       6,    1,   71,    2, 0x08 /* Private */,
       7,    1,   74,    2, 0x08 /* Private */,
       8,    1,   77,    2, 0x08 /* Private */,
       9,    1,   80,    2, 0x08 /* Private */,
      10,    1,   83,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      11,    1,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,

       0        // eod
};

void MyConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyConfig *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_radioButton_3_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_radioButton_4_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_radioButton_5_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_radioButton_7_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_radioButton_6_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_radioButton_2_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_radioButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;

        case 9: _t->on_radioButton_8_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyConfig::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_MyConfig.data,
    qt_meta_data_MyConfig,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyConfig.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MyConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
