#ifndef PROJECTDATA_H
#define PROJECTDATA_H

#include <QObject>
#include <QPointer>
#include <QDebug>

class ProjectData : public QObject
{
    Q_OBJECT
public:
    ProjectData(QObject *parent = nullptr);
    void addItem(QObject *item);
    int getSize();
    QObject *getItem();
    QList<QObject*> getAll();

private:
    QList<QObject*> m_objList;
};

#endif // PROJECTDATA_H
