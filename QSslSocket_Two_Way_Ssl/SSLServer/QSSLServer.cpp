#include "QSSLServer.h"
#include <QSslSocket>
#include <QJsonDocument>
#include <QSslCertificate>
#include <QMap>
#include <QFile>
#include <QSslKey>
#include <QDebug>

QSSLServer::QSSLServer(QObject *parent) : QTcpServer(parent)
{
    m_key = new QSslKey;
    m_privateCertificate = new QSslCertificate;
    loadCertificate();
    if(!this->listen(QHostAddress::Any, 19999)){

        qCritical() << "Unable to start the TCP server";
        exit(0);
    }
    connect(this, &QSSLServer::newConnection, this, &QSSLServer::link);
    qDebug() << "The SSLServer started succeefully";
    qDebug() << "port: 19999";
}

QSSLServer::~QSSLServer()
{
    delete m_privateCertificate;
    delete m_key;
}

void QSSLServer::loadCertificate()
{
    QFile p12File(":/res/p_server.p12");
    if(!p12File.open(QIODevice::ReadOnly)){

        qDebug() << "The certificate file open failed!";
        exit(0);
    }

    bool ok = QSslCertificate::importPkcs12(&p12File, m_key, m_privateCertificate, &m_publicCertificateList, "cccccc");
    if(!ok){

        qDebug() << "The certificate import error!";
        exit(0);
    }
    p12File.close();
}

void QSSLServer::incomingConnection(qintptr socketDescriptor)
{
    QSslSocket *sslSocket = new QSslSocket(this);
    connect(sslSocket, SIGNAL(sslErrors(QList<QSslError>)), this, SLOT(sslErrors(QList<QSslError>)));
    sslSocket->setSocketDescriptor(socketDescriptor);
    sslSocket->setPrivateKey(*m_key);
    sslSocket->setLocalCertificate(*m_privateCertificate);
    sslSocket->addCaCertificates(m_publicCertificateList);
    sslSocket->setPeerVerifyMode(QSslSocket::VerifyPeer);
    sslSocket->startServerEncryption();
    addPendingConnection(sslSocket);
}

void QSSLServer::sslErrors(const QList<QSslError> &errors)
{
    foreach(const QSslError &error, errors)
        qDebug() << error.errorString();
}

void QSSLServer::link()
{
    QTcpSocket *clientSocket;
    clientSocket = nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &QSSLServer::rx);
    connect(clientSocket, &QTcpSocket::disconnected, this, &QSSLServer::disconnected);
}

void QSSLServer::rx()
{
    QTcpSocket* clientSocket = qobject_cast<QTcpSocket*>(sender());
    QString clientString = clientSocket->readAll();
    qDebug() << "client:" << clientString;

    //再发一条数据
    clientSocket->write("Hello Client");
}

void QSSLServer::disconnected()
{
    qDebug("Client Disconnected");
    QTcpSocket* clientSocket = qobject_cast<QTcpSocket*>(sender());
    clientSocket->deleteLater();
}
