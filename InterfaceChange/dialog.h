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
    void on_pushButton_clicked();
    void receiveshow(); 
    //void on_pushButton_2_clicked();
signals:
    void showmainwindow();
    void trashow();
    //void quit();

private:
    Ui::Dialog *ui;

private:
    void closeEvent(QCloseEvent *event);
};

#endif // DIALOG_H
