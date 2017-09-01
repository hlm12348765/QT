#include <QtGui>
#include "xuzhi.h"

Xuzhi::Xuzhi(QWidget *parent) :QWidget(parent)
{
  QLabel *label1 = new QLabel(this);
  label1 -> setPixmap(QPixmap("/opt/qt/logo1.png"));
  label1 -> setFixedSize(460,60);
  QLabel *label2 = new QLabel(tr("Kaoshengxuzhi"));
  label2 -> setAlignment(Qt::AlignHCenter);
  QLabel *label3 = new QLabel(tr("IP Address"));
  QLabel *label4 = new QLabel(tr("MAC Address"));
  QLabel *label5 = new QLabel(tr("Version"));
  QLabel *label6 = new QLabel(tr("Release Date"));
  QLabel *label7 = new QLabel(tr("Please press the startbutton to start exam"));
  loginButton = new QPushButton(tr("Start"));
  textEdit1 = new QLineEdit(this);
  textEdit2 = new QLineEdit(this);
  textEdit3 = new QLineEdit(this);
  textEdit4 = new QLineEdit(this);
  textEdit1 -> setReadOnly(true);
  textEdit2 -> setReadOnly(true);
  textEdit3 -> setReadOnly(true);
  textEdit4 -> setReadOnly(true);
  layout = new QGridLayout();
  layout -> addWidget(label1,0,0,2,12);
  layout -> addWidget(label2,2,0,1,12);
  layout -> addWidget(label3,3,0,1,3);
  layout -> addWidget(label4,4,0,1,3);
  layout -> addWidget(label5,5,0,1,3);
  layout -> addWidget(label6,3,6,1,3);
  layout -> addWidget(label7,4,6,1,6);
  layout -> addWidget(textEdit1,3,3,1,3);
  layout -> addWidget(textEdit2,4,3,1,3);
  layout -> addWidget(textEdit3,5,3,1,3);
  layout -> addWidget(textEdit4,3,9,1,3);
  layout -> addWidget(loginButton,5,6,1,6);

  this -> setLayout(layout);
  setWindowTitle(tr("Blackbox"));
  setWindowFlags(Qt::FramelessWindowHint);
  resize(480,272);

  tcpSocket = new QTcpSocket(this);
  tcpSocket -> connectToHost("172.17.32.133",6666);

  connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recv_slot()));
}

void Xuzhi::receiveshow()
{
  this -> show();
}

void Xuzhi::recv_slot()
{
  QString byte;
  byte = tcpSocket -> readAll();
  QString str1;
  QString str2;
  QString str3;
  QString str4;
  if (byte.startsWith("$ks") && byte.endsWith("$js"))
  {
    str1 = byte.section(";",1,1);
    str2 = byte.section(";",2,2);
    str3 = byte.section(";",3,3);
    str4 = byte.section(";",4,4);
    textEdit1 -> setText(QString(str1));
    textEdit2 -> setText(QString(str2));
    textEdit3 -> setText(QString(str3));
    textEdit4 -> setText(QString(str4));
  }
}

void Xuzhi::closeEvent(QCloseEvent *event)
{
  event -> ignore();
}
