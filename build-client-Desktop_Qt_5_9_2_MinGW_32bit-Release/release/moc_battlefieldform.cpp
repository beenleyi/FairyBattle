/****************************************************************************
** Meta object code from reading C++ file 'battlefieldform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/battlefieldform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'battlefieldform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_battlefieldForm_t {
    QByteArrayData data[13];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_battlefieldForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_battlefieldForm_t qt_meta_stringdata_battlefieldForm = {
    {
QT_MOC_LITERAL(0, 0, 15), // "battlefieldForm"
QT_MOC_LITERAL(1, 16, 9), // "battleEnd"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "QString*"
QT_MOC_LITERAL(4, 36, 17), // "sendLoseAFairyBag"
QT_MOC_LITERAL(5, 54, 12), // "QJsonObject*"
QT_MOC_LITERAL(6, 67, 15), // "showUserFormReq"
QT_MOC_LITERAL(7, 83, 27), // "on_start_pushButton_clicked"
QT_MOC_LITERAL(8, 111, 14), // "myTimetoAttack"
QT_MOC_LITERAL(9, 126, 20), // "opponentTimetoAttack"
QT_MOC_LITERAL(10, 147, 8), // "gameOver"
QT_MOC_LITERAL(11, 156, 13), // "showBattleRes"
QT_MOC_LITERAL(12, 170, 28) // "on_return_pushButton_clicked"

    },
    "battlefieldForm\0battleEnd\0\0QString*\0"
    "sendLoseAFairyBag\0QJsonObject*\0"
    "showUserFormReq\0on_start_pushButton_clicked\0"
    "myTimetoAttack\0opponentTimetoAttack\0"
    "gameOver\0showBattleRes\0"
    "on_return_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_battlefieldForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   59,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       6,    0,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   76,    2, 0x08 /* Private */,
       8,    0,   77,    2, 0x08 /* Private */,
       9,    0,   78,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    1,   80,    2, 0x08 /* Private */,
      12,    0,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 3, 0x80000000 | 3,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,

       0        // eod
};

void battlefieldForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        battlefieldForm *_t = static_cast<battlefieldForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->battleEnd((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString*(*)>(_a[5])),(*reinterpret_cast< QString*(*)>(_a[6]))); break;
        case 1: _t->sendLoseAFairyBag((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 2: _t->showUserFormReq(); break;
        case 3: _t->on_start_pushButton_clicked(); break;
        case 4: _t->myTimetoAttack(); break;
        case 5: _t->opponentTimetoAttack(); break;
        case 6: _t->gameOver(); break;
        case 7: _t->showBattleRes((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 8: _t->on_return_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (battlefieldForm::*_t)(int , int , int , int , QString * , QString * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&battlefieldForm::battleEnd)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (battlefieldForm::*_t)(QJsonObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&battlefieldForm::sendLoseAFairyBag)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (battlefieldForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&battlefieldForm::showUserFormReq)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject battlefieldForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_battlefieldForm.data,
      qt_meta_data_battlefieldForm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *battlefieldForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *battlefieldForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_battlefieldForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int battlefieldForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void battlefieldForm::battleEnd(int _t1, int _t2, int _t3, int _t4, QString * _t5, QString * _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void battlefieldForm::sendLoseAFairyBag(QJsonObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void battlefieldForm::showUserFormReq()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
