#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QByteArray>
#include <iostream>
#include <string>
#include "TestProtocStruMsg.pb.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file("/XXX/XXX/XXX/probuffDemo/file");

    if(!file.open(QIODevice::ReadOnly)){

        qDebug() << "open failed!";
        return 0;
    }

    QByteArray arr = file.readAll();
    qDebug() << arr;
    file.close();

   TestProtocStru test ;
   if(!test.ParseFromArray(arr.data(), arr.length())){

       qDebug() << "parse failed";
       return 0;
   }

   qDebug() << test.value1().c_str();
   qDebug() << test.value2();
   qDebug() << test.value3();

   //create TestProtocStru
   TestProtocStru *testStru = new TestProtocStru();
   testStru->set_value1("hehehe");
   testStru->set_value2(10010);
   testStru->set_value3(true);

   string s;
   if(!testStru->SerializeToString(&s)){

       qDebug() << "SerializeToString failed!";
      return 0;
   }

   qDebug() << "-------------------------------------------------";

   TestProtocStru test2 ;
   if(!test2.ParseFromArray(s.c_str(), s.length())){

       qDebug() << "parse failed";
       return 0;
   }

   qDebug() << test2.value1().c_str();
   qDebug() << test2.value2();
   qDebug() << test2.value3();

    return a.exec();
}
