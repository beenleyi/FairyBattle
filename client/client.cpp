#include "client.h"
#include <QDebug>

client::client()
{
    mysocket=new QTcpSocket;
}

int client::connectToHost(){
    if(mysocket==NULL) return 2;
    mysocket->connectToHost(serverIP,port);
    int connected=mysocket->waitForConnected();
    if(connected){
        connect(mysocket,SIGNAL(readyRead()),this,SLOT(preProcessRecvData()));
        return 1;
    }else{
        QMessageBox messageBox(QMessageBox::NoIcon,
                               "Error", "Cannot connect to server.\nCheck your network and make sure that server is open.",
                               QMessageBox::Ok, NULL);
        int result=messageBox.exec();
        switch (result)
        {
        case QMessageBox::Ok:
            close();
            break;
        default:
            break;
        }
        return 0;
    }

}

void client::sendMessage(QJsonObject *sendBag){
    mysocket->write(QJsonDocument(*sendBag).toJson());
    mysocket->waitForBytesWritten();
}

void client::preProcessRecvData(){
    QJsonObject *recvdata;
    recvdata=new QJsonObject;
    *recvdata=QJsonDocument::fromJson(this->mysocket->readAll()).object();
    int event=recvdata->value("event").toInt();
    switch (event) {
    case 0:
        emit signUp_usernameExisted();
        break;
    case 1:
        emit signUp_signUpSecceed();
        break;
    case 2:
        emit signIn_signInSecceed();
        break;
    case 3:
        emit signIn_passwordErr();
        break;
    case 4:
        emit signIn_accountNotExist();
        break;
    }
}
