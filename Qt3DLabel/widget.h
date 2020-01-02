#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
namespace QtDataVisualization{
    class Q3DSurface;
    class QCustom3DLabel;
}
class QPropertyAnimation;
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void handleElementSelected(int type);

protected:
    void createLabel(const QString text);

private:
    Ui::Widget *ui;
    QtDataVisualization::Q3DSurface *m_surface;
    QtDataVisualization::QCustom3DLabel *m_label;
    QPropertyAnimation *m_selectionAnimation;
};
#endif // WIDGET_H
