#include <QtGui>
#include "dialog.h"

Dialog::Dialog(QWidget *parent) :QDialog(parent)
{
  loginButton = new QPushButton("login");
  QLabel *label1 = new QLabel(this);
  QLabel *label2 = new QLabel("Welcome training !");
  label1 -> setPixmap(QPixmap("/opt/qt/logo.png"));
  layout = new QGridLayout();
  layout -> addWidget(label1,0,0,1,3);
  layout -> addWidget(label2,1,1,1,1);
  layout -> addWidget(loginButton,2,1,1,1);
  setLayout(layout);

  setWindowTitle(tr("SLAT2000"));
  setWindowFlags(Qt::WindowTitleHint);
  resize(480, 272);

  tcpSocket = new QTcpSocket(this);

  connect(loginButton,SIGNAL(clicked()),this,SLOT(connect_slot()));
  connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(finish_slot()));
}

void Dialog::receiveshow()
{
  this -> show();
}

void Dialog::connect_slot()
{
  tcpSocket -> connectToHost("172.17.32.199",22);
}

void Dialog::finish_slot()
{
  this -> hide();
  emit trashow();
}

void Dialog::closeEvent(QCloseEvent *event)
{
  event -> ignore();
}
