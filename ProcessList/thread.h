#ifndef THREAD_H
#define THREAD_H

#include <QVector>
#include <QString>

struct ProcessInfo{

    QString processID;              //进程ID
    QString threadNum;              //该进程开启的线程数
    QString parentProcessID;        //父进程ID
    QString processPri;             //线程优先权
    QString processHandle;          //进程句柄
    QString processName;            //名称
};


class Thread
{
public:
    Thread();
    void getSnapshot();
    const QVector<ProcessInfo> &getVec();
    void clearVec();

protected:
    void insertInfo(const QString &pID, const QString &thrNum,
                    const QString &parePID, const QString &processPr,
                    const QString &handle, const QString &processName);

private:

    QVector<ProcessInfo> m_vec;
};

#endif // THREAD_H
