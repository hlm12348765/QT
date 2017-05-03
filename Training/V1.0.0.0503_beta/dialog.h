//--------------------------------------------------------
//Title: Training Interface for SLAT2000
//Author: Bowen Nie
//Date completed: May 2nd
//Version 1.0.0.0502_beta
//--------------------------------------------------------
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QGridLayout>
#include <QPushButton>
#include <QTextCodec>

class Dialog : public QDialog
{
  Q_OBJECT

public:
  Dialog(QWidget *parent = 0);
  virtual ~Dialog() {}

private:
  QGridLayout *layout;
  QPushButton *loginButton;
  QTcpSocket *tcpSocket;
  void closeEvent(QCloseEvent *event);

signals:
  void showmainwindow();
  void trashow();

public slots:
  void finish_slot();
  void connect_slot();

private slots:
  void receiveshow();
};

#endif // DIALOG_H
