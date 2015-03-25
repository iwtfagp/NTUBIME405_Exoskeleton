/****************************************************************************
** Meta object code from reading C++ file 'qt_exoskeleton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qt_exoskeleton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt_exoskeleton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_qt_exoskeleton_t {
    QByteArrayData data[16];
    char stringdata[367];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qt_exoskeleton_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qt_exoskeleton_t qt_meta_stringdata_qt_exoskeleton = {
    {
QT_MOC_LITERAL(0, 0, 14), // "qt_exoskeleton"
QT_MOC_LITERAL(1, 15, 10), // "updateView"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 33), // "on_pushButton_calibration_cli..."
QT_MOC_LITERAL(4, 61, 28), // "on_pushButton_enable_clicked"
QT_MOC_LITERAL(5, 90, 29), // "on_pushButton_connect_clicked"
QT_MOC_LITERAL(6, 120, 27), // "on_pushButton_close_clicked"
QT_MOC_LITERAL(7, 148, 30), // "on_pushButton_standing_clicked"
QT_MOC_LITERAL(8, 179, 29), // "on_pushButton_sitting_clicked"
QT_MOC_LITERAL(9, 209, 31), // "on_pushButton_extension_clicked"
QT_MOC_LITERAL(10, 241, 29), // "on_pushButton_flexion_clicked"
QT_MOC_LITERAL(11, 271, 13), // "keyPressEvent"
QT_MOC_LITERAL(12, 285, 10), // "QKeyEvent*"
QT_MOC_LITERAL(13, 296, 5), // "event"
QT_MOC_LITERAL(14, 302, 32), // "on_pushButton_StartModel_clicked"
QT_MOC_LITERAL(15, 335, 31) // "on_pushButton_loadModel_clicked"

    },
    "qt_exoskeleton\0updateView\0\0"
    "on_pushButton_calibration_clicked\0"
    "on_pushButton_enable_clicked\0"
    "on_pushButton_connect_clicked\0"
    "on_pushButton_close_clicked\0"
    "on_pushButton_standing_clicked\0"
    "on_pushButton_sitting_clicked\0"
    "on_pushButton_extension_clicked\0"
    "on_pushButton_flexion_clicked\0"
    "keyPressEvent\0QKeyEvent*\0event\0"
    "on_pushButton_StartModel_clicked\0"
    "on_pushButton_loadModel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qt_exoskeleton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    1,   83,    2, 0x08 /* Private */,
      14,    0,   86,    2, 0x08 /* Private */,
      15,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void qt_exoskeleton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        qt_exoskeleton *_t = static_cast<qt_exoskeleton *>(_o);
        switch (_id) {
        case 0: _t->updateView(); break;
        case 1: _t->on_pushButton_calibration_clicked(); break;
        case 2: _t->on_pushButton_enable_clicked(); break;
        case 3: _t->on_pushButton_connect_clicked(); break;
        case 4: _t->on_pushButton_close_clicked(); break;
        case 5: _t->on_pushButton_standing_clicked(); break;
        case 6: _t->on_pushButton_sitting_clicked(); break;
        case 7: _t->on_pushButton_extension_clicked(); break;
        case 8: _t->on_pushButton_flexion_clicked(); break;
        case 9: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 10: _t->on_pushButton_StartModel_clicked(); break;
        case 11: _t->on_pushButton_loadModel_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject qt_exoskeleton::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_qt_exoskeleton.data,
      qt_meta_data_qt_exoskeleton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *qt_exoskeleton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qt_exoskeleton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_qt_exoskeleton.stringdata))
        return static_cast<void*>(const_cast< qt_exoskeleton*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int qt_exoskeleton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
