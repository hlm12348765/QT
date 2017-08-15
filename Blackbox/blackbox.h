//--------------------------------------------------------
//Title: Examing Interface for Blackbox
//Author: Bowen Nie
//Date completed: August 7th
//Version 1.0.0.0807_beta
//--------------------------------------------------------
#ifndef TRAINING_H
#define TRAINING_H

#include <QWidget>
#include <QCloseEvent>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QGridLayout>
#include <QTextEdit>
#include <QTextCodec>
#include <QListView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QModelIndex>

class Training : public QWidget
{
  Q_OBJECT

public:
  Training(QWidget *parent = 0);
  virtual ~Training() {}

private:
  QTcpSocket *tcpSocket;
  QGridLayout *layout;
  QTextEdit *textEdit1;
  QTextEdit *textEdit2;
  QTextEdit *textEdit3;
  QTextEdit *textEdit4;
  QTextEdit *textEdit5;
  QTextEdit *textEdit6;
  QListView *listview1;
  QListView *listview2;
  QStandardItemModel *standardItemModel1;
  QStandardItemModel *standardItemModel2;
  void closeEvent(QCloseEvent *event);

signals:
  void dlgshow();

public slots:
  void recv_slot();
  void connect_slot();

private slots:
  void receiveshow();
};

#endif // TRAINING_H
