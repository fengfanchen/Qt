#include <QCoreApplication>
#include <adapters/qt.h>
#include <QDebug>

void getCallback(redisAsyncContext *ctx, void *r, void *privdata){

    qDebug() << "getCallback called";

    redisReply *reply = static_cast<redisReply*>(r);
    if(reply == nullptr){

        qDebug() << "The reply is nullptr";
        return;
    }

    qDebug() << "result: ";

    for(int i = 0; i < reply->elements; i++){

        qDebug() << "key: " << reply->element[i]->str;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    redisAsyncContext *ctx = redisAsyncConnect("XXX.XXX.XXX.XXX", 6379);

    RedisQtAdapter adapter;

    if(ctx->err){

        qDebug()<< "error: " << ctx->errstr;
        redisAsyncFree(ctx);
        return 0;
    }
    adapter.setContext(ctx);

    redisAsyncCommand(ctx, nullptr, nullptr, "auth XXXXXXX");
    redisAsyncCommand(ctx, getCallback, nullptr, "KEYS *");
    qDebug() << "over";

    return a.exec();
}

