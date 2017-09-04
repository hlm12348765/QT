#include "bidui.h"
#include "ui_bidui.h"

bidui::bidui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bidui)
{
    ui->setupUi(this);
    this->Init();
}

bidui::~bidui()
{
    delete ui;
}

void bidui::Init()
{
    setWindowFlags(Qt::FramelessWindowHint);
    tcpSocket = new QTcpSocket(this);
}

void bidui::receiveshow()
{
    this->show();
    tcpSocket -> connectToHost("172.17.32.199",6666);
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(wllj_slot()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(wldk_slot()));
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recv_slot()));
}

void bidui::wllj_slot()
{
    QPalette pal_wllj;
    pal_wllj.setColor(QPalette::Button,Qt::green);
    ui->button2->setPalette(pal_wllj);
    ui->button2->setAutoFillBackground(true);
    ui->button2->setFlat(true);
    ui->button2->setEnabled(true);
    ui->button2->setText("已连接");
}

void bidui::wldk_slot()
{
    QPalette pal_wldk;
    pal_wldk.setColor(QPalette::Button,Qt::red);
    ui->button2->setPalette(pal_wldk);
    ui->button2->setAutoFillBackground(true);
    ui->button2->setFlat(true);
    ui->button2->setEnabled(false);
    ui->button2->setText("已断开");
}

void bidui::recv_slot()
{
    QString str;
    str = tcpSocket -> readAll();
    int i = str.indexOf("yunxukaoshi");
    if (i!=-1)
    {
      tcpSocket->abort();
      this->close();
      emit kshow();
    }
}
