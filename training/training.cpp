#include <QtGui>
#include "training.h"
//#include "ui_training.h"
#include <QImage>
#include <QApplication>

Training::Training(QWidget *parent) :QWidget(parent)
//    ui(new Ui::Training)
{
    //ui -> setupUi(this);

    textEdit = new QTextEdit();
    QLabel *label1 = new QLabel(this);
    label1 -> setPixmap(QPixmap("/opt/qt/logo.png"));
    label1 -> show();
    layout = new QGridLayout();
    layout -> addWidget(label1,0,0,1,3);
    layout -> addWidget(textEdit,1,0,3,3);
    setLayout(layout);

    setWindowTitle(tr("SLAT2000"));
    setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    resize(480, 272);

    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recv_slot()));

}

//Training::~Training()
//{
//    delete ui;
//}

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
    tcpSocket -> connectToHost("172.17.32.199",23);
}

void Training::recv_slot()
{
    QByteArray byte;
    byte = tcpSocket -> readAll();
    textEdit -> setPlainText(QString(byte));
}
