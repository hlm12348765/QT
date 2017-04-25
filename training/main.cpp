#include <QApplication>
#include "dialog.h"
#include <QLabel>
#include "training.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Training tra;
    Dialog dlg;
    dlg.show();

    QObject::connect(&dlg,SIGNAL(trashow()),&tra,SLOT(receiveshow()));
    QObject::connect(&dlg,SIGNAL(trashow()),&tra,SLOT(connect_slot()));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    return a.exec();
}
