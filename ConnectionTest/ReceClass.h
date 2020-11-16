#ifndef RECECLASS_H
#define RECECLASS_H

#include <QObject>

class ReceClass : public QObject
{
    Q_OBJECT
public:
    explicit ReceClass(QObject *parent = nullptr);

public slots:
    void receMsg(QString msg);
};

#endif // RECECLASS_H
