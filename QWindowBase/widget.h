#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Window;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    Window *m_window;
};

#endif // WIDGET_H
