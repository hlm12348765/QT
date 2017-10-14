#ifndef STARTUP_H
#define STARTUP_H

#include <QWidget>
#include <QTextCodec>
#include <QPalette>
#include <QDebug>

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

signals:


private slots:
    void receiveshow();
    void recv_slot();
};

#endif // STARTUP_H
