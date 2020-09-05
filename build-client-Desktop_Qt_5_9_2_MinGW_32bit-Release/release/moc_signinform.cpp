/****************************************************************************
** Meta object code from reading C++ file 'signinform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/signinform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'signinform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_signInForm_t {
    QByteArrayData data[10];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_signInForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_signInForm_t qt_meta_stringdata_signInForm = {
    {
QT_MOC_LITERAL(0, 0, 10), // "signInForm"
QT_MOC_LITERAL(1, 11, 14), // "sendMessageReq"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "QJsonObject*"
QT_MOC_LITERAL(4, 40, 9), // "signUpReq"
QT_MOC_LITERAL(5, 50, 28), // "on_signIn_pushButton_clicked"
QT_MOC_LITERAL(6, 79, 28), // "on_signUp_pushButton_clicked"
QT_MOC_LITERAL(7, 108, 18), // "signIn_passwordErr"
QT_MOC_LITERAL(8, 127, 22), // "signIn_accountNotExist"
QT_MOC_LITERAL(9, 150, 8) // "showForm"

    },
    "signInForm\0sendMessageReq\0\0QJsonObject*\0"
    "signUpReq\0on_signIn_pushButton_clicked\0"
    "on_signUp_pushButton_clicked\0"
    "signIn_passwordErr\0signIn_accountNotExist\0"
    "showForm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_signInForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    0,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void signInForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        signInForm *_t = static_cast<signInForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMessageReq((*reinterpret_cast< QJsonObject*(*)>(_a[1]))); break;
        case 1: _t->signUpReq(); break;
        case 2: _t->on_signIn_pushButton_clicked(); break;
        case 3: _t->on_signUp_pushButton_clicked(); break;
        case 4: _t->signIn_passwordErr(); break;
        case 5: _t->signIn_accountNotExist(); break;
        case 6: _t->showForm(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (signInForm::*_t)(QJsonObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&signInForm::sendMessageReq)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (signInForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&signInForm::signUpReq)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject signInForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_signInForm.data,
      qt_meta_data_signInForm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *signInForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *signInForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_signInForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int signInForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void signInForm::sendMessageReq(QJsonObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void signInForm::signUpReq()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
