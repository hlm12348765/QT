#include <QtGui>
#include "training.h"
#include "ui_training.h"
#include <QImage>
#include <QApplication>

Training::Training(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Training)
{
    ui -> setupUi(this);
    setWindowTitle(tr("SLAT2000"));
    setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    //setWindowState(Qt::WindowMaximized);

    //connectButton = new QPushButton("connect");
    //sendButton = new QPushButton("send");
    textEdit = new QTextEdit();

    //QImage *image1=new QImage("/opt/qt/logo.png");
    QLabel *label1 = new QLabel(this);
    //label1->setGeometry(0,0,480,100);
    //label1->setPixmap(QPixmap::fromImage(*image1));
    //label1->setPixmap(QPixmap("/opt/qt/logo.png"));
    //label1->show();

    //QImage *image2=new QImage("/opt/qt/picture.png");
    //QLabel *label2=new QLabel(this);
    //label2->setGeometry(0,100,120,172);
    //label2->setPixmap(QPixmap::fromImage(*image2));
    //label2->setPixmap(QPixmap("/opt/qt/picture.png"));
    //label2->show();
    layout = new QGridLayout();
    layout -> addWidget(label1,0,0,1,3);
    layout -> addWidget(textEdit,1,0,3,3);
    //layout -> addWidget(connectButton,1,2);
    //layout -> addWidget(sendButton,2,2);
    setLayout(layout);
    label1 -> setPixmap(QPixmap("/opt/qt/logo.png"));
    label1 -> show();

    //QImage *image3=new QImage("/opt/qt/xinxi.png");
    //QLabel *label3=new QLabel(this);
    //label3->setGeometry(360,100,120,172);
    //label3->setPixmap(QPixmap::fromImage(*image3));
    //label3->setPixmap(QPixmap("/opt/qt/xinxi.png"));
    //label3->show();

    //sendButton -> setDisabled(false);
    tcpSocket = new QTcpSocket(this);
    //tcpSocket_connect_HBJ -> abort();
    //tcpSocket -> connectToHost("172.17.32.199",22);

    //connect(connectButton,SIGNAL(clicked()),this,SLOT(connect_slot()));
    //connect(sendButton,SIGNAL(clicked()),this,SLOT(send_slot()));
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recv_slot()));

}

Training::~Training()
{
    delete ui;
}

void Training::closeEvent(QCloseEvent *event)
{
    event -> ignore();
}

void Training::receiveshow()
{
    this -> show();
}

void Training::connect_slot()
{
    //tcpSocket_connect_HBJ -> abort();
    tcpSocket -> connectToHost("172.17.32.199",23);
}

//void Training::send_slot()
//{
//    QString str = textEdit -> toPlainText();
//    tcpSocket -> write(qPrintable(str));
//}

void Training::recv_slot()
{
    QByteArray byte;
    byte = tcpSocket -> readAll();
    textEdit -> setPlainText(QString(byte));
}
