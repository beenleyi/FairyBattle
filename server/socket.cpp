#include "socket.h"

myTcpSocket::myTcpSocket(QTcpSocket* tempsocket){
    qtcpsocket=tempsocket;
}

void myTcpSocket::preProcessRecvData(){
    QJsonObject *recvdata;
    recvdata=new QJsonObject;
    *recvdata=QJsonDocument::fromJson(this->qtcpsocket->readAll()).object();
    int event=recvdata->value("event").toInt();
    if(event==0)//sign in
        emit getSignInBag(recvdata);
    else if(event==1)
        emit getSignUpBag(recvdata);
    else if(event==2)
        emit getSignOutBag(recvdata);
}

void myTcpSocket::sendInfo(int infoType){
    QJsonObject *info;
    info=new QJsonObject;
    *info={{"event",infoType}};
    qtcpsocket->write(QJsonDocument(*info).toJson());
    qtcpsocket->waitForBytesWritten();
}
