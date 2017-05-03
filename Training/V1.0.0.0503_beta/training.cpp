//--------------------------------------------------------
//Title: Training Interface for SLAT2000
//Author: Bowen Nie
//Date completed: May 2nd
//Version 1.0.0.0502_beta
//--------------------------------------------------------
#include <QtGui>
#include "training.h"

Training::Training(QWidget *parent) :QWidget(parent)
{
  textEdit1 = new QTextEdit();
  textEdit2 = new QTextEdit();
  textEdit3 = new QTextEdit();
  QLabel *label1 = new QLabel(this);
  label1 -> setPixmap(QPixmap("/opt/qt/logo.png"));
  QLabel *label2 = new QLabel("Trained Project");
  QLabel *label3 = new QLabel("Trained Log");
  QLabel *label4 = new QLabel("Student information");
  layout = new QGridLayout();
  layout -> addWidget(label1,0,0,1,6);
  layout -> addWidget(label2,1,2,1,2);
  layout -> addWidget(label3,1,4,1,2);
  layout -> addWidget(label4,1,0,1,2);
  layout -> addWidget(textEdit1,2,0,2,2);
  layout -> addWidget(textEdit2,2,2,2,2);
  layout -> addWidget(textEdit3,2,4,2,2);
  setLayout(layout);

  setWindowTitle(tr("安徽三联SLAT2000"));
  setWindowFlags(Qt::WindowTitleHint);
  resize(480, 260);

  tcpSocket = new QTcpSocket(this);

  connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recv_slot()));
}

void Training::receiveshow()
{
  this -> show();
}

void Training::connect_slot()
{
  tcpSocket -> connectToHost("172.17.32.199",23);
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
}

void Training::closeEvent(QCloseEvent *event)
{
  event -> ignore();
}
