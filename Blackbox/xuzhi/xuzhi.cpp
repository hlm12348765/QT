#include <QtGui>
#include "xuzhi.h"

Xuzhi::Xuzhi(QWidget *parent) :QWidget(parent)
{
  QLabel *label1 = new QLabel(this);
  label1 -> setPixmap(QPixmap("/opt/qt/logo1.png"));
  label1 -> setFixedSize(460,60);
  QLabel *label2 = new QLabel(tr("Kaoshengxuzhi"));
  QLabel *label3 = new QLabel(tr("IP Address"));
  QLabel *label4 = new QLabel(tr("MAC Address"));
  QLabel *label5 = new QLabel(tr("Version"));
  QLabel *label6 = new QLabel(tr("Release Date"));
  QLabel *label7 = new QLabel(tr("Tips"));
  loginButton = new QPushButton(tr("Start"));
  textEdit1 = new QTextEdit(this);
  textEdit2 = new QTextEdit(this);
  textEdit3 = new QTextEdit(this);
  textEdit4 = new QTextEdit(this);
  textEdit5 = new QTextEdit(this);
  layout = new QGridLayout();
  layout -> addWidget(label1,0,0,2,12);
  layout -> addWidget(label2,2,0,1,12);
  layout -> addWidget(label3,3,0,1,4);
  layout -> addWidget(label4,4,0,1,4);
  layout -> addWidget(label5,5,0,1,4);
  layout -> addWidget(label6,6,0,1,4);
  layout -> addWidget(label7,7,0,1,4);
  layout -> addWidget(textEdit1,3,4,1,4);
  layout -> addWidget(textEdit2,4,4,1,4);
  layout -> addWidget(textEdit3,5,4,1,4);
  layout -> addWidget(textEdit4,6,4,1,4);
  layout -> addWidget(textEdit5,7,4,1,4);
  layout -> addWidget(loginButton,4,8,3,3);

  this -> setLayout(layout);
  setWindowTitle(tr("Blackbox"));
  resize(480,272);
}

void Xuzhi::receiveshow()
{
  this -> show();
}
