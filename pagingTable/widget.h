#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>

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
    void setListWidget(const int &currentPage);

protected slots:
    void upBtnClicked();
    void downBtnClicked();

private:
    Ui::Widget *ui;
    QVector<QString> m_vec;
    int m_pageCount;

    int m_currentPageNum;   //当前页数
    int m_countPageNum;        //总页数
};

#endif // WIDGET_H
