#ifndef DECORATOR_H
#define DECORATOR_H

#include "component.h"

class Decorator: public Component
{
public:
    Decorator();
    void setComponent(Component *component);
    void processOperation(QWidget *page = nullptr);

private:
    Component *m_component;
};

#endif // DECORATOR_H
