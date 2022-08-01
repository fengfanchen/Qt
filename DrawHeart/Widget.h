#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QGraphicsScene;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void drawCricle(int x, int y, int height, int width, int startAngle, int endAngle);
    void drawPolygon();

private:
    Ui::Widget *ui;
    QGraphicsScene *m_scene;
};
#endif // WIDGET_H
