#include "mainwindow.h"
#include <QApplication>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Dialog dlg;
    dlg.show();
//信号与槽之间进行关联  
    QObject::connect(&dlg,SIGNAL(showmainwindow()),&w,SLOT(receivelogin()));  
    QObject::connect(&w,SIGNAL(dlgshow()),&dlg,SLOT(receiveshow()));  
    QObject::connect(&w,SIGNAL(quit()),&a,SLOT(quit()));  
    QObject::connect(&dlg,SIGNAL(quit()),&a,SLOT(quit()));  

    return a.exec();
}
