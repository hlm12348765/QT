#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:  
    void on_pushButton_clicked();//与login关联的槽函数  
    void receiveshow();//与relogin中发射的信号关联的槽函数  
   // void on_pushButton_2_clicked();//与exit关联的槽函数
signals:  
    void showmainwindow();//显示主窗口信号  
   // void quit();//退出信号

private:
    Ui::Dialog *ui;

private:
    void closeEvent(QCloseEvent *event);
};

#endif // DIALOG_H
