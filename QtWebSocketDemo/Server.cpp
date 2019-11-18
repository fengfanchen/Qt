#include "Server.h"
#include <QDebug>
#include <QtWebSockets>

Server::Server(quint16 port)
    :QObject(nullptr), m_pWebSocketServer(Q_NULLPTR)
{
    m_pWebSocketServer = new QWebSocketServer("WebSocket Server", QWebSocketServer::NonSecureMode, this);

    if(m_pWebSocketServer->listen(QHostAddress::Any, port)){

        qDebug() << "WebSocket opened, the port is " << port;
        connect(m_pWebSocketServer, &QWebSocketServer::newConnection, this, &Server::onNewConnection);
    }
}

Server::~Server()
{
    m_pWebSocketServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
}

void Server::onNewConnection()
{
    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();
    connect(pSocket, &QWebSocket::textMessageReceived, this, &Server::processMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &Server::socketDisconnected);

    QString localResourceName = pSocket->resourceName();
    int position = localResourceName.lastIndexOf("/");
    m_clients << new PeerHost(localResourceName.right(localResourceName.length() - position - 1), pSocket);
    qDebug() << "new Connection: The name " << pSocket->peerName() << "; The port: " << pSocket->peerPort()
             << "; The IP is " << pSocket->peerAddress();
}

void Server::processMessage(const QString &message)
{
    QWebSocket *pSender = qobject_cast<QWebSocket *>(sender());
    QString sendName = this->getHostName(pSender);
    if(message.left(5) == "name:"){

        QStringList localSplit = message.split(";");
        if(localSplit.size() != 2){

            qDebug() << "message: " << message << "格式错误";
            return;
        }
        QString hostName = localSplit[0].remove("name:");
        sendPointClient(sendName + ":" + localSplit[1], hostName);
    }
    else{

        sendAllClient(sendName + ":" + message);
    }
}

void Server::sendAllClient(const QString &msg)
{
    QWebSocket *pSender = qobject_cast<QWebSocket *>(sender());
    for(PeerHost *pClient : qAsConst(m_clients)){

        if(pClient->m_socket != pSender){

            pClient->m_socket->sendTextMessage(msg);
        }
    }
}

void Server::sendPointClient(const QString &msg, const QString &name)
{
    for(PeerHost *pClient : qAsConst(m_clients)){

        if(pClient->m_name == name){

            pClient->m_socket->sendTextMessage(msg);
            return;
        }
    }
}

void Server::socketDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    for(PeerHost *client : qAsConst(m_clients)){


        qDebug() << client->m_name << " disconnection";

        if(client->m_socket == pClient){

            m_clients.removeAll(client);
            client->m_socket->deleteLater();
        }
    }
}

QString Server::getHostName(QWebSocket *socket)
{
    for(PeerHost *pClient : qAsConst(m_clients)){

        if(pClient->m_socket == socket){

            return pClient->m_name;
        }
    }
}

PeerHost::~PeerHost()
{
    delete m_socket;
}
