/****************************************************************************
** Meta object code from reading C++ file 'header.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "header.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'header.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LEDBlock_t {
    QByteArrayData data[13];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LEDBlock_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LEDBlock_t qt_meta_stringdata_LEDBlock = {
    {
QT_MOC_LITERAL(0, 0, 8), // "LEDBlock"
QT_MOC_LITERAL(1, 9, 7), // "clicked"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 4), // "tick"
QT_MOC_LITERAL(4, 23, 12), // "valueChanged"
QT_MOC_LITERAL(5, 36, 8), // "newValue"
QT_MOC_LITERAL(6, 45, 12), // "valueClicked"
QT_MOC_LITERAL(7, 58, 5), // "value"
QT_MOC_LITERAL(8, 64, 5), // "LEDon"
QT_MOC_LITERAL(9, 70, 6), // "LEDoff"
QT_MOC_LITERAL(10, 77, 8), // "setValue"
QT_MOC_LITERAL(11, 86, 9), // "initLogic"
QT_MOC_LITERAL(12, 96, 8) // "binLogic"

    },
    "LEDBlock\0clicked\0\0tick\0valueChanged\0"
    "newValue\0valueClicked\0value\0LEDon\0"
    "LEDoff\0setValue\0initLogic\0binLogic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LEDBlock[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    1,   61,    2, 0x06 /* Public */,
       6,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   67,    2, 0x0a /* Public */,
       9,    0,   68,    2, 0x0a /* Public */,
      10,    1,   69,    2, 0x0a /* Public */,
      11,    0,   72,    2, 0x0a /* Public */,
      12,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LEDBlock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LEDBlock *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clicked(); break;
        case 1: _t->tick(); break;
        case 2: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->valueClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->LEDon(); break;
        case 5: _t->LEDoff(); break;
        case 6: _t->setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->initLogic(); break;
        case 8: _t->binLogic(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LEDBlock::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LEDBlock::clicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LEDBlock::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LEDBlock::tick)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LEDBlock::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LEDBlock::valueChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (LEDBlock::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LEDBlock::valueClicked)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LEDBlock::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_LEDBlock.data,
    qt_meta_data_LEDBlock,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LEDBlock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LEDBlock::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LEDBlock.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LEDBlock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void LEDBlock::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LEDBlock::tick()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void LEDBlock::valueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LEDBlock::valueClicked(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
