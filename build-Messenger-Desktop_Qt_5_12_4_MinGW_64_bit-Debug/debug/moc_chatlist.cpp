/****************************************************************************
** Meta object code from reading C++ file 'chatlist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Messenger(source)/ChatList/chatlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChatList_t {
    QByteArrayData data[15];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatList_t qt_meta_stringdata_ChatList = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ChatList"
QT_MOC_LITERAL(1, 9, 7), // "clicked"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 7), // "deleted"
QT_MOC_LITERAL(4, 26, 12), // "appendDialog"
QT_MOC_LITERAL(5, 39, 5), // "title"
QT_MOC_LITERAL(6, 45, 4), // "text"
QT_MOC_LITERAL(7, 50, 8), // "upDialog"
QT_MOC_LITERAL(8, 59, 7), // "newText"
QT_MOC_LITERAL(9, 67, 11), // "changeTitle"
QT_MOC_LITERAL(10, 79, 8), // "newTitle"
QT_MOC_LITERAL(11, 88, 10), // "changeText"
QT_MOC_LITERAL(12, 99, 10), // "hideDialog"
QT_MOC_LITERAL(13, 110, 10), // "showDialog"
QT_MOC_LITERAL(14, 121, 11) // "showDialogs"

    },
    "ChatList\0clicked\0\0deleted\0appendDialog\0"
    "title\0text\0upDialog\0newText\0changeTitle\0"
    "newTitle\0changeText\0hideDialog\0"
    "showDialog\0showDialogs"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatList[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   70,    2, 0x0a /* Public */,
       7,    1,   75,    2, 0x0a /* Public */,
       7,    2,   78,    2, 0x0a /* Public */,
       9,    2,   83,    2, 0x0a /* Public */,
      11,    2,   88,    2, 0x0a /* Public */,
      12,    1,   93,    2, 0x0a /* Public */,
      13,    1,   96,    2, 0x0a /* Public */,
      14,    0,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    8,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

       0        // eod
};

void ChatList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChatList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->deleted((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->appendDialog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->upDialog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->upDialog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->changeTitle((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->changeText((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->hideDialog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->showDialog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->showDialogs(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChatList::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatList::clicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ChatList::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatList::deleted)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChatList::staticMetaObject = { {
    &QScrollArea::staticMetaObject,
    qt_meta_stringdata_ChatList.data,
    qt_meta_data_ChatList,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChatList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChatList.stringdata0))
        return static_cast<void*>(this);
    return QScrollArea::qt_metacast(_clname);
}

int ChatList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ChatList::clicked(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChatList::deleted(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE