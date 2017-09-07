#ifndef XUZHI_H
#define XUZHI_H

#include <QWidget>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QTextCodec>
#include <QPalette>
#include <QHostAddress>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QProcess>
#include <QList>
#include <QFile>
#include <QTextStream>

namespace Ui {
class xuzhi;
}

class xuzhi : public QWidget
{
    Q_OBJECT

public:
    explicit xuzhi(QWidget *parent = 0);
    ~xuzhi();

signals:
    void bshow();

private slots:
    void on_button1_clicked();
    void recv_slot();
    void wllj_slot();
    void wldk_slot();
    void receiveshow();

private:
    Ui::xuzhi *ui;
    void Init();
    QTcpSocket *tcpSocket;


signals:
    void bidshow();
};

#endif // XUZHI_H
