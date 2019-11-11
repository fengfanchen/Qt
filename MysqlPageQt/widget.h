#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class SQL;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void updateBtnStatus();
    void setTreeWidget();

protected slots:
    void valueChange(int num);
    void upBtnClicked();
    void downBtnClicked();

private:
    Ui::Widget *ui;
    SQL *m_sql;
    int m_count;
    int m_currentPage;
    int m_numInPage;
    int m_countPage;
};

#endif // WIDGET_H
