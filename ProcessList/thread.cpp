#include "thread.h"
#include <windows.h>
#include <tlhelp32.h>
#include <QDebug>

Thread::Thread()
{
//    getSnapshot();
}

void Thread::getSnapshot()
{
    HANDLE hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    if(!hProcess){

        qDebug() << "CreateToolhelp32Snapshot failed!";
        return;
    }

    PROCESSENTRY32 info;
    info.dwSize = sizeof(PROCESSENTRY32);
    if(!Process32First(hProcess, &info)){

        qDebug() << "Process32First null";
        return;
    }

    bool haveNext = true;
    while(haveNext){

        haveNext = Process32Next(hProcess, &info);
        if(haveNext){

            HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, TRUE, info.th32ProcessID);

            insertInfo(QString::number(info.th32ProcessID), QString::number(info.cntUsage),
                       QString::number(info.th32ParentProcessID), QString::number(info.pcPriClassBase),
                       QString::number((DWORD)hProcess), QString::fromWCharArray(info.szExeFile));

//            qDebug() << info.th32ProcessID << "  " << info.pcPriClassBase << "  " << QString::fromWCharArray(info.szExeFile) << "  " << hProcess;
        }
    }
//    qDebug() << "Over!";
}

const QVector<ProcessInfo> &Thread::getVec()
{
    return m_vec;
}

void Thread::clearVec()
{
    m_vec.clear();
}

void Thread::insertInfo(const QString &pID, const QString &thrNum,
                        const QString &parePID, const QString &processPr,
                        const QString &handle, const QString &processName)
{
    ProcessInfo info;
    info.processID = pID;
    info.threadNum = thrNum;
    info.parentProcessID = parePID;
    info.processPri = processPr;
    info.processHandle = handle;
    info.processName = processName;

    m_vec.append(info);
}
