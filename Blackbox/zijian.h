#ifndef ZIJIAN_H
#define ZIJIAN_H

#include <QWidget>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QTextCodec>
#include <QPalette>

namespace Ui {
class zijian;
}

class zijian : public QWidget
{
    Q_OBJECT

public:
    explicit zijian(QWidget *parent = 0);
    ~zijian();

private:
    Ui::zijian *ui;
    void Init();
    QTcpSocket *tcpSocket;

signals:
    void xshow();

private slots:
    void recv_slot();
    void wllj_slot();
    void wldk_slot();
    void receiveshow();
};

#endif // ZIJIAN_H
