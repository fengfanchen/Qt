#ifndef FORMADMINMODIFYPW_H
#define FORMADMINMODIFYPW_H

#include <QWidget>

namespace Ui {
class FormAdminModifyPW;
}

class FormAdminModifyPW : public QWidget
{
    Q_OBJECT

public:
    explicit FormAdminModifyPW(QWidget *parent = nullptr);
    ~FormAdminModifyPW();

private:
    Ui::FormAdminModifyPW *ui;
};

#endif // FORMADMINMODIFYPW_H
