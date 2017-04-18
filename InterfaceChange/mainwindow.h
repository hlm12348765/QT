#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    void closeEvent(QCloseEvent *event);

private slots:  
    void receivelogin();//与login中发射的信号关联的槽函数  
    //void on_pushButton_clicked();//与relogin的click()关联的槽函数
  
    void on_pushButton_2_clicked();//与quit的click()关联的槽函数  
  
signals:  
    void dlgshow();//显示登录对话框信号  
    void quit();//退出信号
    void trashow();
};

#endif // MAINWINDOW_H
