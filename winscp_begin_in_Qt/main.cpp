#include <QCoreApplication>
#include <QDebug>
#include "pcap.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    pcap_if_t *alldevs;
    pcap_if_t *d;
    int i = 0;
    char errbuf[PCAP_ERRBUF_SIZE];

    //检索本地适配器设备
    if (pcap_findalldevs(&alldevs, errbuf) == -1){

        qDebug() << "Error in pcap_findalldevs_ex: " <<  errbuf;
        return 0;
    }

    //打印
    for(d = alldevs; d != NULL; d= d->next)
    {

        qDebug() << i << ". " << d->name;
        if(d->description){

            qDebug() << d->description;
        }
        else{

            qDebug() << "No description available";
        }
    }

    if(i == 0){

        qDebug() << "No interfaces found! Make sure WinPcap is installed";
        return 0;
    }

    //释放指针
    pcap_freealldevs(alldevs);

    return a.exec();
}
