#ifndef WORK_H
#define WORK_H

#include <QObject>
#include <QRunnable>

class Work : public QObject, public QRunnable
{
    Q_OBJECT
public:
    Work();
    ~Work();

protected:
    void run() Q_DECL_OVERRIDE;

signals:
    void nowTime(const QString &time);
};

#endif // WORK_H
