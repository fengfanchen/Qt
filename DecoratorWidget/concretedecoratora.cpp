#include "concretedecoratora.h"
#include "formadminintroduce.h"
#include <QDebug>

ConcreteDecoratorA::ConcreteDecoratorA()
{

}


void ConcreteDecoratorA::processOperation(QWidget *page)
{
    Q_UNUSED(page)

    qDebug() << "ConcreteDecoratorA processOperation called!" << this;
    FormAdminIntroduce *adminForm = new FormAdminIntroduce;
    Decorator::processOperation(adminForm);
}
