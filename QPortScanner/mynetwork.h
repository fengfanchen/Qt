#ifndef MYNETWORK_H
#define MYNETWORK_H

#include <QObject>
#include <QThread>

class QTcpSocket;

class MyNetWork:public QObject
{
    Q_OBJECT
public:
    MyNetWork(QObject *parent=0);
    ~MyNetWork();

    void setIp(const QString ip);
    void setStartPort(const int startPort);
    void setEndPort(const int endPort);

public slots:
    void beginToScanner();

signals:
    void progressBarAdd();
    void pcIsConnected(int port);

private:
    QTcpSocket *m_tcpSocket;
    QThread m_thread;

    int m_startPort;
    int m_endPort;
    QString m_ip;
};

#endif // MYNETWORK_H
