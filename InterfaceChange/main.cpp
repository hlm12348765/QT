#include <QApplication>
#include "dialog.h"
#include <QLabel>
#include "training.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    Training tra;
    Dialog dlg;
    dlg.show();

    //QObject::connect(&dlg,SIGNAL(showmainwindow()),&w,SLOT(receivelogin()));
    //QObject::connect(&w,SIGNAL(dlgshow()),&dlg,SLOT(receiveshow()));
    QObject::connect(&dlg,SIGNAL(trashow()),&tra,SLOT(receiveshow()));
    QObject::connect(&dlg,SIGNAL(recv_start()),&tra,SLOT(recv_slot()));
    //QObject::connect(&dlg,SIGNAL(quit()),&a,SLOT(quit()));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    return a.exec();
}
