#include "socket.h"

myTcpSocket::myTcpSocket(QTcpSocket* tempsocket){
    qtcpsocket=tempsocket;
    username=NULL;
}

void myTcpSocket::preProcessRecvData(){
    QJsonObject *recvdata;
    recvdata=new QJsonObject;
    *recvdata=QJsonDocument::fromJson(this->qtcpsocket->readAll()).object();
    int event=recvdata->value("event").toInt();
    switch (event) {
    case 0:
        username=new QString;
        *username=recvdata->value("username").toString();
        emit getSignInBag(recvdata,this->qtcpsocket->socketDescriptor());
        qDebug()<<"get sign in bag";
        break;
    case 1:
        qDebug()<<"get sign up bag";
        emit getSignUpBag(recvdata,this->qtcpsocket->socketDescriptor());
        break;
    case 2:
        qDebug()<<"get sign out bag:";
        qDebug()<<*username;
        emit getSignOutBag(username);
        delete username;
        break;
    case 3:
        qDebug()<<"get my fairy req bag";
        emit getUserFairiesReq(username,this->qtcpsocket->socketDescriptor());
        break;
    case 4:
        qDebug()<<"get online user req bag";
        emit getUserReq(username,1,this->qtcpsocket->socketDescriptor());
        break;
    case 5:
        qDebug()<<"get all user req bag";
        emit getUserReq(username,0,this->qtcpsocket->socketDescriptor());
        break;
    case 6:
        qDebug()<<"get server fairies req bag";
        emit getBattleFairiesReqBag(username,this->qtcpsocket->socketDescriptor());
        break;
    }

}

void myTcpSocket::send(QJsonObject* data){
    qDebug()<<"this socket is"<<this->qtcpsocket->socketDescriptor();
    qtcpsocket->write(QJsonDocument(*data).toJson());
    delete data;
}

void myTcpSocket::preProcessDisconnect(){
    emit clientDisconnect(username);
}
