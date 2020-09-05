/****************************************************************************
** Meta object code from reading C++ file 'selectopponentform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/selectopponentform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectopponentform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_selectOpponentForm_t {
    QByteArrayData data[12];
    char stringdata0[277];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_selectOpponentForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_selectOpponentForm_t qt_meta_stringdata_selectOpponentForm = {
    {
QT_MOC_LITERAL(0, 0, 18), // "selectOpponentForm"
QT_MOC_LITERAL(1, 19, 15), // "gotoBattlefield"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 12), // "QJsonObject*"
QT_MOC_LITERAL(4, 49, 15), // "showUserFormReq"
QT_MOC_LITERAL(5, 65, 15), // "showBattleFairy"
QT_MOC_LITERAL(6, 81, 43), // "on_userFairies_comboBox_curre..."
QT_MOC_LITERAL(7, 125, 4), // "arg1"
QT_MOC_LITERAL(8, 130, 45), // "on_serverFairies_comboBox_cur..."
QT_MOC_LITERAL(9, 176, 35), // "on_upgradeBattle_pushButton_c..."
QT_MOC_LITERAL(10, 212, 35), // "on_winloseBattle_pushButton_c..."
QT_MOC_LITERAL(11, 248, 28) // "on_return_pushButton_clicked"

    },
    "selectOpponentForm\0gotoBattlefield\0\0"
    "QJsonObject*\0showUserFormReq\0"
    "showBattleFairy\0"
    "on_userFairies_comboBox_currentIndexChanged\0"
    "arg1\0on_serverFairies_comboBox_currentIndexChanged\0"
    "on_upgradeBattle_pushButton_clicked\0"
    "on_winloseBattle_pushButton_clicked\0"
    "on_return_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_selectOpponentForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   54,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   62,    2, 0x08 /* Private */,
       6,    1,   65,    2, 0x08 /* Private */,
       8,    1,   68,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3, 0x80000000 | 3,    2,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void selectOpponentForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        selectOpponentForm *_t = static_cast<selectOpponentForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gotoBattlefield((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QJsonObject*(*)>(_a[2])),(*reinterpret_cast< QJsonObject*(*)>(_a[3]))); break;
        case 1: _t->showUserFormReq(); break;
        case 2: _t->showBattleFairy((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 3: _t->on_userFairies_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_serverFairies_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_upgradeBattle_pushButton_clicked(); break;
        case 6: _t->on_winloseBattle_pushButton_clicked(); break;
        case 7: _t->on_return_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (selectOpponentForm::*_t)(int , QJsonObject * , QJsonObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&selectOpponentForm::gotoBattlefield)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (selectOpponentForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&selectOpponentForm::showUserFormReq)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject selectOpponentForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_selectOpponentForm.data,
      qt_meta_data_selectOpponentForm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *selectOpponentForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *selectOpponentForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_selectOpponentForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int selectOpponentForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void selectOpponentForm::gotoBattlefield(int _t1, QJsonObject * _t2, QJsonObject * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void selectOpponentForm::showUserFormReq()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
