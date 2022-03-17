#include <QCoreApplication>
#include <QDebug>
#include <Windows.h>

const char *pipeNamePtr = "\\\\.\\pipe\\test_pip";
const int pipeBufferSize = 65535;

HANDLE namedCreateNamedPipe = CreateNamedPipeA(pipeNamePtr,
                                              PIPE_ACCESS_DUPLEX,
                                              PIPE_TYPE_MESSAGE | PIPE_WAIT | PIPE_READMODE_MESSAGE,
                                              PIPE_UNLIMITED_INSTANCES,
                                              0,
                                              0, NMPWAIT_WAIT_FOREVER, nullptr);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(namedCreateNamedPipe == INVALID_HANDLE_VALUE){

        qDebug() << "error : " << namedCreateNamedPipe;
        return 0;
    }

    qDebug() << "namedCreateNamedPipe : " << namedCreateNamedPipe;

    if(!ConnectNamedPipe(namedCreateNamedPipe, nullptr)){

        qDebug() << "ConnectNamedPipe failed";
        return 0;
    }
    qDebug() << "connected";


    while(true){

        char buffer[pipeBufferSize];
        DWORD lenth = 0;
        if(!ReadFile(namedCreateNamedPipe, buffer, pipeBufferSize, &lenth, nullptr)){

            qDebug() << "read failed : " << GetLastError();
            break;
        }

        qDebug() << "receive : " << buffer;

        DWORD writeNum;
        QString over = "over";
        if(!WriteFile(namedCreateNamedPipe, over.toStdString().c_str(), over.length(), &writeNum, nullptr)){

            qDebug() << "WriteFile failed : " << GetLastError();
            break;
        }

    }

    DisconnectNamedPipe(namedCreateNamedPipe);
    CloseHandle(namedCreateNamedPipe);

    return a.exec();
}
