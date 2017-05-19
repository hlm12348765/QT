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
  //textEdit6 = new QTextEdit(this);
  QLabel *label1 = new QLabel(this);
  label1 -> setPixmap(QPixmap("/opt/qt/logo1.png"));
  label1 -> setFixedSize(460, 60);
  QLabel *label2 = new QLabel(tr("Credit card to complete the training"));
  //label2 -> setPixmap(QPixmap("/opt/picture/image_jpg.png"));
  QLabel *label3 = new QLabel(tr("Student Name"));
  QLabel *label4 = new QLabel(tr("Student Number"));
  QLabel *label5 = new QLabel(tr("Appointment Hours"));
  QLabel *label6 = new QLabel(tr("Starting Time"));
  QLabel *label7 = new QLabel(tr("Remaining Time"));
  QLabel *label8 = new QLabel(this);
  label8 -> setText(QString("小时"));
  QLabel *label9 = new QLabel(tr("Trained Project"));
  QLabel *label10 = new QLabel(tr("Training Log"));
  QLabel *label11 = new QLabel(this);
  QLabel *label12 = new QLabel(this);
  QLabel *label13 = new QLabel(this);
  QLabel *label14 = new QLabel(this);
  QLabel *label15 = new QLabel(this);
  QListView *listview1 = new QListView(this);
  QListView *listview2 = new QListView(this);
  layout = new QGridLayout();
  layout -> addWidget(label1,0,0,1,12);
  layout -> addWidget(label2,1,0,1,4);
  layout -> addWidget(label3,2,0,1,2);
  layout -> addWidget(label4,3,0,1,2);
  layout -> addWidget(label5,4,0,1,2);
  layout -> addWidget(label6,5,0,1,2);
  layout -> addWidget(label7,6,0,1,2);
  layout -> addWidget(label8,4,3,1,1);
  layout -> addWidget(label9,1,4,1,6);
  layout -> addWidget(label10,4,4,1,6);
  layout -> addWidget(label11,2,4,1,2);
  layout -> addWidget(label12,3,4,1,2);
  layout -> addWidget(label13,4,4,1,2);
  layout -> addWidget(label14,5,4,1,2);
  layout -> addWidget(label15,6,3,1,2);
  layout -> addWidget(textEdit1,2,2,1,2);
  layout -> addWidget(textEdit2,3,2,1,2);
  layout -> addWidget(textEdit3,4,2,1,1);
  layout -> addWidget(textEdit4,5,2,1,2);
  layout -> addWidget(textEdit5,6,2,1,1);
  //layout -> addWidget(textEdit6,6,4,1,1);
  layout -> addWidget(listview1,2,6,2,6);
  layout -> addWidget(listview2,5,6,2,6);
  this -> setLayout(layout);

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
  QString str6;
  if (byte.startsWith("$ks") && byte.endsWith("$js"))
  {
    str1 = byte.section(";",1,1);
    str2 = byte.section(";",2,2);
    str3 = byte.section(";",3,3);
    str5 = byte.section(";",4,4);
    QDateTime time = QDateTime::currentDateTime();
    str4 = time.toString("yyyy-MM-dd hh:mm:ss ddd");
    textEdit1 -> setPlainText(QString(str1));
    textEdit2 -> setPlainText(QString(str2));
    textEdit3 -> setPlainText(QString(str3));
    textEdit4 -> setPlainText(QString(str4));
    textEdit5 -> setPlainText(QString(str5));
    //textEdit6 -> setPlainText(QString(str5));
    //listview1 -> setModel(standardItemModel1);
    //listview2 -> setModel(standardItemModel2);
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
