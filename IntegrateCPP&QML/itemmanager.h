#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include <QObject>
#include <QList>

class ItemManager : public QObject
{
    Q_OBJECT
public:
    void addItem(QObject *item);
    QObject *getObject();
    void printTest();
    ~ItemManager();
    static ItemManager *getInstance();


protected:
    explicit ItemManager(QObject *parent = nullptr);
    ItemManager();
    ItemManager(ItemManager &item);

private:
    QList<QObject*> m_item;

    static ItemManager *m_instance;

};

#endif // ITEMMANAGER_H
