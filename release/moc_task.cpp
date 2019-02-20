/****************************************************************************
** Meta object code from reading C++ file 'task.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../task.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'task.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Task_t {
    QByteArrayData data[21];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Task_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Task_t qt_meta_stringdata_Task = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Task"
QT_MOC_LITERAL(1, 5, 21), // "nextOccurrenceUpdated"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "nameUpdated"
QT_MOC_LITERAL(4, 40, 8), // "finished"
QT_MOC_LITERAL(5, 49, 16), // "do_remindTheUser"
QT_MOC_LITERAL(6, 66, 8), // "taskName"
QT_MOC_LITERAL(7, 75, 3), // "msg"
QT_MOC_LITERAL(8, 79, 16), // "do_visitAWebsite"
QT_MOC_LITERAL(9, 96, 7), // "address"
QT_MOC_LITERAL(10, 104, 12), // "do_openAFile"
QT_MOC_LITERAL(11, 117, 8), // "taskFile"
QT_MOC_LITERAL(12, 126, 14), // "do_runAProgram"
QT_MOC_LITERAL(13, 141, 11), // "taskProgram"
QT_MOC_LITERAL(14, 153, 13), // "taskArguments"
QT_MOC_LITERAL(15, 167, 16), // "do_logTheUserOff"
QT_MOC_LITERAL(16, 184, 22), // "do_shutDownTheComputer"
QT_MOC_LITERAL(17, 207, 21), // "do_restartTheComputer"
QT_MOC_LITERAL(18, 229, 10), // "performNow"
QT_MOC_LITERAL(19, 240, 20), // "updateNextOccurrence"
QT_MOC_LITERAL(20, 261, 19) // "updateTaskListEntry"

    },
    "Task\0nextOccurrenceUpdated\0\0nameUpdated\0"
    "finished\0do_remindTheUser\0taskName\0"
    "msg\0do_visitAWebsite\0address\0do_openAFile\0"
    "taskFile\0do_runAProgram\0taskProgram\0"
    "taskArguments\0do_logTheUserOff\0"
    "do_shutDownTheComputer\0do_restartTheComputer\0"
    "performNow\0updateNextOccurrence\0"
    "updateTaskListEntry"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Task[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   82,    2, 0x0a /* Public */,
       8,    1,   87,    2, 0x0a /* Public */,
      10,    1,   90,    2, 0x0a /* Public */,
      12,    2,   93,    2, 0x0a /* Public */,
      15,    0,   98,    2, 0x0a /* Public */,
      16,    0,   99,    2, 0x0a /* Public */,
      17,    0,  100,    2, 0x0a /* Public */,
      18,    0,  101,    2, 0x0a /* Public */,
      19,    0,  102,    2, 0x0a /* Public */,
      20,    0,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Task::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Task *_t = static_cast<Task *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nextOccurrenceUpdated(); break;
        case 1: _t->nameUpdated(); break;
        case 2: _t->finished(); break;
        case 3: _t->do_remindTheUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->do_visitAWebsite((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->do_openAFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->do_runAProgram((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->do_logTheUserOff(); break;
        case 8: _t->do_shutDownTheComputer(); break;
        case 9: _t->do_restartTheComputer(); break;
        case 10: _t->performNow(); break;
        case 11: _t->updateNextOccurrence(); break;
        case 12: _t->updateTaskListEntry(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Task::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Task::nextOccurrenceUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Task::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Task::nameUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Task::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Task::finished)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Task::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Task.data,
    qt_meta_data_Task,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Task::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Task::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Task.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Task::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Task::nextOccurrenceUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Task::nameUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Task::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
