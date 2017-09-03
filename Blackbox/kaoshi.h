#ifndef KAOSHI_H
#define KAOSHI_H

#include <QWidget>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QTextCodec>
#include <QPalette>

namespace Ui {
class kaoshi;
}

class kaoshi : public QWidget
{
    Q_OBJECT

public:
    explicit kaoshi(QWidget *parent = 0);
    ~kaoshi();

signals:
    void xshow();

private slots:
    void recv_slot();
    void wllj_slot();
    void wldk_slot();
    void receiveshow();

private:
    Ui::kaoshi *ui;
    void Init();
    QTcpSocket *tcpSocket;
};

#endif // KAOSHI_H
