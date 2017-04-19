#include "dialog.h"
#include "ui_dialog.h"
#include <QHBoxLayout>
#include <mainwindow.h>
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
    //QImage *image=new QImage("/opt/qt/logo.png");
    QLabel *label=new QLabel(this);  
    label->setGeometry(0,0,480,100);
   // label->setPixmap(QPixmap::fromImage(*image));
    label->setPixmap(QPixmap("/opt/qt/logo.png"));
    label->show(); 
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::closeEvent(QCloseEvent *event)
{
    event->ignore();
}

void Dialog::on_pushButton_clicked()
{  
    this->hide();//隐藏登录对话框  
    emit showmainwindow();//显示主窗口  
}  
  
  
void Dialog::receiveshow()
{  
    this->show();//显示登录对话框  
  
}  
  
//void Dialog::on_pushButton_2_clicked()
//{
 //   emit quit();//发射退出信号
//}
