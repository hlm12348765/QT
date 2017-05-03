//--------------------------------------------------------
//Title: Training Interface for SLAT2000
//Author: Bowen Nie
//Date completed: May 3rd
//Version 1.0.0.0503_beta
//--------------------------------------------------------
#ifndef TRAINING_H
#define TRAINING_H

#include <QWidget>
#include <QCloseEvent>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QGridLayout>
#include <QTextEdit>
#include <QTextCodec>

class Training : public QWidget
{
  Q_OBJECT

public:
  Training(QWidget *parent = 0);
  virtual ~Training() {}

private:
  QTcpSocket *tcpSocket;
  QGridLayout *layout;
  QTextEdit *textEdit1;
  QTextEdit *textEdit2;
  QTextEdit *textEdit3;
  void closeEvent(QCloseEvent *event);

public slots:
  void recv_slot();
  void connect_slot();

private slots:
  void receiveshow();
};

#endif // TRAINING_H
