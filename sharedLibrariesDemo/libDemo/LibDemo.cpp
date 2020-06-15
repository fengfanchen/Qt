#include "LibDemo.h"
#include <QPushButton>

LibDemo::LibDemo()
{
    m_btn = Q_NULLPTR;
}

void LibDemo::showNewWidgets()
{
    m_btn = new QPushButton("ABCD1234");
    m_btn->show();
}

void LibDemo::freeWidgets()
{
    if(m_btn != Q_NULLPTR){

        delete m_btn;
        m_btn = Q_NULLPTR;
    }
}
