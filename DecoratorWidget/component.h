#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>

QT_BEGIN_NAMESPACE
class QWidget;
QT_END_NAMESPACE

class Component
{
public:
    virtual void processOperation(QWidget *page = nullptr);

protected:
    Component();
};

#endif // COMPONENT_H
