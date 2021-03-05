#include <QCoreApplication>
#include "Com.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Com com;

    return a.exec();
}
