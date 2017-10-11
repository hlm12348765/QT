#include "zijian.h"
#include "ui_zijian.h"

zijian::zijian(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zijian)
{
    ui->setupUi(this);
    this->Init();
}

zijian::~zijian()
{
    delete ui;
}

void zijian::Init()
{
    ui->button1->setEnabled(false);
    ui->button2->setEnabled(false);
    ui->button3->setEnabled(false);
    ui->button4->setEnabled(false);
    ui->button5->setEnabled(false);
    ui->button6->setEnabled(false);
    ui->button7->setEnabled(false);
    ui->button8->setEnabled(false);
    ui->button9->setEnabled(false);
    ui->button10->setEnabled(false);
    ui->button11->setEnabled(false);

    setWindowFlags(Qt::FramelessWindowHint);
}

void zijian::receiveshow()
{
    this->show();
    tcpSocket = new QTcpSocket(this);
    tcpSocket -> connectToHost("192.168.1.155",6666);

    connect(tcpSocket,SIGNAL(connected()),this,SLOT(wllj_slot()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(wldk_slot()));
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recv_slot()));
}

void zijian::wllj_slot()
{
    QPalette pal_wllj;
    pal_wllj.setColor(QPalette::Button,Qt::green);
    ui->button11->setPalette(pal_wllj);
    ui->button11->setAutoFillBackground(true);
    ui->button11->setFlat(true);
    ui->button11->setEnabled(true);
    ui->button11->setText("已连接");
}

void zijian::wldk_slot()
{
    QPalette pal_wldk;
    pal_wldk.setColor(QPalette::Button,Qt::red);
    ui->button11->setPalette(pal_wldk);
    ui->button11->setAutoFillBackground(true);
    ui->button11->setFlat(true);
    ui->button11->setEnabled(false);
    ui->button11->setText("已断开");
}

