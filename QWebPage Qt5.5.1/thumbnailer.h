#ifndef THUMBNAILER_H
#define THUMBNAILER_H

#include <QObject>
#include <QWebPage>
#include <QUrl>

class Thumbnailer : public QObject
{
    Q_OBJECT

public:
    Thumbnailer(const QUrl &url);
    ~Thumbnailer();

Q_SIGNALS:
    void finished();

private Q_SLOTS:
    void render();

private:
    QWebPage page;
};

#endif // THUMBNAILER_H
