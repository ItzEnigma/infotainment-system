/****************************************************************************
** Meta object code from reading C++ file 'lockscreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../lockScreen/lockscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lockscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_lockScreen_t {
    QByteArrayData data[7];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_lockScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_lockScreen_t qt_meta_stringdata_lockScreen = {
    {
QT_MOC_LITERAL(0, 0, 10), // "lockScreen"
QT_MOC_LITERAL(1, 11, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 33), // "on_lineEdit_cursorPositionCha..."
QT_MOC_LITERAL(4, 68, 35), // "on_lineEdit_2_cursorPositionC..."
QT_MOC_LITERAL(5, 104, 35), // "on_lineEdit_3_cursorPositionC..."
QT_MOC_LITERAL(6, 140, 35) // "on_lineEdit_4_cursorPositionC..."

    },
    "lockScreen\0on_pushButton_clicked\0\0"
    "on_lineEdit_cursorPositionChanged\0"
    "on_lineEdit_2_cursorPositionChanged\0"
    "on_lineEdit_3_cursorPositionChanged\0"
    "on_lineEdit_4_cursorPositionChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_lockScreen[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void lockScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<lockScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_lineEdit_cursorPositionChanged(); break;
        case 2: _t->on_lineEdit_2_cursorPositionChanged(); break;
        case 3: _t->on_lineEdit_3_cursorPositionChanged(); break;
        case 4: _t->on_lineEdit_4_cursorPositionChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject lockScreen::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_lockScreen.data,
    qt_meta_data_lockScreen,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *lockScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lockScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_lockScreen.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int lockScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
