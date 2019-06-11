#ifndef FORMUSERINTRODUCE_H
#define FORMUSERINTRODUCE_H

#include <QWidget>

namespace Ui {
class FormUserIntroduce;
}

class FormUserIntroduce : public QWidget
{
    Q_OBJECT

public:
    explicit FormUserIntroduce(QWidget *parent = nullptr);
    ~FormUserIntroduce();

private:
    Ui::FormUserIntroduce *ui;
};

#endif // FORMUSERINTRODUCE_H
