#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include "QSSLClient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSSLClient sslClient;
    sslClient.connectServer();
    sslClient.sendMsg("Hello Server");
    QTimer::singleShot(2 * 1000, &sslClient, &QSSLClient::closeSocket);
    return a.exec();
}
