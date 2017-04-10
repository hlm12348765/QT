#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("SLAT2000"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receivelogin()  
{  
    this->show();//显示主窗口  
}  
  
void MainWindow::on_pushButton_clicked()  
{  
    this->hide();//隐藏主窗口  
    emit dlgshow();//发射显示登录对话框信号  
}  
  
void MainWindow::on_pushButton_2_clicked()  
{  
    emit quit();//发射退出信号  
}  
