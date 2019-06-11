#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class ConcreteComponent;
class ConcreteDecoratorA;
class ConcreteDecoratorB;
class ConcreteDecoratorC;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    ConcreteComponent *m_admin;
    ConcreteComponent *m_user;

    ConcreteDecoratorA *m_a;        //管理员信息模块
    ConcreteDecoratorB *m_b;        //管理员修改密码模块
    ConcreteDecoratorC *m_c;        //用户模块
    ConcreteDecoratorC *m_d;
};

#endif // WIDGET_H
