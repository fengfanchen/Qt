#include <QCoreApplication>
#include "QSSLServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSSLServer sslServer;


    return a.exec();
}
