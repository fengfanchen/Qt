#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>

class Thread;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void timerEvent(QTimerEvent *event);
    void clearmPvec();
    void addNew();
    void removeOld();

private:
    Ui::Widget *ui;
    Thread *m_thread;
};

#endif // WIDGET_H
