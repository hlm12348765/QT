#ifndef ZIJIAN_H
#define ZIJIAN_H

#include <QWidget>
#include <QGridLayout>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QTextCodec>
#include <QCheckBox>
#include <QLabel>

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
  QCheckBox *checkbox1;
  QCheckBox *checkbox2;
  QCheckBox *checkbox3;
  QCheckBox *checkbox4;

signals:
  void c1show();

public slots:
  void recv_slot();
  void change_slot();

private slots:
  void receiveshow();
};

#endif // ZIJIAN_H
