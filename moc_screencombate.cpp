/****************************************************************************
** Meta object code from reading C++ file 'screencombate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screencombate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screencombate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ScreenCombate_t {
    QByteArrayData data[13];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScreenCombate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScreenCombate_t qt_meta_stringdata_ScreenCombate = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ScreenCombate"
QT_MOC_LITERAL(1, 14, 16), // "ActualizarEquipo"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 12), // "QVector<int>"
QT_MOC_LITERAL(4, 45, 16), // "on_Salir_clicked"
QT_MOC_LITERAL(5, 62, 16), // "on_usar1_clicked"
QT_MOC_LITERAL(6, 79, 16), // "on_usar2_clicked"
QT_MOC_LITERAL(7, 96, 18), // "ActualizarPantalla"
QT_MOC_LITERAL(8, 115, 14), // "ActualizarMenu"
QT_MOC_LITERAL(9, 130, 19), // "on_cambiar1_clicked"
QT_MOC_LITERAL(10, 150, 19), // "on_cambiar2_clicked"
QT_MOC_LITERAL(11, 170, 15), // "ComprobarEquipo"
QT_MOC_LITERAL(12, 186, 36) // "QVector<std::shared_ptr<Perso..."

    },
    "ScreenCombate\0ActualizarEquipo\0\0"
    "QVector<int>\0on_Salir_clicked\0"
    "on_usar1_clicked\0on_usar2_clicked\0"
    "ActualizarPantalla\0ActualizarMenu\0"
    "on_cambiar1_clicked\0on_cambiar2_clicked\0"
    "ComprobarEquipo\0QVector<std::shared_ptr<Personaje> >"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScreenCombate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    0,   62,    2, 0x08 /* Private */,
       5,    0,   63,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    1,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 12,    2,

       0        // eod
};

void ScreenCombate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScreenCombate *_t = static_cast<ScreenCombate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ActualizarEquipo((*reinterpret_cast< QVector<int>(*)>(_a[1]))); break;
        case 1: _t->on_Salir_clicked(); break;
        case 2: _t->on_usar1_clicked(); break;
        case 3: _t->on_usar2_clicked(); break;
        case 4: _t->ActualizarPantalla(); break;
        case 5: _t->ActualizarMenu(); break;
        case 6: _t->on_cambiar1_clicked(); break;
        case 7: _t->on_cambiar2_clicked(); break;
        case 8: { int _r = _t->ComprobarEquipo((*reinterpret_cast< QVector<std::shared_ptr<Personaje> >(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    }
}

const QMetaObject ScreenCombate::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ScreenCombate.data,
      qt_meta_data_ScreenCombate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ScreenCombate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScreenCombate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ScreenCombate.stringdata0))
        return static_cast<void*>(const_cast< ScreenCombate*>(this));
    return QDialog::qt_metacast(_clname);
}

int ScreenCombate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
