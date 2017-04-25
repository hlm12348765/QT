#include <QtGui>
#include "training.h"

Training::Training(QWidget *parent) :QWidget(parent)
{
  textEdit = new QTextEdit();
  QLabel *label1 = new QLabel(this);
  QLabel *label2 = new QLabel("Training started !");
  label1 -> setPixmap(QPixmap("/opt/qt/logo.png"));
  layout = new QGridLayout();
  layout -> addWidget(label1,0,0,1,3);
  layout -> addWidget(textEdit,1,0,3,2);
  layout -> addWidget(label2,2,2,1,1);
  setLayout(layout);

  setWindowTitle(tr("SLAT2000"));
  setWindowFlags(Qt::WindowTitleHint);
  resize(480, 272);

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
  QByteArray byte;
  byte = tcpSocket -> readAll();
  textEdit -> setPlainText(QString(byte));
}

void Training::closeEvent(QCloseEvent *event)
{
  event -> ignore();
}
