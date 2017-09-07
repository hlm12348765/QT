#include "kaoshi.h"
#include "ui_kaoshi.h"

kaoshi::kaoshi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kaoshi)
{
    ui->setupUi(this);
    this->Init();
}

kaoshi::~kaoshi()
{
    delete ui;
}

void kaoshi::Init()
{
    ui->lineEdit1->setReadOnly(true);
    ui->lineEdit2->setReadOnly(true);
    ui->lineEdit3->setReadOnly(true);
    ui->lineEdit4->setReadOnly(true);
    ui->lineEdit5->setReadOnly(true);

    setWindowFlags(Qt::FramelessWindowHint);
}

void kaoshi::receiveshow()
{
    this->show();
    tcpSocket = new QTcpSocket(this);
    tcpSocket -> connectToHost("172.17.32.199",6666);

    connect(tcpSocket,SIGNAL(connected()),this,SLOT(wllj_slot()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(wldk_slot()));
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recv_slot()));

    QDir dir("qrc/");
    QStringList filters;
    filters <<"*.jpg";
    dir.setNameFilters(filters);
    QFileInfoList list = dir.entryInfoList();

    if(list.length()!=0)
    for (int i = 0; i < list.size(); ++i)
    {
        QPixmap img("qrc/"+list.at(0).fileName());
        ui->label3->setPixmap(QPixmap(img));
    }
}

void kaoshi::wllj_slot()
{
    QPalette pal_wllj;
    pal_wllj.setColor(QPalette::Button,Qt::green);
    ui->button1->setPalette(pal_wllj);
    ui->button1->setAutoFillBackground(true);
    ui->button1->setFlat(true);
    ui->button1->setEnabled(true);
    ui->button1->setText("已连接");
}

void kaoshi::wldk_slot()
{
    QPalette pal_wldk;
    pal_wldk.setColor(QPalette::Button,Qt::red);
    ui->button1->setPalette(pal_wldk);
    ui->button1->setAutoFillBackground(true);
    ui->button1->setFlat(true);
    ui->button1->setEnabled(false);
    ui->button1->setText("已断开");
}

void kaoshi::recv_slot()
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

        ui->lineEdit1->setText(QString(str1));
        ui->lineEdit2->setText(QString(str2));
        ui->lineEdit3->setText(QString(str3));
        ui->lineEdit4->setText(QString(str4));
        ui->lineEdit5->setText(QString(str5));
    }

    int i = byte.indexOf("kaoshijieshu");
    if (i!=-1)
    {
      delete tcpSocket;
      this->close();
      emit xshow();
    }
}
