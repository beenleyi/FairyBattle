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
        connect(mysocket,&QTcpSocket::readyRead,[=](){
            QByteArray buf=mysocket->readAll();
        }
        );
        return 1;
    }else{
        QMessageBox messageBox(QMessageBox::NoIcon,
                               "Error", "Cannot connect to server.\nCheck your network and make sure that server is open.",
                               QMessageBox::Yes, NULL);
        int result=messageBox.exec();


        switch (result)
        {
        case QMessageBox::Yes:
            qDebug()<<"Yes";
            close();
            break;
        case QMessageBox::No:
            qDebug()<<"NO";
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
