#include "socket.h"

myTcpSocket::myTcpSocket(QTcpSocket* tempsocket){
    qtcpsocket=tempsocket;
}

void myTcpSocket::processRecvData(){
    QJsonObject recvdata;
    QJsonDocument recvdocument;
    QByteArray recvarray= this->qtcpsocket->readAll();
    recvdocument=QJsonDocument::fromJson(recvarray);
    recvdata=recvdocument.object();
    int event=recvdata.value("event").toInt();
    QString username=recvdata.value("username").toString();
    qDebug()<<event<<endl<<username;
}
