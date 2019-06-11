#include "concretecomponent.h"
#include <QWidget>
#include <QTabWidget>
#include <QDebug>

ConcreteComponent::ConcreteComponent()
{
    m_tabWidget = nullptr;
}

void ConcreteComponent::processOperation(QWidget *page)
{
    if(page == nullptr && m_tabWidget == nullptr)
        return;

    qDebug() << "add admin widget";
    m_tabWidget->addTab(page, page->windowTitle());
}

void ConcreteComponent::setTabWidget(QTabWidget *tabWidget)
{
    m_tabWidget = tabWidget;
}
