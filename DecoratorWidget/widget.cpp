#include "widget.h"
#include "ui_widget.h"
#include "concretecomponent.h"
#include "concretedecoratora.h"
#include "concretedecoratorb.h"
#include "concretedecoratorc.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_admin = new ConcreteComponent;
    m_admin->setTabWidget(ui->adminTabWidget);

    m_user = new ConcreteComponent;
    m_user->setTabWidget(ui->userTabWidget);

    //管理员模块加载
    //m_a = new ConcreteDecoratorA;
    //m_a->setComponent(m_admin);

    m_b = new ConcreteDecoratorB;
    m_b->setComponent(m_admin);

    m_c = new ConcreteDecoratorC;
    m_c->setComponent(m_admin);

    m_d = new ConcreteDecoratorC;
    m_d->setComponent(m_user);
}

Widget::~Widget()
{
    delete m_user;
    delete m_admin;
    delete m_a;
    delete m_b;
    delete m_d;
    delete m_c;
    delete ui;
}
