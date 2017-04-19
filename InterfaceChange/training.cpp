#include <QtGui>
#include "training.h"
#include "ui_training.h"
#include <QImage>

Training::Training(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Training)
{
    ui->setupUi(this);
    setWindowTitle(tr("SLAT2000"));
    setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    //setWindowState(Qt::WindowMaximized);

    //QImage *image1=new QImage("/opt/qt/logo.png");
    QLabel *label1=new QLabel(this);
    label1->setGeometry(0,0,480,100);
    //label1->setPixmap(QPixmap::fromImage(*image1));
    label1->setPixmap(QPixmap("/opt/qt/logo.png"));
    label1->show();

    //QImage *image2=new QImage("/opt/qt/picture.png");
    QLabel *label2=new QLabel(this);
    label2->setGeometry(0,100,120,172);
    //label2->setPixmap(QPixmap::fromImage(*image2));
    label2->setPixmap(QPixmap("/opt/qt/picture.png"));
    label2->show();

    //QImage *image3=new QImage("/opt/qt/xinxi.png");
    QLabel *label3=new QLabel(this);
    label3->setGeometry(360,100,120,172);
    //label3->setPixmap(QPixmap::fromImage(*image3));
    label3->setPixmap(QPixmap("/opt/qt/xinxi.png"));
    label3->show();


}

Training::~Training()
{
    delete ui;
}

void Training::closeEvent(QCloseEvent *event)
{
    event->ignore();
}

void Training::receiveshow()
{
    this ->show();
}
