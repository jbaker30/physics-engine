/****************************************************************************
** Meta object code from reading C++ file 'customrender.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../customrender.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customrender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CustomRender_t {
    QByteArrayData data[18];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomRender_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomRender_t qt_meta_stringdata_CustomRender = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CustomRender"
QT_MOC_LITERAL(1, 13, 9), // "ResetMass"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "value"
QT_MOC_LITERAL(4, 30, 11), // "ResetSpring"
QT_MOC_LITERAL(5, 42, 11), // "ResetDamper"
QT_MOC_LITERAL(6, 54, 15), // "ResetResistance"
QT_MOC_LITERAL(7, 70, 13), // "ResetPressure"
QT_MOC_LITERAL(8, 84, 15), // "mousePressEvent"
QT_MOC_LITERAL(9, 100, 12), // "QMouseEvent*"
QT_MOC_LITERAL(10, 113, 1), // "e"
QT_MOC_LITERAL(11, 115, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(12, 133, 10), // "ChangeMass"
QT_MOC_LITERAL(13, 144, 12), // "ChangeSpring"
QT_MOC_LITERAL(14, 157, 12), // "ChangeDamper"
QT_MOC_LITERAL(15, 170, 16), // "ChangeResistance"
QT_MOC_LITERAL(16, 187, 14), // "ChangePressure"
QT_MOC_LITERAL(17, 202, 15) // "ResetSimulation"

    },
    "CustomRender\0ResetMass\0\0value\0ResetSpring\0"
    "ResetDamper\0ResetResistance\0ResetPressure\0"
    "mousePressEvent\0QMouseEvent*\0e\0"
    "mouseReleaseEvent\0ChangeMass\0ChangeSpring\0"
    "ChangeDamper\0ChangeResistance\0"
    "ChangePressure\0ResetSimulation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomRender[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       5,    1,   85,    2, 0x06 /* Public */,
       6,    1,   88,    2, 0x06 /* Public */,
       7,    1,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   94,    2, 0x0a /* Public */,
      11,    1,   97,    2, 0x0a /* Public */,
      12,    1,  100,    2, 0x0a /* Public */,
      13,    1,  103,    2, 0x0a /* Public */,
      14,    1,  106,    2, 0x0a /* Public */,
      15,    1,  109,    2, 0x0a /* Public */,
      16,    1,  112,    2, 0x0a /* Public */,
      17,    0,  115,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void CustomRender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CustomRender *_t = static_cast<CustomRender *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ResetMass((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->ResetSpring((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ResetDamper((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ResetResistance((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->ResetPressure((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->ChangeMass((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->ChangeSpring((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->ChangeDamper((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->ChangeResistance((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->ChangePressure((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->ResetSimulation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CustomRender::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustomRender::ResetMass)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CustomRender::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustomRender::ResetSpring)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CustomRender::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustomRender::ResetDamper)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CustomRender::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustomRender::ResetResistance)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CustomRender::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustomRender::ResetPressure)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject CustomRender::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_CustomRender.data,
      qt_meta_data_CustomRender,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CustomRender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomRender::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CustomRender.stringdata0))
        return static_cast<void*>(const_cast< CustomRender*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int CustomRender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void CustomRender::ResetMass(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CustomRender::ResetSpring(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CustomRender::ResetDamper(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CustomRender::ResetResistance(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CustomRender::ResetPressure(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
