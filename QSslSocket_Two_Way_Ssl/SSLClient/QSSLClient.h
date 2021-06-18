#ifndef QSSLCLIENT_H
#define QSSLCLIENT_H

#include <QObject>
#include <QSslError>

QT_BEGIN_NAMESPACE
class QSslCertificate;
class QSslKey;
class QSslSocket;
QT_END_NAMESPACE

class QSSLClient : public QObject
{
    Q_OBJECT
public:
    QSSLClient(QObject *parent = nullptr);
    ~QSSLClient();
    void connectServer();
    void sendMsg(const QString &msg);
    void closeSocket();

Q_SIGNALS:
    void disconnected(void);

protected:
    void loadCertificate();

private slots:
    void sslErrors(const QList<QSslError> &errors);
    void rx(void);
    void serverDisconnect(void);

private:
    QList<QSslCertificate> m_publicCertificateList;
    QSslCertificate *m_privateCertificate;
    QSslKey *m_key;
    QSslSocket *m_client;
};

#endif // QSSLCLIENT_H
