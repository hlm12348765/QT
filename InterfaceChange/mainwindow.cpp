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

MainWindow::~MainWindow()
{
    delete ui;
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