void zijian::recv_slot()
{
    QString byte;
    byte = tcpSocket ->readAll();

    QPalette pal_aqd;
    QPalette pal_ss;
    QPalette pal_lh;
    QPalette pal_cm;
    QPalette pal_zzx;
    QPalette pal_yzx;
    QPalette pal_lb;
    QPalette pal_kd;
    QPalette pal_dhkg;
    QPalette pal_fdjzt;

    int i1 = byte.indexOf("aqd");
    if (i1!=-1)
    {
        pal_aqd.setColor(QPalette::Button,Qt::white);
        ui->button1->setPalette(pal_aqd);
        ui->button1->setAutoFillBackground(true);
        ui->button1->setFlat(true);
        ui->button1->setText("正在检查");
        ui->button1->setEnabled(true);
    }

    int n1 = byte.indexOf("aqd_pass");
    if (n1!=-1)
    {
        pal_aqd.setColor(QPalette::Button,Qt::green);
        ui->button1->setPalette(pal_aqd);
        ui->button1->setAutoFillBackground(true);
        ui->button1->setFlat(true);
        ui->button1->setText("通过");
    }

    int s1 = byte.indexOf("aqd_fail");
    if (s1!=-1)
    {
        pal_aqd.setColor(QPalette::Button,Qt::red);
        ui->button1->setPalette(pal_aqd);
        ui->button1->setAutoFillBackground(true);
        ui->button1->setFlat(true);
        ui->button1->setText("异常");
    }

    int i2 = byte.indexOf("shsh");
    if (i2!=-1)
    {
        pal_ss.setColor(QPalette::Button,Qt::white);
        ui->button2->setPalette(pal_ss);
        ui->button2->setAutoFillBackground(true);
        ui->button2->setFlat(true);
        ui->button2->setText("正在检查");
        ui->button2->setEnabled(true);
    }

    int n2 = byte.indexOf("shsh_pass");
    if (n2!=-1)
    {
        pal_ss.setColor(QPalette::Button,Qt::green);
        ui->button2->setPalette(pal_ss);
        ui->button2->setAutoFillBackground(true);
        ui->button2->setFlat(true);
        ui->button2->setText("通过");
    }

    int s2 = byte.indexOf("shsh_fail");
    if (s2!=-1)
    {
        pal_ss.setColor(QPalette::Button,Qt::red);
        ui->button2->setPalette(pal_ss);
        ui->button2->setAutoFillBackground(true);
        ui->button2->setFlat(true);
        ui->button2->setText("异常");
    }

    int i3 = byte.indexOf("lh");
    if (i3!=-1)
    {
        pal_lh.setColor(QPalette::Button,Qt::white);
        ui->button3->setPalette(pal_lh);
        ui->button3->setAutoFillBackground(true);
        ui->button3->setFlat(true);
        ui->button3->setText("正在检查");
        ui->button3->setEnabled(true);
    }

    int n3 = byte.indexOf("lh_pass");
    if (n3!=-1)
    {
        pal_lh.setColor(QPalette::Button,Qt::green);
        ui->button3->setPalette(pal_lh);
        ui->button3->setAutoFillBackground(true);
        ui->button3->setFlat(true);
        ui->button3->setText("通过");
    }

    int s3 = byte.indexOf("lh_fail");
    if (s3!=-1)
    {
        pal_lh.setColor(QPalette::Button,Qt::red);
        ui->button3->setPalette(pal_lh);
        ui->button3->setAutoFillBackground(true);
        ui->button3->setFlat(true);
        ui->button3->setText("异常");
    }

    int i4 = byte.indexOf("cm");
    if (i4!=-1)
    {
        pal_cm.setColor(QPalette::Button,Qt::white);
        ui->button4->setPalette(pal_cm);
        ui->button4->setAutoFillBackground(true);
        ui->button4->setFlat(true);
        ui->button4->setText("正在检查");
        ui->button4->setEnabled(true);
    }

    int n4 = byte.indexOf("cm_pass");
    if (n4!=-1)
    {
        pal_cm.setColor(QPalette::Button,Qt::green);
        ui->button4->setPalette(pal_cm);
        ui->button4->setAutoFillBackground(true);
        ui->button4->setFlat(true);
        ui->button4->setText("通过");
    }

    int s4 = byte.indexOf("cm_fail");
    if (s4!=-1)
    {
        pal_cm.setColor(QPalette::Button,Qt::red);
        ui->button4->setPalette(pal_cm);
        ui->button4->setAutoFillBackground(true);
        ui->button4->setFlat(true);
        ui->button4->setText("异常");
    }

    int i5 = byte.indexOf("zzx");
    if (i5!=-1)
    {
        pal_zzx.setColor(QPalette::Button,Qt::white);
        ui->button5->setPalette(pal_zzx);
        ui->button5->setAutoFillBackground(true);
        ui->button5->setFlat(true);
        ui->button5->setText("正在检查");
        ui->button5->setEnabled(true);
    }

    int n5 = byte.indexOf("zzx_pass");
    if (n5!=-1)
    {
        pal_zzx.setColor(QPalette::Button,Qt::green);
        ui->button5->setPalette(pal_zzx);
        ui->button5->setAutoFillBackground(true);
        ui->button5->setFlat(true);
        ui->button5->setText("通过");
    }

    int s5 = byte.indexOf("zzx_fail");
    if (s5!=-1)
    {
        pal_zzx.setColor(QPalette::Button,Qt::red);
        ui->button5->setPalette(pal_zzx);
        ui->button5->setAutoFillBackground(true);
        ui->button5->setFlat(true);
        ui->button5->setText("异常");
    }

    int i6 = byte.indexOf("yzx");
    if (i6!=-1)
    {
        pal_yzx.setColor(QPalette::Button,Qt::white);
        ui->button6->setPalette(pal_yzx);
        ui->button6->setAutoFillBackground(true);
        ui->button6->setFlat(true);
        ui->button6->setText("正在检查");
        ui->button6->setEnabled(true);
    }

    int n6 = byte.indexOf("yzx_pass");
    if (n6!=-1)
    {
        pal_yzx.setColor(QPalette::Button,Qt::green);
        ui->button6->setPalette(pal_yzx);
        ui->button6->setAutoFillBackground(true);
        ui->button6->setFlat(true);
        ui->button6->setText("通过");
    }

    int s6 = byte.indexOf("yzx_fail");
    if (s6!=-1)
    {
        pal_yzx.setColor(QPalette::Button,Qt::red);
        ui->button6->setPalette(pal_yzx);
        ui->button6->setAutoFillBackground(true);
        ui->button6->setFlat(true);
        ui->button6->setText("异常");
    }

    int i7 = byte.indexOf("lb");
    if (i7!=-1)
    {
        pal_lb.setColor(QPalette::Button,Qt::white);
        ui->button7->setPalette(pal_lb);
        ui->button7->setAutoFillBackground(true);
        ui->button7->setFlat(true);
        ui->button7->setText("正在检查");
        ui->button7->setEnabled(true);
    }

    int n7 = byte.indexOf("lb_pass");
    if (n7!=-1)
    {
        pal_lb.setColor(QPalette::Button,Qt::green);
        ui->button7->setPalette(pal_lb);
        ui->button7->setAutoFillBackground(true);
        ui->button7->setFlat(true);
        ui->button7->setText("通过");
    }

    int s7 = byte.indexOf("lb_fail");
    if (s7!=-1)
    {
        pal_lb.setColor(QPalette::Button,Qt::red);
        ui->button7->setPalette(pal_lb);
        ui->button7->setAutoFillBackground(true);
        ui->button7->setFlat(true);
        ui->button7->setText("异常");
    }

    int i8 = byte.indexOf("kd");
    if (i8!=-1)
    {
        pal_kd.setColor(QPalette::Button,Qt::white);
        ui->button8->setPalette(pal_kd);
        ui->button8->setAutoFillBackground(true);
        ui->button8->setFlat(true);
        ui->button8->setText("正在检查");
        ui->button8->setEnabled(true);
    }

    int n8 = byte.indexOf("kd_pass");
    if (n8!=-1)
    {
        pal_kd.setColor(QPalette::Button,Qt::green);
        ui->button8->setPalette(pal_kd);
        ui->button8->setAutoFillBackground(true);
        ui->button8->setFlat(true);
        ui->button8->setText("通过");
    }

    int s8 = byte.indexOf("kd_fail");
    if (s8!=-1)
    {
        pal_kd.setColor(QPalette::Button,Qt::red);
        ui->button8->setPalette(pal_kd);
        ui->button8->setAutoFillBackground(true);
        ui->button8->setFlat(true);
        ui->button8->setText("异常");
    }

    int i9 = byte.indexOf("dhkg");
    if (i9!=-1)
    {
        pal_dhkg.setColor(QPalette::Button,Qt::white);
        ui->button9->setPalette(pal_dhkg);
        ui->button9->setAutoFillBackground(true);
        ui->button9->setFlat(true);
        ui->button9->setText("正在检查");
        ui->button9->setEnabled(true);
    }

    int n9 = byte.indexOf("dhkg_pass");
    if (n9!=-1)
    {
        pal_dhkg.setColor(QPalette::Button,Qt::green);
        ui->button9->setPalette(pal_dhkg);
        ui->button9->setAutoFillBackground(true);
        ui->button9->setFlat(true);
        ui->button9->setText("通过");
    }

    int s9 = byte.indexOf("dhkg_fail");
    if (s9!=-1)
    {
        pal_dhkg.setColor(QPalette::Button,Qt::red);
        ui->button9->setPalette(pal_dhkg);
        ui->button9->setAutoFillBackground(true);
        ui->button9->setFlat(true);
        ui->button9->setText("异常");
    }

    int i10 = byte.indexOf("fdjzt");
    if (i10!=-1)
    {
        pal_fdjzt.setColor(QPalette::Button,Qt::white);
        ui->button10->setPalette(pal_fdjzt);
        ui->button10->setAutoFillBackground(true);
        ui->button10->setFlat(true);
        ui->button10->setText("正在检查");
        ui->button10->setEnabled(true);
    }

    int n10 = byte.indexOf("fdjzt_pass");
    if (n10!=-1)
    {
        pal_fdjzt.setColor(QPalette::Button,Qt::green);
        ui->button10->setPalette(pal_fdjzt);
        ui->button10->setAutoFillBackground(true);
        ui->button10->setFlat(true);
        ui->button10->setText("通过");
    }

    int s10 = byte.indexOf("aqd_fail");
    if (s10!=-1)
    {
        pal_fdjzt.setColor(QPalette::Button,Qt::red);
        ui->button10->setPalette(pal_fdjzt);
        ui->button10->setAutoFillBackground(true);
        ui->button10->setFlat(true);
        ui->button10->setText("异常");
    }

    int t = byte.indexOf("jinruxuzhi");
    if (t!=-1)
    {
        delete tcpSocket;
        this->close();
        emit xshow();
    }
}
