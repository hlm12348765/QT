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
}

void bidui::receiveshow()
{
    this->show();
    tcpSocket = new QTcpSocket(this);
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

    QDir dir("qrc/");
    QStringList filters;
    filters <<"*.jpg";
    dir.setNameFilters(filters);
    QFileInfoList list = dir.entryInfoList();

    if(list.length()!=0)
    for (int i = 0; i < list.size(); ++i)
    {
        QPixmap img0("qrc/"+list.at(0).fileName());
        QPixmap img1("qrc/"+list.at(1).fileName());
        QPixmap img2("qrc/"+list.at(2).fileName());
        ui->label3->setPixmap(QPixmap(img0));
        ui->label4->setPixmap(QPixmap(img1));
        ui->label5->setPixmap(QPixmap(img2));
    }
    else
    {
        qDebug()<<"no file";
    }
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
      delete tcpSocket;
      this->close();
      emit kshow();
    }
}
