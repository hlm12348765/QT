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
  QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
  QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
  QFont font("WenQuanYi Micro Hei",11,QFont::Normal,FALSE);
  app.setFont(font);
  return app.exec();
}
