#ifndef CONCRETEDECORATORA_H
#define CONCRETEDECORATORA_H

#include "decorator.h"

class ConcreteDecoratorA: public Decorator
{
public:
    ConcreteDecoratorA();
    void processOperation(QWidget *page = nullptr);
};

#endif // CONCRETEDECORATORA_H
