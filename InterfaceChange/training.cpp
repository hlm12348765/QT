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
    QImage *image=new QImage("/home/nie/mygit/QT/InterfaceChange/logo.png");  
  
    QLabel *label=new QLabel(this);  
    label->setGeometry(0,0,520,100);
    label->setPixmap(QPixmap::fromImage(*image));  
    //label->setPixmap(QPixmap("/home/nie/mygit/QT/InterfaceChange/logo.png"));  
    label->show(); 

}

Training::~Training()
{
    delete ui;
}

void Training::receiveshow()
{
    this ->show();
}
