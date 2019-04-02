/****************************************************************************
** Meta object code from reading C++ file 'renderingwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../renderingwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'renderingwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RenderingWindow_t {
    QByteArrayData data[16];
    char stringdata0[468];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RenderingWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RenderingWindow_t qt_meta_stringdata_RenderingWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "RenderingWindow"
QT_MOC_LITERAL(1, 16, 19), // "generateShapeButton"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 17), // "exportShapeButton"
QT_MOC_LITERAL(4, 55, 20), // "randomizeShapeButton"
QT_MOC_LITERAL(5, 76, 31), // "on_LineThickSlider_valueChanged"
QT_MOC_LITERAL(6, 108, 5), // "value"
QT_MOC_LITERAL(7, 114, 40), // "on_AggresivenessSmallSlider_v..."
QT_MOC_LITERAL(8, 155, 37), // "on_ComplexitySmallSlider_valu..."
QT_MOC_LITERAL(9, 193, 39), // "on_IrregularitySmallSlider_va..."
QT_MOC_LITERAL(10, 233, 41), // "on_AggresivenessMediumSlider_..."
QT_MOC_LITERAL(11, 275, 38), // "on_ComplexityMediumSlider_val..."
QT_MOC_LITERAL(12, 314, 40), // "on_IrregularityMediumSlider_v..."
QT_MOC_LITERAL(13, 355, 38), // "on_AggresivenessBigSlider_val..."
QT_MOC_LITERAL(14, 394, 35), // "on_ComplexityBigSlider_valueC..."
QT_MOC_LITERAL(15, 430, 37) // "on_IrregularityBigSlider_valu..."

    },
    "RenderingWindow\0generateShapeButton\0"
    "\0exportShapeButton\0randomizeShapeButton\0"
    "on_LineThickSlider_valueChanged\0value\0"
    "on_AggresivenessSmallSlider_valueChanged\0"
    "on_ComplexitySmallSlider_valueChanged\0"
    "on_IrregularitySmallSlider_valueChanged\0"
    "on_AggresivenessMediumSlider_valueChanged\0"
    "on_ComplexityMediumSlider_valueChanged\0"
    "on_IrregularityMediumSlider_valueChanged\0"
    "on_AggresivenessBigSlider_valueChanged\0"
    "on_ComplexityBigSlider_valueChanged\0"
    "on_IrregularityBigSlider_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RenderingWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    1,   82,    2, 0x08 /* Private */,
       7,    1,   85,    2, 0x08 /* Private */,
       8,    1,   88,    2, 0x08 /* Private */,
       9,    1,   91,    2, 0x08 /* Private */,
      10,    1,   94,    2, 0x08 /* Private */,
      11,    1,   97,    2, 0x08 /* Private */,
      12,    1,  100,    2, 0x08 /* Private */,
      13,    1,  103,    2, 0x08 /* Private */,
      14,    1,  106,    2, 0x08 /* Private */,
      15,    1,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void RenderingWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RenderingWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->generateShapeButton(); break;
        case 1: _t->exportShapeButton(); break;
        case 2: _t->randomizeShapeButton(); break;
        case 3: _t->on_LineThickSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_AggresivenessSmallSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_ComplexitySmallSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_IrregularitySmallSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_AggresivenessMediumSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_ComplexityMediumSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_IrregularityMediumSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_AggresivenessBigSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_ComplexityBigSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_IrregularityBigSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RenderingWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_RenderingWindow.data,
    qt_meta_data_RenderingWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RenderingWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RenderingWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RenderingWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int RenderingWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
