#ifndef DEMO1_H
#define DEMO1_H

#include <QThread>

class Demo1 : public QThread
{
    Q_OBJECT
    void run() override;

public:
    void setMsg(const QString &msg);

signals:
    void sendMsg(QString msg);

private:
    QString m_msg;
};

#endif // DEMO1_H
