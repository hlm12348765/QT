#include <QtGui>
#include "training.h"

Training::Training(QWidget *parent) :QWidget(parent)
{
    textEdit = new QTextEdit();
    QLabel *label = new QLabel(this);
    label -> setPixmap(QPixmap("/opt/qt/logo.png"));
    label -> show();
    layout = new QGridLayout();
    layout -> addWidget(label,0,0,1,3);
    layout -> addWidget(textEdit,1,0,3,3);
    setLayout(layout);

    setWindowTitle(tr("SLAT2000"));
    setWindowFlags(Qt::WindowTitleHint);
    resize(480, 272);

    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recv_slot()));
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
    tcpSocket -> connectToHost("172.17.32.199",23);
}

void Training::recv_slot()
{
    QByteArray byte;
    byte = tcpSocket -> readAll();
    textEdit -> setPlainText(QString(byte));
}
