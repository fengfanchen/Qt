#ifndef CONCRETEDECORATORC_H
#define CONCRETEDECORATORC_H

#include "decorator.h"

class ConcreteDecoratorC: public Decorator
{
public:
    ConcreteDecoratorC();
    void processOperation(QWidget *page = nullptr);
};

#endif // CONCRETEDECORATORC_H
