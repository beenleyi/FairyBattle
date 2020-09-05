/****************************************************************************
** Meta object code from reading C++ file 'socket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../server/socket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'socket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_myTcpSocket_t {
    QByteArrayData data[16];
    char stringdata0[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myTcpSocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myTcpSocket_t qt_meta_stringdata_myTcpSocket = {
    {
QT_MOC_LITERAL(0, 0, 11), // "myTcpSocket"
QT_MOC_LITERAL(1, 12, 12), // "getSignInBag"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "QJsonObject*"
QT_MOC_LITERAL(4, 39, 7), // "qintptr"
QT_MOC_LITERAL(5, 47, 12), // "getSignUpBag"
QT_MOC_LITERAL(6, 60, 13), // "getSignOutBag"
QT_MOC_LITERAL(7, 74, 8), // "QString*"
QT_MOC_LITERAL(8, 83, 16), // "clientDisconnect"
QT_MOC_LITERAL(9, 100, 17), // "getUserFairiesReq"
QT_MOC_LITERAL(10, 118, 10), // "getUserReq"
QT_MOC_LITERAL(11, 129, 22), // "getBattleFairiesReqBag"
QT_MOC_LITERAL(12, 152, 15), // "getBattleEndBag"
QT_MOC_LITERAL(13, 168, 16), // "getLoseAFairyBag"
QT_MOC_LITERAL(14, 185, 18), // "preProcessRecvData"
QT_MOC_LITERAL(15, 204, 20) // "preProcessDisconnect"

    },
    "myTcpSocket\0getSignInBag\0\0QJsonObject*\0"
    "qintptr\0getSignUpBag\0getSignOutBag\0"
    "QString*\0clientDisconnect\0getUserFairiesReq\0"
    "getUserReq\0getBattleFairiesReqBag\0"
    "getBattleEndBag\0getLoseAFairyBag\0"
    "preProcessRecvData\0preProcessDisconnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myTcpSocket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       5,    2,   74,    2, 0x06 /* Public */,
       6,    1,   79,    2, 0x06 /* Public */,
       8,    1,   82,    2, 0x06 /* Public */,
       9,    2,   85,    2, 0x06 /* Public */,
      10,    3,   90,    2, 0x06 /* Public */,
      11,    2,   97,    2, 0x06 /* Public */,
      12,    3,  102,    2, 0x06 /* Public */,
      13,    2,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  114,    2, 0x0a /* Public */,
      15,    0,  115,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int, 0x80000000 | 4,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 7, 0x80000000 | 4,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 7,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void myTcpSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        myTcpSocket *_t = static_cast<myTcpSocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getSignInBag((*reinterpret_cast< QJsonObject*(*)>(_a[1])),(*reinterpret_cast< qintptr(*)>(_a[2]))); break;
        case 1: _t->getSignUpBag((*reinterpret_cast< QJsonObject*(*)>(_a[1])),(*reinterpret_cast< qintptr(*)>(_a[2]))); break;
        case 2: _t->getSignOutBag((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 3: _t->clientDisconnect((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 4: _t->getUserFairiesReq((*reinterpret_cast< QString*(*)>(_a[1])),(*reinterpret_cast< qintptr(*)>(_a[2]))); break;
        case 5: _t->getUserReq((*reinterpret_cast< QString*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< qintptr(*)>(_a[3]))); break;
        case 6: _t->getBattleFairiesReqBag((*reinterpret_cast< QString*(*)>(_a[1])),(*reinterpret_cast< qintptr(*)>(_a[2]))); break;
        case 7: _t->getBattleEndBag((*reinterpret_cast< QJsonObject*(*)>(_a[1])),(*reinterpret_cast< QString*(*)>(_a[2])),(*reinterpret_cast< qintptr(*)>(_a[3]))); break;
        case 8: _t->getLoseAFairyBag((*reinterpret_cast< QJsonObject*(*)>(_a[1])),(*reinterpret_cast< QString*(*)>(_a[2]))); break;
        case 9: _t->preProcessRecvData(); break;
        case 10: _t->preProcessDisconnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (myTcpSocket::*_t)(QJsonObject * , qintptr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&myTcpSocket::getSignInBag)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (myTcpSocket::*_t)(QJsonObject * , qintptr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&myTcpSocket::getSignUpBag)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (myTcpSocket::*_t)(QString * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&myTcpSocket::getSignOutBag)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (myTcpSocket::*_t)(QString * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&myTcpSocket::clientDisconnect)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (myTcpSocket::*_t)(QString * , qintptr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&myTcpSocket::getUserFairiesReq)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (myTcpSocket::*_t)(QString * , int , qintptr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&myTcpSocket::getUserReq)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (myTcpSocket::*_t)(QString * , qintptr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&myTcpSocket::getBattleFairiesReqBag)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (myTcpSocket::*_t)(QJsonObject * , QString * , qintptr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&myTcpSocket::getBattleEndBag)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (myTcpSocket::*_t)(QJsonObject * , QString * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&myTcpSocket::getLoseAFairyBag)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject myTcpSocket::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_myTcpSocket.data,
      qt_meta_data_myTcpSocket,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *myTcpSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myTcpSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_myTcpSocket.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int myTcpSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void myTcpSocket::getSignInBag(QJsonObject * _t1, qintptr _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void myTcpSocket::getSignUpBag(QJsonObject * _t1, qintptr _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void myTcpSocket::getSignOutBag(QString * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void myTcpSocket::clientDisconnect(QString * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void myTcpSocket::getUserFairiesReq(QString * _t1, qintptr _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void myTcpSocket::getUserReq(QString * _t1, int _t2, qintptr _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void myTcpSocket::getBattleFairiesReqBag(QString * _t1, qintptr _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void myTcpSocket::getBattleEndBag(QJsonObject * _t1, QString * _t2, qintptr _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void myTcpSocket::getLoseAFairyBag(QJsonObject * _t1, QString * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
