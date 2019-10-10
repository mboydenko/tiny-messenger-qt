/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Messenger(source)/client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Client_t {
    QByteArrayData data[28];
    char stringdata0[428];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Client_t qt_meta_stringdata_Client = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Client"
QT_MOC_LITERAL(1, 7, 17), // "signalInvalidData"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 26), // "signalUserNameNotAvailable"
QT_MOC_LITERAL(4, 53, 28), // "signalSuccessfulRegistration"
QT_MOC_LITERAL(5, 82, 18), // "signalUserReceived"
QT_MOC_LITERAL(6, 101, 4), // "User"
QT_MOC_LITERAL(7, 106, 18), // "signalUserNotFound"
QT_MOC_LITERAL(8, 125, 24), // "signalServerNotAvailable"
QT_MOC_LITERAL(9, 150, 20), // "signalReceiveMessage"
QT_MOC_LITERAL(10, 171, 3), // "mes"
QT_MOC_LITERAL(11, 175, 6), // "sender"
QT_MOC_LITERAL(12, 182, 11), // "destination"
QT_MOC_LITERAL(13, 194, 15), // "signalAddDialog"
QT_MOC_LITERAL(14, 210, 18), // "signalDeleteDialog"
QT_MOC_LITERAL(15, 229, 13), // "slotReadyRead"
QT_MOC_LITERAL(16, 243, 13), // "slotConnected"
QT_MOC_LITERAL(17, 257, 9), // "slotError"
QT_MOC_LITERAL(18, 267, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(19, 296, 12), // "slotExitUser"
QT_MOC_LITERAL(20, 309, 24), // "slotSendRegistrationData"
QT_MOC_LITERAL(21, 334, 5), // "login"
QT_MOC_LITERAL(22, 340, 8), // "password"
QT_MOC_LITERAL(23, 349, 25), // "slotSendAuthorizationData"
QT_MOC_LITERAL(24, 375, 13), // "slotAddDialog"
QT_MOC_LITERAL(25, 389, 5), // "title"
QT_MOC_LITERAL(26, 395, 16), // "slotDeleteDialog"
QT_MOC_LITERAL(27, 412, 15) // "slotSendMessage"

    },
    "Client\0signalInvalidData\0\0"
    "signalUserNameNotAvailable\0"
    "signalSuccessfulRegistration\0"
    "signalUserReceived\0User\0signalUserNotFound\0"
    "signalServerNotAvailable\0signalReceiveMessage\0"
    "mes\0sender\0destination\0signalAddDialog\0"
    "signalDeleteDialog\0slotReadyRead\0"
    "slotConnected\0slotError\0"
    "QAbstractSocket::SocketError\0slotExitUser\0"
    "slotSendRegistrationData\0login\0password\0"
    "slotSendAuthorizationData\0slotAddDialog\0"
    "title\0slotDeleteDialog\0slotSendMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Client[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    0,  105,    2, 0x06 /* Public */,
       4,    0,  106,    2, 0x06 /* Public */,
       5,    1,  107,    2, 0x06 /* Public */,
       7,    0,  110,    2, 0x06 /* Public */,
       8,    0,  111,    2, 0x06 /* Public */,
       9,    3,  112,    2, 0x06 /* Public */,
      13,    1,  119,    2, 0x06 /* Public */,
      14,    1,  122,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,  125,    2, 0x0a /* Public */,
      16,    0,  126,    2, 0x0a /* Public */,
      17,    1,  127,    2, 0x0a /* Public */,
      19,    0,  130,    2, 0x0a /* Public */,
      20,    2,  131,    2, 0x0a /* Public */,
      23,    2,  136,    2, 0x0a /* Public */,
      24,    1,  141,    2, 0x0a /* Public */,
      26,    1,  144,    2, 0x0a /* Public */,
      27,    2,  147,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   12,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   21,   22,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   21,   22,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   12,

       0        // eod
};

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalInvalidData(); break;
        case 1: _t->signalUserNameNotAvailable(); break;
        case 2: _t->signalSuccessfulRegistration(); break;
        case 3: _t->signalUserReceived((*reinterpret_cast< const User(*)>(_a[1]))); break;
        case 4: _t->signalUserNotFound(); break;
        case 5: _t->signalServerNotAvailable(); break;
        case 6: _t->signalReceiveMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 7: _t->signalAddDialog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->signalDeleteDialog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->slotReadyRead(); break;
        case 10: _t->slotConnected(); break;
        case 11: _t->slotError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 12: _t->slotExitUser(); break;
        case 13: _t->slotSendRegistrationData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 14: _t->slotSendAuthorizationData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 15: _t->slotAddDialog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->slotDeleteDialog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->slotSendMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalInvalidData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalUserNameNotAvailable)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalSuccessfulRegistration)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Client::*)(const User & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalUserReceived)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalUserNotFound)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalServerNotAvailable)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Client::*)(const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalReceiveMessage)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Client::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalAddDialog)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Client::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalDeleteDialog)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Client::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Client.data,
    qt_meta_data_Client,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Client.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void Client::signalInvalidData()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Client::signalUserNameNotAvailable()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Client::signalSuccessfulRegistration()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Client::signalUserReceived(const User & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Client::signalUserNotFound()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Client::signalServerNotAvailable()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Client::signalReceiveMessage(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Client::signalAddDialog(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Client::signalDeleteDialog(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
