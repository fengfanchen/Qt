#ifndef SERVER_H
#define SERVER_H

#include <QObject>

QT_BEGIN_NAMESPACE
class QWebSocketServer;
class QWebSocket;
QT_END_NAMESPACE

struct PeerHost{

    PeerHost(const QString &name, QWebSocket *socket){

        m_name = name;
        m_socket = socket;
    }

    ~PeerHost();

    QString m_name = nullptr;
    QWebSocket *m_socket = nullptr;
};

class Server : public QObject
{
    Q_OBJECT
public:
    Server(quint16 port);
    ~Server();

private slots:
    void onNewConnection();
    void processMessage(const QString &msg);
    void socketDisconnected();

protected:
    QString getHostName(QWebSocket *socket);
    void sendAllClient(const QString &msg);
    void sendPointClient(const QString &msg, const QString &name); //指定发送

private:
    QWebSocketServer *m_pWebSocketServer;
    QList<PeerHost *> m_clients;
};

#endif // SERVER_H
