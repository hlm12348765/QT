#include <QApplication>
#include <QTextCodec>
#include <QLabel>
#include "dialog.h"
#include "training.h"

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
