#include <QtGui>
#include "xuzhi.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  Xuzhi xzh;
  xzh.show();

  QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
  QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
  QFont font("WenQuanYi Micro Hei",12,QFont::Normal,FALSE);
  app.setFont(font);
  return app.exec();
}
