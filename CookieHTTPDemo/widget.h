#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_HEADER
class QTcpServer;
class QTcpSocket;
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
    void newConnectionSlot();
    void errorStringSlot();
    void btnClicked();
    void sendMsg();

private:
    Ui::Widget *ui;
    QTcpServer *m_tcpServer;
    QTcpSocket *m_tcpSocket;
};

#endif // WIDGET_H
