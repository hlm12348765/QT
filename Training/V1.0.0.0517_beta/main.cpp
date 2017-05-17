//--------------------------------------------------------
//Title: Training Interface for SLAT2000
//Author: Bowen Nie
//Date completed: May 3rd
//Version 1.0.0.0503_beta
//--------------------------------------------------------
#include <QtGui>
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
  QObject::connect(&tra,SIGNAL(dlgshow()),&dlg,SLOT(receiveshow()));
  QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
  QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
  QFont font("WenQuanYi Micro Hei",12,QFont::Normal,FALSE);
  app.setFont(font);
  return app.exec();
}
