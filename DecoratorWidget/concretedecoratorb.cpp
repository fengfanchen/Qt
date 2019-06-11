#include "concretedecoratorb.h"
#include "formadminmodifypw.h"
#include <QDebug>

ConcreteDecoratorB::ConcreteDecoratorB()
{

}

void ConcreteDecoratorB::processOperation(QWidget *page)
{
    Q_UNUSED(page)
    qDebug() << "ConcreteDecoratorB processOperation called!" << this;
    FormAdminModifyPW *adminForm = new FormAdminModifyPW;
    Decorator::processOperation(adminForm);
}
