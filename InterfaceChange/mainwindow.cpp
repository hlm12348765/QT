#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QImage>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setWindowState(Qt::WindowMaximized);
    setWindowTitle(tr("SLAT2000"));
    setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);

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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
}

void MainWindow::receivelogin()  
{  
    this->show();//显示主窗口  
}  
  
//void MainWindow::on_pushButton_clicked()
//{
 //   this->hide();//隐藏主窗口
  //  emit dlgshow();//发射显示登录对话框信号
//}
  
void MainWindow::on_pushButton_2_clicked()  
{  
   // emit quit();//发射退出信号
    this ->hide();
    emit trashow();
}  
