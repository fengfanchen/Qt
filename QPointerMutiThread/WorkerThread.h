#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>

class ProjectData;

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    WorkerThread();
    void setProjectData(ProjectData *project);
    void run() Q_DECL_OVERRIDE;
    bool stopFlag;

private:
    ProjectData *m_project;
};

#endif // WORKERTHREAD_H
