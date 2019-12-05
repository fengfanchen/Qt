#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected slots:
    void btnClicked();

protected:
    bool isOK(QString str);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
