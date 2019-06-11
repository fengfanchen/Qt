#ifndef FORMADMININTRODUCE_H
#define FORMADMININTRODUCE_H

#include <QWidget>

namespace Ui {
class FormAdminIntroduce;
}

class FormAdminIntroduce : public QWidget
{
    Q_OBJECT

public:
    FormAdminIntroduce(QWidget *parent = nullptr);
    ~FormAdminIntroduce();

private:
    Ui::FormAdminIntroduce *ui;
};

#endif // FORMADMININTRODUCE_H
