#include "socket.h"


SocketThread::SocketThread(QObject *parent)
: QThread(parent)
{
    m_bServerConnected = false;

    m_pTcpSocket = new QTcpSocket;
    connect(m_pTcpSocket, SIGNAL(connected()), this, SLOT(OnSocketConnected()));
    connect(m_pTcpSocket, SIGNAL(disconnected()), this, SLOT(OnSocketDisconnected()));
    connect(m_pTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(OnSocketError(QAbstractSocket::SocketError)));

    connect(&m_timer, SIGNAL(timeout()), this, SLOT(ConnectServer()));
    m_timer.setInterval(3000);
    m_timer.start();

    moveToThread(this);//must be the last executed

}

SocketThread::~SocketThread()
{

}

void SocketThread::run()
{
    this->exec();
}

void SocketThread::OnSocketConnected()
{
    emit ShowStatus("Server connected");
    m_bServerConnected = true;
}

void SocketThread::OnSocketDisconnected()
{
    emit ShowStatus("Server disconnected");
    m_bServerConnected = false;
}

void SocketThread::OnSocketError(QAbstractSocket::SocketError error)
{
    emit ShowStatus(m_pTcpSocket->errorString());
}

void SocketThread::ConnectServer()
{
    if(!m_bServerConnected)
    {
        m_pTcpSocket->connectToHost("192.168.2.1", 8745);
        //m_pTcpSocket->waitForConnected(2000);//如果调用这句，界面会卡死
    }
}
