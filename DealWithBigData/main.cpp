#include <QCoreApplication>
#include "BigDataTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BigDataTest bigDataTest;
    bigDataTest.run();

    return a.exec();
}
