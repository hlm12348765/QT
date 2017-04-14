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
}

Dialog::~Dialog()
{
    delete ui;
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
