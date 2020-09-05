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
    username=new QString();
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
        connect(myBattlefieldForm,SIGNAL(battleEnd(int,int,int,int,QString*,QString*)),this,SLOT(sendBattleEndBag(int, int, int, int, QString*, QString*)));
        connect(this,SIGNAL(getBattleEndResBag(QJsonObject*)),myBattlefieldForm,SLOT(showBattleRes(QJsonObject*)));
        connect(myBattlefieldForm,SIGNAL(sendLoseAFairyBag(QJsonObject*)),this,SLOT(sendMessage(QJsonObject*)));
        connect(myBattlefieldForm,SIGNAL(showUserFormReq()),this,SLOT(showUserForm()));
        connect(mySelectOpponentForm,SIGNAL(showUserFormReq()),this,SLOT(showUserForm()));
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
    qDebug()<<*sendBag;
    mysocket->write(QJsonDocument(*sendBag).toJson());
    mysocket->waitForBytesWritten();
    delete sendBag;
}

void client::preProcessRecvData(){
    QByteArray bytearray=this->mysocket->readAll();
    QJsonObject *recvdata;
    recvdata=new QJsonObject;
    int event=-1;
    QJsonParseError jsonError;
    QJsonDocument parseDocument=QJsonDocument::fromJson(bytearray,&jsonError);
    //qDebug()<<jsonError.error;

    if(jsonError.error==QJsonParseError::NoError){
        if(parseDocument.isObject()){
            *recvdata=parseDocument.object();
            if(recvdata->contains("event")){
                QJsonValue event_value=recvdata->take("event");
                if(event_value.isDouble())event=event_value.toInt();
            }
        }
    }
    QString tempUsername;
    switch (event) {
    case 0:
    {
        int info=-1;
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
            delete this->username;
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
    }
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
    case 4:
        qDebug()<<"get server battle end bag";
        emit getBattleEndResBag(recvdata);
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

void client::sendBattleEndBag(int battleType, int winOrLose, int countAttack, int countHurt, QString *myfairy, QString *opponent){
    QJsonObject *battleEndBag;
    battleEndBag=new QJsonObject;
    *battleEndBag={
        {"event",7},
        {"battleType", battleType},
        {"winOrLose",winOrLose},
        {"countAttack",countAttack},
        {"countHurt",countHurt},
        {"myFairyName",*myfairy},
        {"opponentName",*opponent}
    };
    sendMessage(battleEndBag);
//    delete myfairy;
//    delete opponent;
}

void client::showUserForm(){
    getFairies();
    myBattlefieldForm->hide();
    mySelectOpponentForm->hide();
    myUserForm->show();
}
