#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <Windows.h>

using namespace std;

const char *pipeNamePtr = "\\\\.\\pipe\\test_pip";
const int pipeBufferSize = 65535;


HANDLE namedCreateNamedPipe = CreateFileA(pipeNamePtr,
                                               GENERIC_READ | GENERIC_WRITE,
                                               0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(namedCreateNamedPipe == INVALID_HANDLE_VALUE){

        qDebug() << "error : " << namedCreateNamedPipe;
        return 0;
    }

    qDebug() << "namedCreateNamedPipe : " << namedCreateNamedPipe;

    while(true){

        DWORD writeNum;
        char buffer[pipeBufferSize];
        cout << "my >";
        cin >> buffer;
        if(!WriteFile(namedCreateNamedPipe, buffer, pipeBufferSize, &writeNum, nullptr)){

            qDebug() << "write failed";
            break;
        }

        DWORD lenth = 0;
        if(!ReadFile(namedCreateNamedPipe, buffer, pipeBufferSize, &lenth, nullptr)){

            qDebug() << "read failed : " << GetLastError();
            break;
        }

        qDebug() << "server >" << buffer;
    }

    CloseHandle(namedCreateNamedPipe);

    return a.exec();
}
