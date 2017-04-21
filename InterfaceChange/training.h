#ifndef TRAINING_H
#define TRAINING_H

#include <QWidget>
#include <QCloseEvent>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QGridLayout>
#include <QTextEdit>
#include <QPushButton>

namespace Ui {
class Training;
}

class Training : public QWidget
{
    Q_OBJECT

public:
    explicit Training(QWidget *parent = 0);
    ~Training();

public slots:
    void send_slot();
    void recv_slot();
    void connect_slot();

private slots:
    void receiveshow();

private:
    Ui::Training *ui;

private:
    void closeEvent(QCloseEvent *event);

private:
    QTcpSocket *tcpSocket;
    QGridLayout *layout;
    QTextEdit *textEdit;
    QPushButton *connectButton;
    QPushButton *sendButton;
};

#endif // TRAINING_H
