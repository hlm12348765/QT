class SocketThread : public QThread
{
    Q_OBJECT

public://public functions
    SocketThread(QObject *parent);
    ~SocketThread();
    void run();

public://public variables
    QTcpSocket* m_pTcpSocket;
    bool m_bServerConnected;
    QTimer m_timer;
    public slots:
        void OnSocketError(QAbstractSocket::SocketError);
        void OnSocketConnected();
        void OnSocketDisconnected();
        void ConnectServer();
signals:
        void ShowStatus(QString str);

private:

};  
