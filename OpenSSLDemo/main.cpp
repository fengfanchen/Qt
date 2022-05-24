#include <QCoreApplication>
#include <openssl/crypto.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << OpenSSL_version(0) << std::endl;
    std::cout << OpenSSL_version(1) << std::endl;
    std::cout << OpenSSL_version(2) << std::endl;
    std::cout << OpenSSL_version(3) << std::endl;
    std::cout << OpenSSL_version(4) << std::endl;
    std::cout << OpenSSL_version(5) << std::endl;

    return a.exec();
}

