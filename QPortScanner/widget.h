#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPoint>
#include <QMap>

class QTimer;
class MyNetWork;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

protected:
    bool checkIpLineEditProperty();

protected slots:
    void showDynamicTime();
    void windowsClose();
    void windowsShowMin();
    void btnClicked();

    void progressBarIncreament();
    void updateListWidget(int port);


private:
    Ui::Widget *ui;
    QPoint z;
    QTimer *m_pTimer;
    MyNetWork *m_netWork[10];
    QMap<int,QString> m_sucessPort;

};

#endif // WIDGET_H
