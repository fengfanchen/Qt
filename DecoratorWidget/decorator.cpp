#include "decorator.h"
#include <QWidget>
#include <QDebug>

Decorator::Decorator()
{
    m_component = nullptr;
}

void Decorator::setComponent(Component *component)
{
    m_component = component;
    processOperation();
}

void Decorator::processOperation(QWidget *page)
{
    if(page == nullptr)
        return;

    qDebug() << "Decorator processOperation called!" << m_component;

    m_component->processOperation(page);
}
