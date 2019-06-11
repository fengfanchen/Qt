#ifndef CONCRETECOMPONENT_H
#define CONCRETECOMPONENT_H

#include "component.h"

QT_BEGIN_NAMESPACE
class QTabWidget;
QT_END_NAMESPACE


class ConcreteComponent: public Component
{
public:
    ConcreteComponent();
    void processOperation(QWidget *page = nullptr);
    void setTabWidget(QTabWidget *tabWidget);

private:
    QTabWidget *m_tabWidget;
};

#endif // CONCRETECOMPONENT_H
