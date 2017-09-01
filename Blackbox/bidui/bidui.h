#ifndef BIDUI_H
#define BIDUI_H

#include <QWidget>
#include <QGridLayout>
#include <QTextEdit>
#include <QTextCodec>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QPushButton>
#include <QCloseEvent>
#include <QMovie>
#include <QPainter>

class Bidui : public QWidget
{
  Q_OBJECT

public:
  Bidui(QWidget *parent = 0);
  virtual ~Bidui() {}

private:
  QTcpSocket *tcpSocket;
  QGridLayout *layout;
  QImage *image;
  //void closeEvent(QCloseEvent *event);

public slots:
  void recv_slot();
  void close_slot();

private slots:
  void receiveshow();
};

#endif // BIDUI_H
