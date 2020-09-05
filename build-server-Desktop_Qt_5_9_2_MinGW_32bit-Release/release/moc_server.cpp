/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../server/server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_myTcpServer_t {
    QByteArrayData data[14];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myTcpServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myTcpServer_t qt_meta_stringdata_myTcpServer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "myTcpServer"
QT_MOC_LITERAL(1, 12, 17), // "processDisconnect"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "QString*"
QT_MOC_LITERAL(4, 40, 16), // "processSignInBag"
QT_MOC_LITERAL(5, 57, 12), // "QJsonObject*"
QT_MOC_LITERAL(6, 70, 7), // "qintptr"
QT_MOC_LITERAL(7, 78, 16), // "processSignUpBag"
QT_MOC_LITERAL(8, 95, 17), // "processSignOutBag"
QT_MOC_LITERAL(9, 113, 21), // "processUserFairiesReq"
QT_MOC_LITERAL(10, 135, 14), // "processUserReq"
QT_MOC_LITERAL(11, 150, 23), // "processBattleFairiesReq"
QT_MOC_LITERAL(12, 174, 16), // "processBattleEnd"
QT_MOC_LITERAL(13, 191, 17) // "processLoseAFairy"

    },
    "myTcpServer\0processDisconnect\0\0QString*\0"
    "processSignInBag\0QJsonObject*\0qintptr\0"
    "processSignUpBag\0processSignOutBag\0"
    "processUserFairiesReq\0processUserReq\0"
    "processBattleFairiesReq\0processBattleEnd\0"
    "processLoseAFairy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myTcpServer[] = {

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
       1,    1,   59,    2, 0x08 /* Private */,
       4,    2,   62,    2, 0x08 /* Private */,
       7,    2,   67,    2, 0x08 /* Private */,
       8,    1,   72,    2, 0x08 /* Private */,
       9,    2,   75,    2, 0x08 /* Private */,
      10,    3,   80,    2, 0x08 /* Private */,
      11,    2,   87,    2, 0x08 /* Private */,
      12,    3,   92,    2, 0x08 /* Private */,
      13,    2,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 6,    2,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 6,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6,    2,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, 0x80000000 | 6,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6,    2,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 3, 0x80000000 | 6,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 3,    2,    2,

       0        // eod
};

void myTcpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        myTcpServer *_t = static_cast<myTcpServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->processDisconnect((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 1: _t->processSignInBag((*reinterpret_cast< QJsonObject*(*)>(_a[1])),(*reinterpret_cast< qintptr(*)>(_a[2]))); break;
        case 2: _t->processSignUpBag((*reinterpret_cast< QJsonObject*(*)>(_a[1])),(*reinterpret_cast< qintptr(*)>(_a[2]))); break;
        case 3: _t->processSignOutBag((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 4: _t->processUserFairiesReq((*reinterpret_cast< QString*(*)>(_a[1])),(*reinterpret_cast< qintptr(*)>(_a[2]))); break;
        case 5: _t->processUserReq((*reinterpret_cast< QString*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< qintptr(*)>(_a[3]))); break;
        case 6: _t->processBattleFairiesReq((*reinterpret_cast< QString*(*)>(_a[1])),(*reinterpret_cast< qintptr(*)>(_a[2]))); break;
        case 7: _t->processBattleEnd((*reinterpret_cast< QJsonObject*(*)>(_a[1])),(*reinterpret_cast< QString*(*)>(_a[2])),(*reinterpret_cast< qintptr(*)>(_a[3]))); break;
        case 8: _t->processLoseAFairy((*reinterpret_cast< QJsonObject*(*)>(_a[1])),(*reinterpret_cast< QString*(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject myTcpServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_myTcpServer.data,
      qt_meta_data_myTcpServer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *myTcpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myTcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_myTcpServer.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int myTcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
