#include "dialog.h"
#include "ui_dialog.h"
#include <QGridLayout>
#include "training.h"
#include <QLabel>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("SLAT2000"));
    //setWindowFlags(windowFlags() &~ Qt::WindowCloseButtonHint);
    //setWindowState(Qt::WindowMaximized);
    setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    //QImage *image = new QImage("/opt/qt/logo.png");

    loginButton = new QPushButton("login");
    QLabel *label = new QLabel(this);
    //label->setGeometry(0,0,480,100);
    //label->setPixmap(QPixmap::fromImage(*image));
    //label->setPixmap(QPixmap("/opt/qt/logo.png"));
    //label->show();
    layout = new QGridLayout();
    layout -> addWidget(label,0,0,1,3);
    layout -> addWidget(loginButton,1,1);
    setLayout(layout);
    label -> setPixmap(QPixmap("/opt/qt/logo.png"));

    tcpSocket = new QTcpSocket(this);

    connect(loginButton,SIGNAL(clicked()),this,SLOT(connect_slot()));
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(finish_slot()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::closeEvent(QCloseEvent *event)
{
    event -> ignore();
}

//void Dialog::on_pushButton_clicked()
//{
//    this->hide();
//    emit trashow();
//}


void Dialog::receiveshow()
{
    this -> show();

}

//void Dialog::login_slot()
//{
//     this -> hide();
//     emit trashow();
//}

void Dialog::connect_slot()
{
    tcpSocket -> connectToHost("172.17.32.199",22);
}

void Dialog::finish_slot()
{
     this -> hide();
     emit trashow();
}
//void Dialog::on_pushButton_2_clicked()
//{
 //   emit quit();
//}
