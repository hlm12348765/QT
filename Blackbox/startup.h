#ifndef STARTUP_H
#define STARTUP_H

#include <QWidget>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QTextCodec>
#include <QPalette>

namespace Ui {
class startup;
}

class startup : public QWidget
{
    Q_OBJECT

public:
    explicit startup(QWidget *parent = 0);
    ~startup();

private:
    Ui::startup *ui;
    void Init();
    QTcpSocket *tcpSocket;

signals:
    void zshow();
    void xshow();

private slots:
    void recv_slot();
    void wllj_slot();
    void wldk_slot();
    void receiveshow();
};

#endif // STARTUP_H
