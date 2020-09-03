#include "client.h"
#include <QDebug>

client::client()
{
    mysocket=new QTcpSocket(this);
}

int client::connectToHost(){
    if(mysocket==NULL) return 2;
    mysocket->connectToHost(serverIP,port);
    int connected=mysocket->waitForConnected();
    mySignInForm=new signInForm();
    myUserForm=new userForm();
    mySignUpForm=new signUpForm();
    mySelectOpponentForm=new selectOpponentForm();
    myBattlefieldForm=new battlefieldForm();
    if(connected){
        mySignInForm->show();
        connect(mysocket,SIGNAL(readyRead()),this,SLOT(preProcessRecvData()));
        connect(mySignUpForm,SIGNAL(showSignInFormReq()),mySignInForm,SLOT(showForm()));
        connect(myUserForm,SIGNAL(showSignInFormReq()),mySignInForm,SLOT(showForm()));
        connect(mySignInForm,SIGNAL(sendMessageReq(QJsonObject*)),this,SLOT(sendMessage(QJsonObject*)));
        connect(myUserForm,SIGNAL(sendMessageReq(QJsonObject*)),this,SLOT(sendMessage(QJsonObject*)));
        connect(mySignUpForm,SIGNAL(sendMessageReq(QJsonObject*)),this,SLOT(sendMessage(QJsonObject*)));
        connect(mySignInForm,SIGNAL(signUpReq()),this,SLOT(processSignUpReq()));
        connect(this,SIGNAL(signIn_accountNotExist()),mySignInForm,SLOT(signIn_accountNotExist()));
        connect(this,SIGNAL(signIn_passwordErr()),mySignInForm,SLOT(signIn_passwordErr()));
        connect(this,SIGNAL(signUp_usernameExisted()),mySignUpForm,SLOT(signUp_usernameExisted()));
        connect(this,SIGNAL(getMyFairy(QJsonObject*)),myUserForm,SLOT(AddMyFairiesTable(QJsonObject*)));
        connect(this,SIGNAL(getUserBag(QJsonObject*)),myUserForm,SLOT(showUserBag(QJsonObject*)));
        connect(myUserForm,SIGNAL(needMyFairies()),this,SLOT(getFairies()));
        connect(myUserForm,SIGNAL(gotoSelectOpponent()),this,SLOT(toSelectOpponent()));
        connect(this,SIGNAL(getBattleFairiesBag(QJsonObject*)),mySelectOpponentForm,SLOT(showBattleFairy(QJsonObject*)));
        connect(mySelectOpponentForm,SIGNAL(gotoBattlefield(int,QJsonObject*,QJsonObject*)),this,SLOT(showBattlefield(int,QJsonObject*,QJsonObject*)));
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
    delete sendBag;
}

void client::preProcessRecvData(){
    QByteArray bytearray=this->mysocket->readAll();
    QString str(bytearray);
    qDebug()<<str;
    QJsonObject *recvdata;
    recvdata=new QJsonObject;
    int event=-1;
    QJsonParseError jsonError;
    QJsonDocument parseDocument=QJsonDocument::fromJson(bytearray,&jsonError);
    qDebug()<<jsonError.error;

    if(jsonError.error==QJsonParseError::NoError){
        if(parseDocument.isObject()){
            *recvdata=parseDocument.object();
            qDebug()<<"the bag has no error.";
            if(recvdata->contains("event")){
                qDebug()<<"the bag has event";
                QJsonValue event_value=recvdata->take("event");
                if(event_value.isDouble())event=event_value.toInt();
            }
        }
    }
    qDebug()<<"get "<<event<<"bag";

    QString tempUsername;
    switch (event) {
    case 0:
        int info;
        if(recvdata->contains("infoType")){
            QJsonValue infoType=recvdata->take("infoType");
            if(infoType.isDouble()) info=infoType.toInt();
        }
        qDebug()<<"get info:"<<info;
        switch (info){
        case 0:
            emit signUp_usernameExisted();
            break;
        case 1:
            mySignUpForm->hide();
            mySignInForm->show();
            break;
        case 2:
            getFairies();
            this->username=mySignInForm->getUserName();
            myUserForm->setUsername(username);
            myUserForm->show();
            mySignInForm->hide();
            break;
        case 3:
            emit signIn_passwordErr();
            break;
        case 4:
            emit signIn_accountNotExist();
            break;
        }
        break;
    case 1:
        qDebug()<<"get fairies bag";
        tempUsername=recvdata->value("username").toString();
        if(tempUsername==*username){
            emit getMyFairy(recvdata);
        }
        break;
    case 2:
        qDebug()<<"get user bag";
        emit getUserBag(recvdata);
        break;
    case 3:
        qDebug()<<"get server fairies name bag";
        emit getBattleFairiesBag(recvdata);
        break;
    }

    delete recvdata;
}

void client::processSignUpReq(){
    mySignUpForm->show();
    mySignInForm->hide();
}

void client::getFairies(){
    QJsonObject* getFairiesBag;
    getFairiesBag=new QJsonObject;
    *getFairiesBag={{"event",3}};
    sendMessage(getFairiesBag);
}

void client::toSelectOpponent(){
    myUserForm->hide();
    mySelectOpponentForm->show();
    QJsonObject *getBattleFairies=new QJsonObject;
    *getBattleFairies={
        {"event",6}
    };
    sendMessage(getBattleFairies);
}

client::~client(){
    delete myUserForm;
    delete mySignInForm;
    delete mySignUpForm;
    delete mySelectOpponentForm;
    delete myBattlefieldForm;
    delete username;
    delete mysocket;
}

void client::showBattlefield(int type,QJsonObject* myBattleFairy,QJsonObject* opponentFairy){
    myBattlefieldForm->setBattlefieldForm(type,myBattleFairy,opponentFairy);
    myBattlefieldForm->show();
    mySelectOpponentForm->hide();
}
