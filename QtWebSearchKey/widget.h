#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_USE_NAMESPACE
class QNetworkAccessManager;
QT_END_NAMESPACE

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
    void inputChanged(const QString &text);

protected:
    void resetListWidget(QStringList list);

private:
    Ui::Widget *ui;
    QNetworkAccessManager *m_manager;
};

#endif // WIDGET_H
