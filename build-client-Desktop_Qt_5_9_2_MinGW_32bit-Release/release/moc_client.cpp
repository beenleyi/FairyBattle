/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_client_t {
    QByteArrayData data[21];
    char stringdata0[320];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_client_t qt_meta_stringdata_client = {
    {
QT_MOC_LITERAL(0, 0, 6), // "client"
QT_MOC_LITERAL(1, 7, 22), // "signUp_usernameExisted"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 20), // "signUp_signUpSecceed"
QT_MOC_LITERAL(4, 52, 20), // "signIn_signInSecceed"
QT_MOC_LITERAL(5, 73, 18), // "signIn_passwordErr"
QT_MOC_LITERAL(6, 92, 22), // "signIn_accountNotExist"
QT_MOC_LITERAL(7, 115, 10), // "getMyFairy"
QT_MOC_LITERAL(8, 126, 12), // "QJsonObject*"
QT_MOC_LITERAL(9, 139, 10), // "getUserBag"
QT_MOC_LITERAL(10, 150, 19), // "getBattleFairiesBag"
QT_MOC_LITERAL(11, 170, 18), // "getBattleEndResBag"
QT_MOC_LITERAL(12, 189, 18), // "preProcessRecvData"
QT_MOC_LITERAL(13, 208, 16), // "processSignUpReq"
QT_MOC_LITERAL(14, 225, 11), // "sendMessage"
QT_MOC_LITERAL(15, 237, 10), // "getFairies"
QT_MOC_LITERAL(16, 248, 16), // "toSelectOpponent"
QT_MOC_LITERAL(17, 265, 15), // "showBattlefield"
QT_MOC_LITERAL(18, 281, 12), // "showUserForm"
QT_MOC_LITERAL(19, 294, 16), // "sendBattleEndBag"
QT_MOC_LITERAL(20, 311, 8) // "QString*"

    },
    "client\0signUp_usernameExisted\0\0"
    "signUp_signUpSecceed\0signIn_signInSecceed\0"
    "signIn_passwordErr\0signIn_accountNotExist\0"
    "getMyFairy\0QJsonObject*\0getUserBag\0"
    "getBattleFairiesBag\0getBattleEndResBag\0"
    "preProcessRecvData\0processSignUpReq\0"
    "sendMessage\0getFairies\0toSelectOpponent\0"
    "showBattlefield\0showUserForm\0"
    "sendBattleEndBag\0QString*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,
       4,    0,  101,    2, 0x06 /* Public */,
       5,    0,  102,    2, 0x06 /* Public */,
       6,    0,  103,    2, 0x06 /* Public */,
       7,    1,  104,    2, 0x06 /* Public */,
       9,    1,  107,    2, 0x06 /* Public */,
      10,    1,  110,    2, 0x06 /* Public */,
      11,    1,  113,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,  116,    2, 0x08 /* Private */,
      13,    0,  117,    2, 0x08 /* Private */,
      14,    1,  118,    2, 0x08 /* Private */,
      15,    0,  121,    2, 0x08 /* Private */,
      16,    0,  122,    2, 0x08 /* Private */,
      17,    3,  123,    2, 0x08 /* Private */,
      18,    0,  130,    2, 0x08 /* Private */,
      19,    6,  131,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 8,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8, 0x80000000 | 8,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 20, 0x80000000 | 20,    2,    2,    2,    2,    2,    2,

       0        // eod
};

void client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        client *_t = static_cast<client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signUp_usernameExisted(); break;
        case 1: _t->signUp_signUpSecceed(); break;
        case 2: _t->signIn_signInSecceed(); break;
        case 3: _t->signIn_passwordErr(); break;
        case 4: _t->signIn_accountNotExist(); break;
        case 5: _t->getMyFairy((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 6: _t->getUserBag((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 7: _t->getBattleFairiesBag((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 8: _t->getBattleEndResBag((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 9: _t->preProcessRecvData(); break;
        case 10: _t->processSignUpReq(); break;
        case 11: _t->sendMessage((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 12: _t->getFairies(); break;
        case 13: _t->toSelectOpponent(); break;
        case 14: _t->showBattlefield((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QJsonObject*(*)>(_a[2])),(*reinterpret_cast< QJsonObject*(*)>(_a[3]))); break;
        case 15: _t->showUserForm(); break;
        case 16: _t->sendBattleEndBag((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString*(*)>(_a[5])),(*reinterpret_cast< QString*(*)>(_a[6]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::signUp_usernameExisted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::signUp_signUpSecceed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::signIn_signInSecceed)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::signIn_passwordErr)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::signIn_accountNotExist)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (client::*_t)(QJsonObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::getMyFairy)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (client::*_t)(QJsonObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::getUserBag)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (client::*_t)(QJsonObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::getBattleFairiesBag)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (client::*_t)(QJsonObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::getBattleEndResBag)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject client::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_client.data,
      qt_meta_data_client,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_client.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void client::signUp_usernameExisted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void client::signUp_signUpSecceed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void client::signIn_signInSecceed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void client::signIn_passwordErr()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void client::signIn_accountNotExist()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void client::getMyFairy(QJsonObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void client::getUserBag(QJsonObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void client::getBattleFairiesBag(QJsonObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void client::getBattleEndResBag(QJsonObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
