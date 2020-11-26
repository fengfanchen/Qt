#ifndef BOSS_H
#define BOSS_H

#include <QObject>

QT_BEGIN_NAMESPACE
class QSemaphore;
QT_END_NAMESPACE

class Boss : public QObject
{
    Q_OBJECT
public:
    Boss(QSemaphore *sem, QObject *parent = nullptr);
    ~Boss();

public slots:
    void doWork();

private:
    QSemaphore *m_sem;

};

#endif // BOSS_H
