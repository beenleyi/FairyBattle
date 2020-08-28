#include "server.h"
#include <QDebug>
#define _event "event"
#define _username "username"
#define _password "password"

myTcpServer::myTcpServer(){
}

int myTcpServer::startListen(){
    if(QTcpServer::listen(QHostAddress::LocalHost,6666)){
        qDebug()<<"[TcpServer]listen succeeded!";
        return 1;
    }
    else{
        qDebug()<<"[TcpServer]listen failed!";
        return 0;
    }
}

void myTcpServer::incomingConnection(int socketDescriptor){
    qDebug()<<"[TcpServer]new connection, no."<<tcpSocketConnectedList.count()+1<<endl;
    QTcpSocket *tempsocket;
    tempsocket=new QTcpSocket;
    tempsocket->setSocketDescriptor(socketDescriptor);
    QString ip = tempsocket->peerAddress().toString();
    quint16 port = tempsocket->peerPort();
    QString temp = QString("[%1:%2]:connection succeeded").arg(ip).arg(port);
    qDebug()<<temp;
    myTcpSocket* mysocket;
    mysocket=new myTcpSocket(tempsocket);
    connect(tempsocket,SIGNAL(readyRead()),mysocket,SLOT(processRecvData()));
    connect(tempsocket,SIGNAL(disconnected()),this,SLOT(processDisconnect()));
    tcpSocketConnectedList.append(mysocket);
}

void myTcpServer::processDisconnect(){
    for(int i=0;i< tcpSocketConnectedList.count();i++){
        myTcpSocket* tempTcpSocket=tcpSocketConnectedList.at(i);
        int temp=tempTcpSocket->qtcpsocket->socketDescriptor();
        if(temp==-1){
            tcpSocketConnectedList.removeAt(i);
            tempTcpSocket->deleteLater();
            qDebug()<<"[TcpServer]Disconnnect:"<<i;
            return;
        }
    }
    return;
}

//void myTcpServer::processRecvData(QJsonObject* recvData, int discriptor){
//    int event;
//    event=recvData->value(_event).toInt();
//    qDebug()<<event;
//    if(event==0) dealWithSignIn(recvData,discriptor);
//}

//void myTcpServer::dealWithSignIn(QJsonObject* recvData, int discriptor){
//    qDebug()<<recvData->value(_username).toString()<<endl<<recvData->value(_password).toString();
//}
