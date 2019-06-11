#include "concretedecoratorc.h"
#include "formuserintroduce.h"
#include <QDebug>

ConcreteDecoratorC::ConcreteDecoratorC()
{

}

void ConcreteDecoratorC::processOperation(QWidget *page)
{
    Q_UNUSED(page)
    qDebug() << "ConcreteDecoratorC processOperation called!" << this;
    FormUserIntroduce *user = new FormUserIntroduce;
    Decorator::processOperation(user);
}
