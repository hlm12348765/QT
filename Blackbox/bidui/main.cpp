#include <QtGui>
#include "bidui.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  Bidui bid;
  bid.show();

  return app.exec();
}
