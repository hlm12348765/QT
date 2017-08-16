#include <QtGui>
#include "zijian.h"

Zijian::Zijian(QWidget *parent) :QWidget(parent)
{
  QLabel *label1 = new QLabel(this);
  label1 -> setPixmap(QPixmap("/opt/qt/logo1.png"));
  label1 -> setFixedSize(460,60);
  //label1 -> show();
  QLabel *label2 = new QLabel(tr("自检Shebeizijian"));
  QLabel *label3 = new QLabel(tr("Anquandai"));
  QLabel *label4 = new QLabel(tr("Shousha"));
  QLabel *label5 = new QLabel(tr("Lihe"));
  QLabel *label6 = new QLabel(tr("Chemen"));
  QCheckBox *checkbox1 = new QCheckBox(this);
  QCheckBox *checkbox2 = new QCheckBox(this);
  QCheckBox *checkbox3 = new QCheckBox(this);
  QCheckBox *checkbox4 = new QCheckBox(this);
  checkbox1 -> setTristate();
  checkbox2 -> setTristate();
  checkbox3 -> setTristate();
  checkbox4 -> setTristate();
  layout = new QGridLayout();
  layout -> addWidget(label1,0,0,2,12);
  layout -> addWidget(label2,2,0,1,12);
  layout -> addWidget(label3,3,0,1,6);
  layout -> addWidget(label4,4,0,1,6);
  layout -> addWidget(label5,5,0,1,6);
  layout -> addWidget(label6,6,0,1,6);
  layout -> addWidget(checkbox1,3,6,1,6);
  layout -> addWidget(checkbox2,4,6,1,6);
  layout -> addWidget(checkbox3,5,6,1,6);
  layout -> addWidget(checkbox4,6,6,1,6);
  this -> setLayout(layout);
  setWindowTitle(tr("Blackbox"));
  resize(480,272);

  tcpSocket = new QTcpSocket(this);
  tcpSocket -> connectToHost("192.168.1.133",6666);

  connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recv_slot()));
  connect(this,SIGNAL(c1show()),this,SLOT(change_slot()));
}

void Zijian::receiveshow()
{
  this -> show();
}

void Zijian::recv_slot()
{
  QString byte;
  byte = tcpSocket ->readAll();
  int i = byte.indexOf("anquandai");
  if (i!=-1)
  {
    emit c1show();
    //checkbox1 -> setCheckState(Qt::PartiallyChecked);
  }
  int n = byte.indexOf("aqd");
  if(n!=-1)
  {
    checkbox1 -> setChecked(true);
  }
}

void Zijian::change_slot()
{
  checkbox1 -> setCheckState(Qt::PartiallyChecked);
}
