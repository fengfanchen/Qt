#include "thumbnailer.h"
#include <QWebFrame>
#include <QImage>
#include <QPainter>

Thumbnailer::Thumbnailer(const QUrl &url)
{
    page.mainFrame()->load(url);
    connect(&page, SIGNAL(loadFinished(bool)), this, SLOT(render()));
}

Thumbnailer::~Thumbnailer()
{

}

void Thumbnailer::render()
{
    page.setViewportSize(page.mainFrame()->contentsSize());
    QImage image(page.viewportSize(), QImage::Format_ARGB32);
    QPainter painter(&image);

    page.mainFrame()->render(&painter);
    painter.end();

    QImage thumbnail = image.scaled(400, 400);
    thumbnail.save("thumbnail.png");
    image.save("original.png");
    emit finished();
}
