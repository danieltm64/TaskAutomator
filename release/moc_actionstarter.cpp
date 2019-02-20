/****************************************************************************
** Meta object code from reading C++ file 'actionstarter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../actionstarter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'actionstarter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ActionStarter_t {
    QByteArrayData data[15];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ActionStarter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ActionStarter_t qt_meta_stringdata_ActionStarter = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ActionStarter"
QT_MOC_LITERAL(1, 14, 16), // "do_remindTheUser"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "name"
QT_MOC_LITERAL(4, 37, 3), // "msg"
QT_MOC_LITERAL(5, 41, 16), // "do_visitAWebsite"
QT_MOC_LITERAL(6, 58, 7), // "address"
QT_MOC_LITERAL(7, 66, 12), // "do_openAFile"
QT_MOC_LITERAL(8, 79, 4), // "file"
QT_MOC_LITERAL(9, 84, 14), // "do_runAProgram"
QT_MOC_LITERAL(10, 99, 7), // "program"
QT_MOC_LITERAL(11, 107, 9), // "arguments"
QT_MOC_LITERAL(12, 117, 16), // "do_logTheUserOff"
QT_MOC_LITERAL(13, 134, 22), // "do_shutDownTheComputer"
QT_MOC_LITERAL(14, 157, 21) // "do_restartTheComputer"

    },
    "ActionStarter\0do_remindTheUser\0\0name\0"
    "msg\0do_visitAWebsite\0address\0do_openAFile\0"
    "file\0do_runAProgram\0program\0arguments\0"
    "do_logTheUserOff\0do_shutDownTheComputer\0"
    "do_restartTheComputer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ActionStarter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       5,    1,   54,    2, 0x06 /* Public */,
       7,    1,   57,    2, 0x06 /* Public */,
       9,    2,   60,    2, 0x06 /* Public */,
      12,    0,   65,    2, 0x06 /* Public */,
      13,    0,   66,    2, 0x06 /* Public */,
      14,    0,   67,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ActionStarter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ActionStarter *_t = static_cast<ActionStarter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->do_remindTheUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->do_visitAWebsite((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->do_openAFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->do_runAProgram((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->do_logTheUserOff(); break;
        case 5: _t->do_shutDownTheComputer(); break;
        case 6: _t->do_restartTheComputer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ActionStarter::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ActionStarter::do_remindTheUser)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ActionStarter::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ActionStarter::do_visitAWebsite)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ActionStarter::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ActionStarter::do_openAFile)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ActionStarter::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ActionStarter::do_runAProgram)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ActionStarter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ActionStarter::do_logTheUserOff)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ActionStarter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ActionStarter::do_shutDownTheComputer)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ActionStarter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ActionStarter::do_restartTheComputer)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ActionStarter::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_ActionStarter.data,
    qt_meta_data_ActionStarter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ActionStarter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ActionStarter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ActionStarter.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ActionStarter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void ActionStarter::do_remindTheUser(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ActionStarter::do_visitAWebsite(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ActionStarter::do_openAFile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ActionStarter::do_runAProgram(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ActionStarter::do_logTheUserOff()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ActionStarter::do_shutDownTheComputer()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ActionStarter::do_restartTheComputer()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
