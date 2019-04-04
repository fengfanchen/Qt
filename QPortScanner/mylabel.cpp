#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent):
    QLabel(parent)
{

}

void MyLabel::setStatus(const int status)
{
    m_status=status;
}

MyLabel::~MyLabel()
{

}

void MyLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        if(m_status==CloseLabel){
            emit prepareToClose();
        }
        else if(m_status==MinLabel){
            emit prepareToMin();
        }
    }
}
