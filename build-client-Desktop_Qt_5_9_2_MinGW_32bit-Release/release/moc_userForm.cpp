/****************************************************************************
** Meta object code from reading C++ file 'userForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/userForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_userForm_t {
    QByteArrayData data[15];
    char stringdata0[323];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_userForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_userForm_t qt_meta_stringdata_userForm = {
    {
QT_MOC_LITERAL(0, 0, 8), // "userForm"
QT_MOC_LITERAL(1, 9, 17), // "showSignInFormReq"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "sendMessageReq"
QT_MOC_LITERAL(4, 43, 12), // "QJsonObject*"
QT_MOC_LITERAL(5, 56, 13), // "needMyFairies"
QT_MOC_LITERAL(6, 70, 18), // "gotoSelectOpponent"
QT_MOC_LITERAL(7, 89, 35), // "on_upgradeBattle_pushButton_c..."
QT_MOC_LITERAL(8, 125, 29), // "on_signOut_pushButton_clicked"
QT_MOC_LITERAL(9, 155, 17), // "AddMyFairiesTable"
QT_MOC_LITERAL(10, 173, 11), // "showUserBag"
QT_MOC_LITERAL(11, 185, 39), // "on_lookUpOnlineUsers_pushButt..."
QT_MOC_LITERAL(12, 225, 36), // "on_lookUpAllUsers_pushButton_..."
QT_MOC_LITERAL(13, 262, 31), // "on_myFairies_pushButton_clicked"
QT_MOC_LITERAL(14, 294, 28) // "on_battle_pushButton_clicked"

    },
    "userForm\0showSignInFormReq\0\0sendMessageReq\0"
    "QJsonObject*\0needMyFairies\0"
    "gotoSelectOpponent\0"
    "on_upgradeBattle_pushButton_clicked\0"
    "on_signOut_pushButton_clicked\0"
    "AddMyFairiesTable\0showUserBag\0"
    "on_lookUpOnlineUsers_pushButton_clicked\0"
    "on_lookUpAllUsers_pushButton_clicked\0"
    "on_myFairies_pushButton_clicked\0"
    "on_battle_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_userForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    1,   75,    2, 0x06 /* Public */,
       5,    0,   78,    2, 0x06 /* Public */,
       6,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   80,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    1,   82,    2, 0x08 /* Private */,
      10,    1,   85,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void userForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        userForm *_t = static_cast<userForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showSignInFormReq(); break;
        case 1: _t->sendMessageReq((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 2: _t->needMyFairies(); break;
        case 3: _t->gotoSelectOpponent(); break;
        case 4: _t->on_upgradeBattle_pushButton_clicked(); break;
        case 5: _t->on_signOut_pushButton_clicked(); break;
        case 6: _t->AddMyFairiesTable((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 7: _t->showUserBag((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 8: _t->on_lookUpOnlineUsers_pushButton_clicked(); break;
        case 9: _t->on_lookUpAllUsers_pushButton_clicked(); break;
        case 10: _t->on_myFairies_pushButton_clicked(); break;
        case 11: _t->on_battle_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (userForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&userForm::showSignInFormReq)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (userForm::*_t)(QJsonObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&userForm::sendMessageReq)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (userForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&userForm::needMyFairies)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (userForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&userForm::gotoSelectOpponent)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject userForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_userForm.data,
      qt_meta_data_userForm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *userForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *userForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_userForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int userForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void userForm::showSignInFormReq()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void userForm::sendMessageReq(QJsonObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void userForm::needMyFairies()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void userForm::gotoSelectOpponent()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
