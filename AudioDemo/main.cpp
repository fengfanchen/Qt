#include <QCoreApplication>
#include <QFile>
#include <QAudioInput>
#include <QAudioFormat>
#include <QEventLoop>
#include <QDebug>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile destinationFile("audio.raw");
    if(!destinationFile.open(QIODevice::WriteOnly | QIODevice::Truncate)){

        qDebug() << "open failed";
        return 0;
    }

    QAudioFormat format;
    // Set up the desired format, for example:
    format.setSampleRate(8000);
    format.setChannelCount(1);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    qDebug() << info.supportedCodecs();
    if (!info.isFormatSupported(format)) {

        qWarning() << "Default format not supported, trying to use the nearest.";
        format = info.nearestFormat(format);
    }

    QAudioInput audio(format);
    audio.start(&destinationFile);

    QEventLoop loop;
    QTimer::singleShot(1000 * 5, &loop, &QEventLoop::quit);
    loop.exec();

    audio.stop();
    destinationFile.close();
    qDebug() << "over";
    return a.exec();
}
