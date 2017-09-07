#ifndef BIDUI_H
#define BIDUI_H

#include <QWidget>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QTextCodec>
#include <QPalette>
#include <QDir>
#include <QList>

namespace Ui {
class bidui;
}

class bidui : public QWidget
{
    Q_OBJECT

public:
    explicit bidui(QWidget *parent = 0);
    ~bidui();

private:
    Ui::bidui *ui;
    void Init();
    QTcpSocket *tcpSocket;

signals:
    void kshow();

private slots:
    void recv_slot();
    void wllj_slot();
    void wldk_slot();
    void receiveshow();
};

#endif // BIDUI_H
