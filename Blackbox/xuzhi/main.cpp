#include <QtGui>
#include "xuzhi.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  Xuzhi xzh;
  xzh.show();

  QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
  QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
  QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
  QFont font("WenQuanYi Micro Hei",12,QFont::Normal,FALSE);
  app.setFont(font);
  return app.exec();
}
