#define HAVE_REMOTE

#include <QCoreApplication>
#include <QDebug>
#include "pcap.h"
#include "remote-ext.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString devName;
    //获取网卡
    pcap_if_t *allDevs;
    char errbuf[PCAP_ERRBUF_SIZE];
    if(pcap_findalldevs(&allDevs, errbuf) == -1){

        qDebug() << "error:" << errbuf;
        return 0;
    }

    devName = allDevs->name;

    pcap_freealldevs(allDevs);


    //打卡网卡
    pcap_t *fp;
    u_char packet[100];

    if((fp= pcap_open(devName.toStdString().c_str(), 100, PCAP_OPENFLAG_PROMISCUOUS, 1000, NULL, errbuf)) == NULL){

        qDebug() << "error:" << errbuf;
        return 0;
    }

    packet[0]=1;
    packet[1]=1;
    packet[2]=1;
    packet[3]=1;
    packet[4]=1;
    packet[5]=1;

    packet[6]=2;
    packet[7]=2;
    packet[8]=2;
    packet[9]=2;
    packet[10]=2;
    packet[11]=2;

    for(int i = 12; i < 100; i++){

        packet[i]=0xFF;
    }

    if(pcap_sendpacket(fp, packet, 100) != 0){

        qDebug() << "send error:" << pcap_geterr(fp);
        return 0;
    }

    qDebug() << "over";

    return a.exec();
}
