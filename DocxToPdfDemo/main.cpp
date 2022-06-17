#include <QAxObject>
#include <QAxWidget>
#include <QDebug>
#include <QApplication>
#include <QFile>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDir dir("D:\\数学");
    if(!dir.exists()){

        qDebug() << "dir error";
        return 0;
    }

    dir.setFilter(QDir::Files | QDir::NoSymLinks);
    QFileInfoList list = dir.entryInfoList();
    for(int i = 0; i < list.size(); i++){

        QFileInfo fileInfo = list.at(i);
        QString fileName = fileInfo.fileName();
        QString filePath = fileInfo.absoluteFilePath();
        QString dirName = dir.path();

        QAxWidget word("Word.Application");
        word.setProperty("Visible", false);
        QAxObject * documents = word.querySubObject("Documents");
        QAxObject * document = documents->querySubObject("Open(QString)", filePath);


        QVariant OutputFileName(dirName + "/" + fileName.mid(0, fileName.lastIndexOf(".")) + ".pdf");
        QVariant ExportFormat(17);
        QVariant OpenAfterExport(false);


        document->querySubObject("ExportAsFixedFormat(const QVariant&,const QVariant&,const QVariant&)",
                                 OutputFileName,
                                 ExportFormat,
                                 OpenAfterExport);


        document->dynamicCall("Close(boolean)",false);
        word.dynamicCall("Quit (void)");

        qDebug() << filePath + " to pdf success";
    }

    return a.exec();
}
