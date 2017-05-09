//--------------------------------------------------------
//Title: Training Interface for SLAT2000
//Author: Bowen Nie
//Date completed: May 3rd
//Version 1.0.0.0503_beta
//--------------------------------------------------------
#include <QtGui>
#include "dialog.h"

Dialog::Dialog(QWidget *parent) :QDialog(parent)
{
  QLabel *label1 = new QLabel(this);
  label1 -> setPixmap(QPixmap("/opt/qt/logo.png"));
  QLabel *label2 = new QLabel(this);
  label2 -> setPixmap(QPixmap("/opt/qt/huanying.png"));
  layout = new QGridLayout();
  layout -> addWidget(label1,0,0,1,3);
  layout -> addWidget(label2,2,1,1,1);
  setLayout(layout);

  setWindowTitle(tr("SLAT2000"));
  setWindowFlags(Qt::FramelessWindowHint);
  resize(480, 272);

  tcpSocket = new QTcpSocket();
  tcpSocket -> connectToHost("192.168.200.252",6666);

  connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(finish_slot()));
  connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(reconnect_slot()));
}

void Dialog::receiveshow()
{
  this -> show();
}

void Dialog::finish_slot()
{
  QString str;
  str = tcpSocket -> readAll();
  int i = str.indexOf("start");
  if (i!=-1)
  {
    this -> hide();
    emit trashow();
  }
}

void Dialog::reconnect_slot()
{
  tcpSocket -> connectToHost("192.168.200.252",6666);
}

void Dialog::closeEvent(QCloseEvent *event)
{
  event -> ignore();
}
