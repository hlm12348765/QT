#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QGridLayout>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    virtual ~Dialog() {}

private:
    QGridLayout *layout;
    QPushButton *loginButton;
    QTcpSocket *tcpSocket;
    void closeEvent(QCloseEvent *event);

public slots:
    void finish_slot();
    void connect_slot();

private slots:
    void receiveshow();

signals:
    void showmainwindow();
    void trashow();
    void recv_start();
};

#endif // DIALOG_H
