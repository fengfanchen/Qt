#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class WindowHand;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void setWidgetStatus(bool status);
    void timerEvent(QTimerEvent *event);

protected slots:
    void setStatusString(bool status);

private:
    Ui::Widget *ui;
    WindowHand *m_windowHand;
};

#endif // WIDGET_H
