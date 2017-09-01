#ifndef ZIJIAN_H
#define ZIJIAN_H

#include <QWidget>
#include <QGridLayout>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QLineEdit>
#include <QTextCodec>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QPalette>

class Zijian : public QWidget
{
  Q_OBJECT

public:
  Zijian(QWidget *parent = 0);
  virtual ~Zijian() {}

private:
  QTcpSocket *tcpSocket;
  QGridLayout *layout;
  QLabel *label1;
  QLabel *label2;
  QLabel *label3;
  QLabel *label4;
  QLabel *label5;
  QLabel *label6;
  QPushButton *aqdbutton;
  QPushButton *ssbutton;
  QPushButton *lhbutton;
  QPushButton *cmbutton;
  void setAlignment(Qt::AlignmentFlag); 

public slots:
  void recv_slot();

private slots:
  void receiveshow();
};

#endif // ZIJIAN_H
