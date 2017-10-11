#include "xuzhi.h"
#include "ui_xuzhi.h"
#include <QBuffer>
#include <QHostAddress>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QProcess>

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
    setWindowFlags(Qt::FramelessWindowHint);
    //tcpSocket = new QTcpSocket(this);
}

static QString getIP()
{
    QString IP;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
        ipAddressesList.at(i).toIPv4Address())
        {
            IP = ipAddressesList.at(i).toString();
            break;
        }
    }

    if (IP.isEmpty())
        IP = QHostAddress(QHostAddress::LocalHost).toString();
    QString a = "***";
    IP.replace(10,3,a);
    return IP;
}

static QString getMAC()
{
    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();
    int nCnt = nets.count();
    QString strMacAddr = "";
    for(int i = 0; i < nCnt; i ++)
    {
        if(nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning) && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
        {
            strMacAddr = nets[i].hardwareAddress();
            break;
        }
    }
    QString b = "**:**";
    strMacAddr.replace(12,5,b);
    return strMacAddr;
}

static QString getVersion()
{
    QString str1;
    QString version;
    QFile file("qrc/version");

    if (file.open(QIODevice ::ReadOnly | QIODevice ::Text))
    {
        QTextStream textStream(&file);
        while (!textStream.atEnd())
        {
            str1 = textStream.readLine();
            version = str1.section(";",1,1);
        }
    }
    return version;
}

static QString getDate()
{
    QString str2;
    QString date;
    QFile file("qrc/version");

    if (file.open(QIODevice ::ReadOnly | QIODevice ::Text))
    {
        QTextStream textStream(&file);
        while (!textStream.atEnd())
        {
            str2 = textStream.readLine();
            date = str2.section(";",2,2);
        }
    }
    return date;
}

void xuzhi::receiveshow()
{
    this->show();
    tcpSocket = new QTcpSocket(this);
    tcpSocket -> connectToHost("192.168.1.155",6666);

    connect(tcpSocket,SIGNAL(connected()),this,SLOT(wllj_slot()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(wldk_slot()));
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recv_slot()));

    ui->button3->setText(getIP());
    ui->button4->setText(getMAC());
    ui->button5->setText(getVersion());
    ui->button6->setText(getDate());
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

    int i = byte.indexOf("kaishibidui");
    if (i!=-1)
    {
      tcpSocket->abort();
      this->close();
      emit bshow();
    }
}
