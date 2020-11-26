#ifndef WORKER_H
#define WORKER_H

#include <QObject>

QT_BEGIN_NAMESPACE
class QSemaphore;
QT_END_NAMESPACE

class Worker : public QObject
{
    Q_OBJECT
public:
    Worker(QSemaphore *sem, QString name, QObject *parent = nullptr);
    ~Worker();

public slots:
    void doWork();

private:
    QString m_name;
    QSemaphore *m_sem;
};

#endif // WORKER_H
