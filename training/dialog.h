#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QGridLayout>
#include <QPushButton>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
    //void login_slot();
    void finish_slot();
    void connect_slot();

private slots:
    //void on_pushButton_clicked();
    void receiveshow();
    //void on_pushButton_2_clicked();
signals:
    void showmainwindow();
    void trashow();
    void recv_start();
    //void quit();

private:
    Ui::Dialog *ui;
    QGridLayout *layout;
    QPushButton *loginButton;
    QTcpSocket *tcpSocket;

private:
    void closeEvent(QCloseEvent *event);
};

#endif // DIALOG_H
