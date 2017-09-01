#include <QtGui>
#include "bidui.h"

Bidui::Bidui(QWidget *parent) :QWidget(parent)
{
  QLabel *label1 = new QLabel(this);
  label1 -> setPixmap(QPixmap("/opt/qt/logo1.png"));
  label1 -> setFixedSize(460,60);
  QLabel *label2 = new QLabel(tr("Renlianbidui"));
  //QImage *image;
  //image -> load("/opt/qt/wuxi_logo.png");
  //QPainter *painter;
  //painter -> drawImage(0,0,*image);
  image = new QImage("/opt/qt/wuxi_logo.png");
  QLabel *label3 = new QLabel(this);
  label3 -> setPixmap(QPixmap::fromImage(*image));
  layout = new QGridLayout();
  layout -> addWidget(label1,0,0,2,12);
  layout -> addWidget(label2,1,0,1,12);
  layout -> addWidget(label3,2,0,3,12);

  this -> setLayout(layout);
  setWindowTitle(tr("Blackbox"));
  resize(480,272);

  tcpSocket = new QTcpSocket(this);
  tcpSocket -> connectToHost("192.168.1.133",6666);

  connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recv_slot()));
  connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(close_slot()));
}

void Bidui::receiveshow()
{
  this -> show();
}

void Bidui::recv_slot()
{
  QString str1;
  str1 = tcpSocket -> readAll();
  int i = str1.indexOf("change");
  if (i!=-1)
  {
    image -> load("/opt/qt/logo1.png");
  }
}

//void Bidui::closeEvent(QCloseEvent *event)
void Bidui::close_slot()
{
  QString str2;
  str2 = tcpSocket -> readAll();
  int n = str2.indexOf("close");
  if (n!=-1)
  {
  this -> hide();
  }
}
