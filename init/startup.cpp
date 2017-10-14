#include "startup.h"
#include "ui_startup.h"
#include "common.h"

extern struct INIT_FLAG flag;

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
    //if (flag.ising==1)
    //{
       // ui->button2->setText("正在预安装,请等待");
   // }


    //ui->button2->setText("");

    //ui->button2->setText("");
    connect(this,SIGNAL(show()),this,SLOT(recv_slot()));
}

void startup::receiveshow()
{
    this->show();
}

void startup::recv_slot()
{
        qDebug()<<flag.unpass;
        if  (flag.unpass==1)
        {
            ui->button2->setText("U盘内容格式不符合要求");
        }
}
