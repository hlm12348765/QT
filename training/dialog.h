#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QGridLayout>
#include <QPushButton>

//namespace Ui {
//class Dialog;
//}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    //explicit Dialog(QWidget *parent = 0);
    //~Dialog();
    Dialog(QWidget *parent = 0);
    virtual ~Dialog() {}

public slots:
    void finish_slot();
    void connect_slot();

private slots:
    void receiveshow();

signals:
    void showmainwindow();
    void trashow();
    void recv_start();

private:
    //Ui::Dialog *ui;
    QGridLayout *layout;
    QPushButton *loginButton;
    QTcpSocket *tcpSocket;

private:
    void closeEvent(QCloseEvent *event);
};

#endif // DIALOG_H
