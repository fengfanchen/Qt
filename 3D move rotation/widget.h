#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtDataVisualization/q3dscatter.h>

namespace Ui {
class Widget;
}

QT_BEGIN_NAMESPACE
class QTimer;
QT_END_NAMESPACE

using namespace QtDataVisualization;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QWidget *getWidgetContent();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private:
    Ui::Widget *ui;
    QTimer *m_timer;
    QTimer *m_rotationTimer;
    Q3DScatter *m_graph;
};

#endif // WIDGET_H
