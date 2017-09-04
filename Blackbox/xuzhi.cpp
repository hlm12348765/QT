#include "xuzhi.h"
#include "ui_xuzhi.h"

xuzhi::xuzhi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::xuzhi)
{
    ui->setupUi(this);
    this->Init();
}

xuzhi::~xuzhi()
{
    delete ui;
}

void xuzhi::Init()
{
    ui->lineEdit1->setReadOnly(true);
    ui->lineEdit2->setReadOnly(true);
    ui->lineEdit3->setReadOnly(true);
    ui->lineEdit4->setReadOnly(true);

    setWindowFlags(Qt::FramelessWindowHint);
    tcpSocket = new QTcpSocket(this);
}

void xuzhi::receiveshow()
{
    this->show();
    tcpSocket -> connectToHost("172.17.32.199",6666);
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(wllj_slot()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(wldk_slot()));
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recv_slot()));
}

void xuzhi::on_button1_clicked()
{
    QByteArray dataSend = "qingqiukaoshi\n";
    tcpSocket->write(dataSend);
}

void xuzhi::wllj_slot()
{
    QPalette pal_wllj;
    pal_wllj.setColor(QPalette::Button,Qt::green);
    ui->button2->setPalette(pal_wllj);
    ui->button2->setAutoFillBackground(true);
    ui->button2->setFlat(true);
    ui->button2->setEnabled(true);
    ui->button2->setText("已连接");
}

void xuzhi::wldk_slot()
{
    QPalette pal_wldk;
    pal_wldk.setColor(QPalette::Button,Qt::red);
    ui->button2->setPalette(pal_wldk);
    ui->button2->setAutoFillBackground(true);
    ui->button2->setFlat(true);
    ui->button2->setEnabled(false);
    ui->button2->setText("已断开");
}

void xuzhi::recv_slot()
{
    ui->button1->setEnabled(true);

    QString byte;
    byte = tcpSocket -> readAll();

    QString str1;
    QString str2;
    QString str3;
    QString str4;

    if (byte.startsWith("$ks") && byte.endsWith("$js"))
    {
        str1 = byte.section(";",1,1);
        str2 = byte.section(";",2,2);
        str3 = byte.section(";",3,3);
        str4 = byte.section(";",4,4);

        ui->lineEdit1->setText(QString(str1));
        ui->lineEdit2->setText(QString(str2));
        ui->lineEdit3->setText(QString(str3));
        ui->lineEdit4->setText(QString(str4));
    }

    int i = byte.indexOf("kaishibidui");
    if (i!=-1)
    {
      tcpSocket->abort();
      this->close();
      emit bshow();
    }
}
