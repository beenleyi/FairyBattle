#include "server.h"
#include <QDebug>
#define _event "event"
#define _username "username"
#define _password "password"

myTcpServer::myTcpServer(){
    //connect to mysql
    hostName="localhost";
    dbName="fairybattle";
    userName="root";
    password="password";

    dbconn=QSqlDatabase::addDatabase("QMYSQL");
    dbconn.setHostName(hostName);
    dbconn.setDatabaseName(dbName);
    dbconn.setUserName(userName);
    dbconn.setPassword(password);
    qDebug("database open status: %d \n",dbconn.open());
    QSqlError error = dbconn.lastError();
    qDebug()<<error.text();

    //create table
    QSqlQuery createQuery;
    QString createTableStr= "CREATE TABLE user \
        (\
         username VARCHAR(25) NOT NULL,\
         password VARCHAR(25) NOT NULL,\
         online INT\
        );";
    error=dbconn.lastError();
    qDebug()<<error.text();
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
    connect(tempsocket,SIGNAL(readyRead()),mysocket,SLOT(preProcessRecvData()));
    connect(tempsocket,SIGNAL(disconnected()),this,SLOT(processDisconnect()));
    connect(mysocket,SIGNAL(getSignInBag(QJsonObject*)),this,SLOT(processSignInBag(QJsonObject*)));
    connect(mysocket,SIGNAL(getSignUpBag(QJsonObject*)),this,SLOT(processSignUpBag(QJsonObject*)));
    connect(mysocket,SIGNAL(getSignOutBag(QJsonObject*)),this,SLOT(processSignOutBag(QJsonObject*)));
    connect(this,SIGNAL(sendInformation(int)),mysocket,SLOT(sendInfo(int)));
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

void myTcpServer::processSignInBag(QJsonObject* signInBag){
    if(dbconn.open()){
        QSqlQuery query;
        QString queryStr=QString("SELECT * FROM user where username='%1'").arg(signInBag->value("username").toString());
        query.exec(queryStr);
        if(query.next()){
            if(query.value(password).toString()==signInBag->value("password").toString()){
                QSqlQuery updateQuery;
                queryStr=QString("UPDATE user SET online = 1 where username='%1'").arg(signInBag->value("username").toString());
                updateQuery.exec(queryStr);
                sendInformation(2);
            }
            //password error
            else sendInformation(3);
        }else{
            //cannot find your account
            emit sendInformation(4);
        }
    }
    return;
}

void myTcpServer::processSignUpBag(QJsonObject* signUpBag){
    QSqlQuery query;
    QString queryStr=QString("SELECT * FROM user where username='%1'").arg(signUpBag->value("username").toString());
    query.exec(queryStr);
    if(query.next()){
        //username has existed
        emit sendInformation(0);
    }else{
        queryStr=QString("INSERT INTO user (username,password,online)\
                         VALUES\
                         ('%1','%2',%3);").arg(signUpBag->value("username").toString()).arg(signUpBag->value("password").toString()).arg(0);
        query.exec(queryStr);
        //sign up secceed
        emit sendInformation(1);
    }
    //free result?
}

void myTcpServer::processSignOutBag(QJsonObject* signOutBag){
    QSqlQuery query;
    query.prepare("UPDATE user SET online=0 where username=:name");
    query.bindValue(":name",signOutBag->value("username").toString());
}

myTcpServer::~myTcpServer(){
    for(int i=0;i<tcpSocketConnectedList.count();i++)
        delete tcpSocketConnectedList.at(i);
    dbconn.close();
}
