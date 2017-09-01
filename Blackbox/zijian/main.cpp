#include <QtGui>
#include "zijian.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  Zijian zij;
  zij.show();
  
  QTranslator translator;
  translator.load("./qt_zh_CN.qm");
  app.installTranslator(&translator);

  //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
  //QFont font("WenQuanYi Micro Hei",12,QFont::Normal,FALSE);
  //app.setFont(font);
  return app.exec();
}
