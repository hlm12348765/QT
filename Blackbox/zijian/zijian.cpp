#include <QtGui>
#include "zijian.h"

Zijian::Zijian(QWidget *parent) :QWidget(parent)
{
  QLabel *label1 = new QLabel(this);
  label1 -> setPixmap(QPixmap("/opt/qt/logo1.png"));
  label1 -> setFixedSize(460,60);
  //label1 -> show();
  QLabel *label2 = new QLabel(tr("Shebeizijian"));
  QLabel *label3 = new QLabel(tr("Anquandai"));
  QLabel *label4 = new QLabel(tr("Shousha"));
  QLabel *label5 = new QLabel(tr("Lihe"));
  QLabel *label6 = new QLabel(tr("Chemen"));
  label2 -> setAlignment(Qt::AlignHCenter);
  label3 -> setAlignment(Qt::AlignHCenter);
  label4 -> setAlignment(Qt::AlignHCenter);
  label5 -> setAlignment(Qt::AlignHCenter);
  label6 -> setAlignment(Qt::AlignHCenter);
  aqdbutton = new QPushButton(tr("waiting"));
  ssbutton = new QPushButton(tr("waiting"));
  lhbutton = new QPushButton(tr("waiting"));
  cmbutton = new QPushButton(tr("waiting"));
  aqdbutton -> setEnabled(false);
  ssbutton -> setEnabled(false);
  lhbutton -> setEnabled(false);
  cmbutton -> setEnabled(false);
  layout = new QGridLayout();
  layout -> addWidget(label1,0,0,2,12);
  layout -> addWidget(label2,2,3,1,6);
  layout -> addWidget(label3,3,0,1,6);
  layout -> addWidget(label4,4,0,1,6);
  layout -> addWidget(label5,5,0,1,6);
  layout -> addWidget(label6,6,0,1,6);
  layout -> addWidget(aqdbutton,3,6,1,6);
  layout -> addWidget(ssbutton,4,6,1,6);
  layout -> addWidget(lhbutton,5,6,1,6);
  layout -> addWidget(cmbutton,6,6,1,6);
  this -> setLayout(layout);
  setWindowTitle(tr("Blackbox"));
  resize(480,272);

  tcpSocket = new QTcpSocket(this);
  tcpSocket -> connectToHost("172.17.32.133",6666);

  connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recv_slot()));
}

void Zijian::receiveshow()
{
  this -> show();
}

void Zijian::recv_slot()
{
  QPalette pal_aqd = aqdbutton -> palette();
  QPalette pal_ss = ssbutton -> palette();
  QPalette pal_lh = lhbutton -> palette();
  QPalette pal_cm = cmbutton -> palette();
  QString byte;
  byte = tcpSocket ->readAll();
  int i1 = byte.indexOf("anquandai");
  if (i1!=-1)
  {
    aqdbutton -> setText("checking");
  }
  int n1 = byte.indexOf("aqd");
  if(n1!=-1)
  {
    aqdbutton -> setText("checked");
    aqdbutton -> setEnabled(true);
    pal_aqd.setColor(QPalette::Button,Qt::green);
    aqdbutton -> setPalette(pal_aqd);
    aqdbutton -> setAutoFillBackground(true);
    aqdbutton -> setFlat(true);
  }
  int i2 = byte.indexOf("shousha");
  if (i2!=-1)
  {
    ssbutton -> setText("checking");
  }
  int n2 = byte.indexOf("ss");
  if(n2!=-1)
  {
    ssbutton -> setText("checked");
    ssbutton -> setEnabled(true);
    pal_ss.setColor(QPalette::Button,Qt::green);
    ssbutton -> setPalette(pal_ss);
    ssbutton -> setAutoFillBackground(true);
    ssbutton -> setFlat(true);
  }
  int i3 = byte.indexOf("lihe");
  if (i3!=-1)
  {
    lhbutton -> setText("checking");
  }
  int n3 = byte.indexOf("lh");
  if(n3!=-1)
  {
    lhbutton -> setText("checked");
    lhbutton -> setEnabled(true);
    pal_lh.setColor(QPalette::Button,Qt::green);
    lhbutton -> setPalette(pal_lh);
    lhbutton -> setAutoFillBackground(true);
    lhbutton -> setFlat(true);
  }
  int i4 = byte.indexOf("chemen");
  if (i4!=-1)
  {
    cmbutton -> setText("checking");
  }
  int n4 = byte.indexOf("cm");
  if(n4!=-1)
  {
    cmbutton -> setText("checked");
    cmbutton -> setEnabled(true);
    pal_cm.setColor(QPalette::Button,Qt::green);
    cmbutton -> setPalette(pal_cm);
    cmbutton -> setAutoFillBackground(true);
    cmbutton -> setFlat(true);
  }
}
