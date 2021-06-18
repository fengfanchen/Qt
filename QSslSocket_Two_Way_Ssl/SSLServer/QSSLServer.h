#ifndef QSSLSERVER_H
#define QSSLSERVER_H

#include <QObject>
#include <QList>
#include <QTcpServer>
#include <QSslError>

QT_BEGIN_NAMESPACE
class QSslCertificate;
class QSslKey;
class QSslSocket;
QT_END_NAMESPACE

class QSSLServer : public QTcpServer
{
    Q_OBJECT
public:
    QSSLServer(QObject *parent = nullptr);
    ~QSSLServer();

protected:
    void loadCertificate();
    void incomingConnection(qintptr socketDescriptor) Q_DECL_OVERRIDE;

private slots:
    void sslErrors(const QList<QSslError> &errors);
    void link();
    void rx();
    void disconnected();

private:
    QList<QSslCertificate> m_publicCertificateList;
    QSslCertificate *m_privateCertificate;
    QSslKey *m_key;
    QSslSocket *m_client;
};

#endif // QSSLSERVER_H
