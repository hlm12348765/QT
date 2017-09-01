#ifndef XUZHI_H
#define XUZHI_J

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextCodec>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QPushButton>
#include <QCloseEvent>

class Xuzhi : public QWidget
{
  Q_OBJECT

public:
  Xuzhi(QWidget *parent = 0);
  virtual ~Xuzhi() {}

private:
  QTcpSocket *tcpSocket;
  QGridLayout *layout;
  QLineEdit *textEdit1;
  QLineEdit *textEdit2;
  QLineEdit *textEdit3;
  QLineEdit *textEdit4;
  QLineEdit *textEdit5;
  QPushButton *loginButton;
  void closeEvent(QCloseEvent *event);

public slots:
  void recv_slot();

private slots:
  void receiveshow();
};

#endif // XUZHI_H
