#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include <QLabel>


#define CloseLabel 0
#define MinLabel 1



class MyLabel : public QLabel
{
    Q_OBJECT
public:
    MyLabel(QWidget *parent=0);
    void setStatus(const int status);
    ~MyLabel();

protected:
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void prepareToClose();
    void prepareToMin();

private:
    int m_status;

};

#endif // MYLABEL_H
