//--------------------------------------------------------
//Title: Examing Interface for Blackbox
//Author: Bowen Nie
//Date completed: August 7th
//Version 1.0.0.0807_beta
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
  QTcpSocket *tcpSocket;
  QPushButton *loginButton;
  void closeEvent(QCloseEvent *event);

signals:
  void trashow();

public slots:
  void finish_slot();
  void login_slot();

private slots:
  void receiveshow();
};

#endif // DIALOG_H
