#include "client.h"
#include <QDebug>

client::client()
{
    mysocket=new QTcpSocket;
    mysocket->connectToHost(serverIP,port);
    int connected=mysocket->waitForConnected();
    connect(mysocket,&QTcpSocket::readyRead,[=](){
        QByteArray buf=mysocket->readAll();
    }
    );
}

void client::sendMessage(QJsonObject *sendBag){
    mysocket->write(QJsonDocument(*sendBag).toJson());
    mysocket->waitForBytesWritten();
}
