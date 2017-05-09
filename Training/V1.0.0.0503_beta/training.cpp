//--------------------------------------------------------
//Title: Training Interface for SLAT2000
//Author: Bowen Nie
//Date completed: May 3rd
//Version 1.0.0.0503_beta
//--------------------------------------------------------
#include <QtGui>
#include "training.h"

Training::Training(QWidget *parent) :QWidget(parent)
{
  textEdit1 = new QTextEdit(this);
  textEdit2 = new QTextEdit(this);
  textEdit3 = new QTextEdit(this);
  QLabel *label1 = new QLabel(this);
  label1 -> setPixmap(QPixmap("/opt/qt/logo.png"));
  QLabel *label2 = new QLabel(this);
  label2 -> setPixmap(QPixmap("/opt/picture/image_jpg.jpg"));
  layout = new QGridLayout();
  layout -> addWidget(label1,0,0,1,6);
  layout -> addWidget(label2,1,0,3,2);
  layout -> addWidget(textEdit1,1,2,1,4);
  layout -> addWidget(textEdit2,2,2,1,4);
  layout -> addWidget(textEdit3,3,2,1,4);
  setLayout(layout);

  setWindowTitle(tr("SLAT2000"));
  setWindowFlags(Qt::FramelessWindowHint);
  resize(480, 272);

  tcpSocket = new QTcpSocket(this);

  connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recv_slot()));
  connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(reconnect_slot()));
}

void Training::receiveshow()
{
  this -> show();
}

void Training::connect_slot()
{
  tcpSocket -> connectToHost("192.168.200.252",6666);
}

void Training::recv_slot()
{
  QString byte;
  byte = tcpSocket -> readAll();
  QString str1;
  QString str2;
  QString str3;
  if (byte.startsWith("$ks") && byte.endsWith("$js"))
  {
    str1 = byte.section(";",1,1);
    str2 = byte.section(";",2,2);
    str3 = byte.section(";",3,3);
    textEdit1 -> setPlainText(QString(str1));
    textEdit2 -> setPlainText(QString(str2));
    textEdit3 -> setPlainText(QString(str3));
  }
  int i = byte.indexOf("finish");
  if (i!=-1)
  {
    textEdit1 -> setPlainText(" ");
    textEdit2 -> setPlainText(" ");
    textEdit3 -> setPlainText(" ");
    this -> hide();
    emit dlgshow();
  }
}

void Training::reconnect_slot()
{
  tcpSocket -> connectToHost("192.168.200.252",6666);
}

void Training::closeEvent(QCloseEvent *event)
{
  event -> ignore();
}
