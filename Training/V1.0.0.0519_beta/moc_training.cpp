/****************************************************************************
** Meta object code from reading C++ file 'training.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "training.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'training.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Training[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      20,    9,    9,    9, 0x0a,
      32,    9,    9,    9, 0x0a,
      47,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Training[] = {
    "Training\0\0dlgshow()\0recv_slot()\0"
    "connect_slot()\0receiveshow()\0"
};

void Training::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Training *_t = static_cast<Training *>(_o);
        switch (_id) {
        case 0: _t->dlgshow(); break;
        case 1: _t->recv_slot(); break;
        case 2: _t->connect_slot(); break;
        case 3: _t->receiveshow(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Training::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Training::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Training,
      qt_meta_data_Training, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Training::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Training::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Training::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Training))
        return static_cast<void*>(const_cast< Training*>(this));
    return QWidget::qt_metacast(_clname);
}

int Training::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Training::dlgshow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
