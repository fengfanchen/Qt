#include "mynetwork.h"

#include <QTcpSocket>
#include <QDebug>

MyNetWork::MyNetWork(QObject *parent):QObject(parent)
{
    m_ip="127.0.0.1";
    m_startPort=0;
    m_endPort=0;
    m_tcpSocket=new QTcpSocket(this);
    m_thread.start();
    m_thread.setPriority(QThread::TimeCriticalPriority);
    moveToThread(&m_thread);
}

MyNetWork::~MyNetWork()
{

}

void MyNetWork::setIp(const QString ip)
{
    m_ip=ip;
}

void MyNetWork::setStartPort(const int startPort)
{
    m_startPort=startPort;
}

void MyNetWork::setEndPort(const int endPort)
{
    m_endPort=endPort;
}

void MyNetWork::beginToScanner()
{
    if((m_ip=="127.0.0.1")||(m_startPort==0&&m_endPort==0))
        return;

    for(int i=m_startPort;i<=m_endPort;i++){
        m_tcpSocket->abort();
        m_tcpSocket->connectToHost(m_ip,i);
        if(m_tcpSocket->waitForConnected(500)){
            emit pcIsConnected(i);
        }
        emit progressBarAdd();
    }
}
