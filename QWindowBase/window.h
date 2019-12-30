#ifndef WINDOW_H
#define WINDOW_H

#include <QObject>
#include <QWindow>

QT_BEGIN_NAMESPACE
class QPainter;
class QBackingStore;
QT_END_NAMESPACE

class Window : public QWindow
{
    Q_OBJECT
public:
    Window(QWindow *parent = 0);
    void render(QPainter *painter);
    void setStr(const QString &str);

public slots:
    void renderLater();
    void renderNow();
    void getMsg(const QString &str);

protected:
    bool event(QEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;
    void exposeEvent(QExposeEvent *event) override;

private:
    QBackingStore *m_backingStore;
    QString m_str;

};

#endif // WINDOW_H
