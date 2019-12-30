#include "window.h"
#include <QBackingStore>
#include <QPainter>
#include <QDebug>
#include <QResizeEvent>

Window::Window(QWindow *parent): QWindow(parent)
{
    m_str = "heheda";
    create();
    m_backingStore = new QBackingStore(this);
    setGeometry(100, 100, 300, 200);
}

bool Window::event(QEvent *event)
 {
     if (event->type() == QEvent::UpdateRequest) {
         renderNow();
         return true;
     }
     return QWindow::event(event);
 }

 void Window::renderLater()
 {
     requestUpdate();
 }

 void Window::resizeEvent(QResizeEvent *resizeEvent)
 {
     m_backingStore->resize(resizeEvent->size());
     if (isExposed())
         renderNow();
 }

 void Window::exposeEvent(QExposeEvent *)
 {
     if (isExposed())
         renderNow();
 }

 void Window::renderNow()
 {
     if (!isExposed())
         return;

     QRect rect(0, 0, width(), height());
     m_backingStore->beginPaint(rect);

     QPaintDevice *device = m_backingStore->paintDevice();
     QPainter painter(device);

     painter.fillRect(0, 0, width(), height(), Qt::white);
     render(&painter);

     m_backingStore->endPaint();
     m_backingStore->flush(rect);
 }

 void Window::getMsg(const QString &str)
 {
     m_str = str;
     this->requestUpdate();
 }

 void Window::render(QPainter *painter)
 {
     painter->drawText(QRectF(0, 0, width(), height()), Qt::AlignCenter, m_str);
 }

 void Window::setStr(const QString &str)
 {
     m_str = str;
 }
