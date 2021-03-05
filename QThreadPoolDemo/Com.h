#ifndef COM_H
#define COM_H

#include <QObject>

QT_BEGIN_NAMESPACE
class QThreadPool;
class QTimer;
QT_END_NAMESPACE

class Com : public QObject
{
    Q_OBJECT
public:
    Com(QObject *parent = nullptr);

protected slots:
    void timeOut();
    void getTime(const QString &time);

private:
    QThreadPool *m_pool;
    QTimer *m_timer;
};

#endif // COM_H
