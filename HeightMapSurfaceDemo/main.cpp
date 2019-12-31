#include <QApplication>
#include <QtDataVisualization>
#include <QHeightMapSurfaceDataProxy>
#include <QSurface3DSeries>
#include <QImage>

using namespace QtDataVisualization;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Q3DSurface surface;
    surface.setFlags(surface.flags() ^ Qt::FramelessWindowHint);
    surface.resize(800, 600);
    surface.show();

    //添加数据
    QImage image(":/img/Heightmap4.png");
    QHeightMapSurfaceDataProxy *proxy = new QHeightMapSurfaceDataProxy(image);
    proxy->setValueRanges(0.0f, 500.0f, 0.0f, 500.0f);
    QSurface3DSeries *series = new QSurface3DSeries(proxy);
    series->setDrawMode(QSurface3DSeries::DrawSurface);
    series->setFlatShadingEnabled(false);
    surface.addSeries(series);

    return a.exec();
}
