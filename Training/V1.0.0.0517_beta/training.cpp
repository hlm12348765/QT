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
  textEdit4 = new QTextEdit(this);
  textEdit5 = new QTextEdit(this);
  textEdit6 = new QTextEdit(this);
  QLabel *label1 = new QLabel(this);
  label1 -> setPixmap(QPixmap("/opt/qt/logo1.png"));
  QLabel *label2 = new QLabel("请刷卡完成训练");
  //label2 -> setPixmap(QPixmap("/opt/picture/image_jpg.png"));
  QLabel *label3 = new QLabel("学员姓名：");
  QLabel *label4 = new QLabel("学员编号：");
  QLabel *label5 = new QLabel("预约学时：");
  QLabel *label6 = new QLabel("开始时间：");
  QLabel *label7 = new QLabel("剩余学时：");
  QLabel *label8 = new QLabel("（单位：小时）");
  QLabel *label9 = new QLabel("已训练项目");
  QLabel *label10 = new QLabel("训练日志");
  QLabel *label11 = new QLabel("时");
  QLabel *label12 = new QLabel("分");
  QListView *listview1 = new QListView(this);
  QListView *listview2 = new QListView(this);
  layout = new QGridLayout();
  layout -> addWidget(label1,0,0,1,12);
  layout -> addWidget(label2,1,0,1,6);
  layout -> addWidget(label3,2,0,1,2);
  layout -> addWidget(label4,3,0,1,2);
  layout -> addWidget(label5,4,0,1,2);
  layout -> addWidget(label6,5,0,1,2);
  layout -> addWidget(label7,6,0,1,2);
  layout -> addWidget(label8,4,3,1,3);
  layout -> addWidget(label9,1,6,1,6);
  layout -> addWidget(label10,4,6,1,6);
  layout -> addWidget(label11,6,3,1,1);
  layout -> addWidget(label12,6,5,1,1);
  layout -> addWidget(textEdit1,2,2,1,4);
  layout -> addWidget(textEdit2,3,2,1,4);
  layout -> addWidget(textEdit3,4,2,1,1);
  layout -> addWidget(textEdit4,5,2,1,4);
  layout -> addWidget(textEdit5,6,2,1,1);
  layout -> addWidget(textEdit6,6,4,1,1);
  layout -> addWidget(listview1,2,6,2,6);
  layout -> addWidget(listview2,5,6,2,6);
  setLayout(layout);

  setWindowTitle(tr("SLAT2000"));
  setWindowFlags(Qt::FramelessWindowHint);
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
  tcpSocket -> connectToHost("192.168.200.244",6666);
}

void Training::recv_slot()
{
  QString byte;
  byte = tcpSocket -> readAll();
  QString str1;
  QString str2;
  QString str3;
  QString str4;
  QString str5;
  if (byte.startsWith("$ks") && byte.endsWith("$js"))
  {
    str1 = byte.section(";",1,1);
    str2 = byte.section(";",2,2);
    str3 = byte.section(";",3,3);
    str4 = byte.section(";",4,4);
    str5 = byte.section(";",5,5);
    textEdit1 -> setPlainText(QString(str1));
    textEdit2 -> setPlainText(QString(str2));
    textEdit3 -> setPlainText(QString(str3));
    textEdit5 -> setPlainText(QString(str4));
    textEdit6 -> setPlainText(QString(str5));
    listview
  }
  int i = byte.indexOf("finish");
  if (i!=-1)
  {
    textEdit1 -> setPlainText(" ");
    textEdit2 -> setPlainText(" ");
    textEdit3 -> setPlainText(" ");
    textEdit4 -> setPlainText(" ");
    textEdit5 -> setPlainText(" ");
    this -> hide();
    emit dlgshow();
  }
}

void Training::closeEvent(QCloseEvent *event)
{
  event -> ignore();
}
