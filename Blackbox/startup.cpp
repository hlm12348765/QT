#include "startup.h"
#include "ui_startup.h"

startup::startup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startup)
{
    ui->setupUi(this);
    this->Init();
}

startup::~startup()
{
    delete ui;
}

void startup::Init()
{
    setWindowFlags(Qt::FramelessWindowHint);
    tcpSocket = new QTcpSocket(this);
    tcpSocket -> connectToHost("172.17.32.199",6666);

    connect(tcpSocket,SIGNAL(connected()),this,SLOT(wllj_slot()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(wldk_slot()));
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recv_slot()));
}

void startup::receiveshow()
{
    this->show();
    tcpSocket -> connectToHost("172.17.32.199",6666);
}

void startup::wllj_slot()
{
    QPalette pal_wllj;
    pal_wllj.setColor(QPalette::Button,Qt::green);
    ui->button2->setPalette(pal_wllj);
    ui->button2->setAutoFillBackground(true);
    ui->button2->setFlat(true);
    ui->button2->setEnabled(true);
    ui->button2->setText("已连接");
}

void startup::wldk_slot()
{
    QPalette pal_wldk;
    pal_wldk.setColor(QPalette::Button,Qt::red);
    ui->button2->setPalette(pal_wldk);
    ui->button2->setAutoFillBackground(true);
    ui->button2->setFlat(true);
    ui->button2->setEnabled(false);
    ui->button2->setText("已断开");
}

void startup::recv_slot()
{
    QString str;
    str = tcpSocket -> readAll();
    int i = str.indexOf("xuyao");
    if (i!=-1)
    {
      tcpSocket->abort();
      this->close();
      emit zshow();
    }

    int n = str.indexOf("wuxu");
    if (n!=-1)
    {
      delete tcpSocket;
      this->close();
      emit xshow();
    }
}
