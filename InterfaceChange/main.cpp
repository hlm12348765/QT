#include "mainwindow.h"
#include <QApplication>
#include "dialog.h"
#include <QLabel>
#include "training.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Training tra;
    Dialog dlg;
    dlg.show();
//信号与槽之间进行关联  
    QObject::connect(&dlg,SIGNAL(showmainwindow()),&w,SLOT(receivelogin()));  
    QObject::connect(&w,SIGNAL(dlgshow()),&dlg,SLOT(receiveshow()));  
    QObject::connect(&w,SIGNAL(trashow()),&tra,SLOT(receiveshow()));
 //   QObject::connect(&dlg,SIGNAL(quit()),&a,SLOT(quit()));
 //     QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
    return a.exec();
}
