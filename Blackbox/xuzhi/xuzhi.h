#ifndef XUZHI_H
#define XUZHI_J

#include <QWidget>
#include <QGridLayout>
#include <QTextEdit>
#include <QTextCodec>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QPushButton>

class Xuzhi : public QWidget
{
  Q_OBJECT

public:
  Xuzhi(QWidget *parent = 0);
  virtual ~Xuzhi() {}

private:
  //QTcpSocket *tcpSocket;
  QGridLayout *layout;
  QTextEdit *textEdit1;
  QTextEdit *textEdit2;
  QTextEdit *textEdit3;
  QTextEdit *textEdit4;
  QTextEdit *textEdit5;
  QPushButton *loginButton;

private slots:
  void receiveshow();
};

#endif // XUZHI_H
