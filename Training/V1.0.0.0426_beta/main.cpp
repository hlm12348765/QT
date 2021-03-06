//--------------------------------------------------------
//Title: Training Interface for SLAT2000
//Author: Bowen Nie
//Date completed: April 26th
//Version 1.0.0.0426_beta
//--------------------------------------------------------
#include <QApplication>
#include <QTextCodec>
#include <QLabel>
#include "dialog.h"
#include "training.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  Training tra;
  Dialog dlg;
  dlg.show();

  QObject::connect(&dlg,SIGNAL(trashow()),&tra,SLOT(receiveshow()));
  QObject::connect(&dlg,SIGNAL(trashow()),&tra,SLOT(connect_slot()));
  QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));

  return app.exec();
}
