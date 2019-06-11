#ifndef CONCRETEDECORATORB_H
#define CONCRETEDECORATORB_H

#include "decorator.h"

class ConcreteDecoratorB: public Decorator
{
public:
    ConcreteDecoratorB();
    void processOperation(QWidget *page = nullptr);
};

#endif // CONCRETEDECORATORB_H
