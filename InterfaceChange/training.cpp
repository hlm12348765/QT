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
    //setWindowState(Qt::WindowMaximized)
    QImage *image1=new QImage("/home/nie/mygit/QT/InterfaceChange/logo.png");
    QLabel *label1=new QLabel(this);
    label1->setGeometry(0,0,520,100);
    label1->setPixmap(QPixmap::fromImage(*image1));
    //label1->setPixmap(QPixmap("/home/nie/mygit/QT/InterfaceChange/logo.png"));
    label1->show();

    QImage *image2=new QImage("/home/nie/mygit/QT/InterfaceChange/picture.png");
    QLabel *label2=new QLabel(this);
    label2->setGeometry(0,100,150,200);
    label2->setPixmap(QPixmap::fromImage(*image2));
    //label2->setPixmap(QPixmap("/home/nie/mygit/QT/InterfaceChange/picture.png"));
    label2->show();

}

Training::~Training()
{
    delete ui;
}

void Training::receiveshow()
{
    this ->show();
}
