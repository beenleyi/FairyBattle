#include "server.h"
#include <QDebug>
#define _event "event"
#define _username "username"
#define _password "password"
/*创建服务器，创建数据库和数据表，有user和fairies两张表*/
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

    //create user table
    QSqlQuery query;
    QString queryStr=QString("CREATE TABLE IF NOT EXISTS `user`(\
        `username` VARCHAR(20) NOT NULL,\
        `password` VARCHAR(20) NOT NULL,\
        `FayeNum` INT,\
        `HebeNum` INT,\
        `LalaNum` INT,\
        `SquirrelNum` INT,\
        `KayNum` INT,\
        `BeenleNum` INT,\
        `battleCount` INT,\
        `winCount` INT,\
        `FairiesNumBadge` INT,\
        `FairiesStageBadge` INT,\
        `online` INT)");
    query.exec(queryStr);
    error=dbconn.lastError();
    qDebug()<<error.text();

    //create fairies table
    queryStr=QString("CREATE TABLE IF NOT EXISTS `fairies`(\
                         `username` VARCHAR(20) NOT NULL,\
                         `fairyname` VARCHAR(20) NOT NULL,\
                         `no` INT,\
                         `type` INT,\
                         `stage` INT,\
                         `experience` INT,\
                         `aggressivity` INT,\
                         `defense` INT,\
                         `life` INT,\
                         `attack_interval` INT)");
    query.exec(queryStr);
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

/*连接成功，创建所有信号和槽的连接*/
void myTcpServer::incomingConnection(int socketDescriptor){
    qDebug()<<"[TcpServer]new connection, no."<<tcpSocketConnectedList.count()+1<<socketDescriptor<<endl;
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
    connect(tempsocket,SIGNAL(disconnected()),mysocket,SLOT(preProcessDisconnect()));
    connect(mysocket,SIGNAL(clientDisconnect(QString*)),this,SLOT(processDisconnect(QString*)));
    connect(mysocket,SIGNAL(getSignInBag(QJsonObject*, qintptr)),this,SLOT(processSignInBag(QJsonObject*, qintptr)));
    connect(mysocket,SIGNAL(getSignUpBag(QJsonObject*, qintptr)),this,SLOT(processSignUpBag(QJsonObject*, qintptr)));
    connect(mysocket,SIGNAL(getSignOutBag(QString*)),this,SLOT(processSignOutBag(QString*)));
    connect(mysocket,SIGNAL(getUserFairiesReq(QString*, qintptr)),this,SLOT(processUserFairiesReq(QString*, qintptr)));
    connect(mysocket,SIGNAL(getUserReq(QString*, int, qintptr)),this,SLOT(processUserReq(QString*, int, qintptr)));
    connect(mysocket,SIGNAL(getBattleFairiesReqBag(QString*,qintptr)),this,SLOT(processBattleFairiesReq(QString*,qintptr)));
    connect(mysocket,SIGNAL(getBattleEndBag(QJsonObject*,QString*,qintptr)),this,SLOT(processBattleEnd(QJsonObject*,QString*,qintptr)));
    connect(mysocket,SIGNAL(getLoseAFairyBag(QJsonObject*,QString*)),this,SLOT(processLoseAFairy(QJsonObject*,QString*)));
    tcpSocketConnectedList.append(mysocket);
}

void myTcpServer::processDisconnect(QString* tempUsername){
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

void myTcpServer::processSignInBag(QJsonObject* signInBag,qintptr socketDescriptor){
    QString * tempUsername;
    tempUsername=new QString;
    *tempUsername=signInBag->value("username").toString();
    if(dbconn.open()){
        QSqlQuery query;
        QString queryStr=QString("SELECT * FROM user where username='%1'").arg(*tempUsername);
        query.exec(queryStr);
        if(query.next()){
            if(query.value("password").toString()==signInBag->value("password").toString()){
                QSqlQuery updateQuery;
                queryStr=QString("UPDATE user SET online = 1 where username='%1'").arg(*tempUsername);
                updateQuery.exec(queryStr);
                sendInfoPre(2,socketDescriptor);
            }
            //password error
            else sendInfoPre(3,socketDescriptor);
        }else{
            //cannot find your account
            sendInfoPre(4,socketDescriptor);
        }
    }
    delete signInBag;
    return;
}

void myTcpServer::processSignUpBag(QJsonObject* signUpBag,qintptr socketDescriptor){
    QString * tempUsername;
    tempUsername=new QString;
    *tempUsername=signUpBag->value("username").toString();
    QSqlQuery query;
    QString queryStr=QString("SELECT * FROM user where username='%1'").arg(*tempUsername);
    query.exec(queryStr);
    if(query.next()){
        //username has existed
        sendInfoPre(0,socketDescriptor);
    }else{
        queryStr=QString("INSERT INTO user\
                         VALUES\
                         ('%1','%2',0,0,0,0,0,0,0,0,0,0,0);").arg(*tempUsername).arg(signUpBag->value("password").toString());
        query.exec(queryStr);
        QSqlError error = dbconn.lastError();
        distributeFairiesRandomly(tempUsername,DISTRIBUTE_NUM);
        //sign up secceed
        sendInfoPre(1,socketDescriptor);
    }
    delete signUpBag;
    delete tempUsername;
}

void myTcpServer::processSignOutBag(QString* tempUserName){
    qDebug()<<"here sign out:"<<*tempUserName;
    QSqlQuery updateQuery;
    QString queryStr=QString("UPDATE user SET online = 0 where username='%1'").arg(*tempUserName);
    updateQuery.exec(queryStr);
    return;
}

myTcpServer::~myTcpServer(){
    for(int i=0;i<tcpSocketConnectedList.count();i++)
        delete tcpSocketConnectedList.at(i);
    dbconn.close();
}

/*成功注册后，随机分配精灵，并添加到数据表中*/
void myTcpServer::distributeFairiesRandomly(QString* tempUsername, int num){
    srand(time(NULL));
    int fairyIndex;
    fairy* tempfairy;
    QSqlQuery query;
    QString queryStr=QString("SELECT * FROM user where username='%1'").arg(*tempUsername);
    query.exec(queryStr);
    if(query.next()){
        for(int i=0;i<num;i++){
            fairyIndex=rand()%FAIRY_TYPE_NUM;
            tempfairy=newAFairy(fairyIndex);
            insertFairy(tempUsername,tempfairy);
        }
    }
}

/*客户端发起获取其所有精灵的请求，进行处理，将一个一个精灵返回给客户端，同种精灵有index编号*/
void myTcpServer::processUserFairiesReq(QString* tempUsername,qintptr socketDescriptor){
    updateBadge();
    QJsonObject* userFairiesBag;
    QJsonArray* tempFairyArray;
    userFairiesBag=new QJsonObject;
    userFairiesBag->insert("event",1);
    userFairiesBag->insert("username",*tempUsername);
    tempFairyArray=getUserFairiesArray(tempUsername);
    userFairiesBag->insert("fairiesArray",QJsonValue(*tempFairyArray));
    QSqlQuery query;
    QString queryStr;
    queryStr=QString("SELECT FairiesNumBadge,FairiesStageBadge FROM user WHERE username='%1'").arg(*tempUsername);
    query.exec(queryStr);
    if(query.next()){
        userFairiesBag->insert("numBadge",query.value(0).toInt());
        userFairiesBag->insert("stageBadge",query.value(1).toInt());
    }
    myTcpSocket* theSocket=getSocket(socketDescriptor);
    theSocket->send(userFairiesBag);
    delete tempFairyArray;
}

QJsonArray* myTcpServer::getUserFairiesArray(QString *tempUserName){
    QList<int>* typeNumList;
    typeNumList=getUserFairiesTypeNum(tempUserName);
    fairy* tempfairy;
    QString *tempFairyName;
    QJsonObject* fairyBag;
    QJsonArray* tempFairyArray;
    tempFairyArray=new QJsonArray;
    if(typeNumList!=NULL){
        for(int i=0;i<FAIRY_TYPE_NUM;i++){
            //j即同种精灵编号
            for(int j=0;j<typeNumList->at(i);j++){
                tempFairyName=getFairyName(i);
                //qDebug()<<*tempFairyName;
                tempfairy=getUserAFairy(tempUserName,tempFairyName,j);
                if(tempfairy!=NULL){
                    //qDebug()<<tempfairy->fairyname<<tempfairy->username;
                    fairyBag=new QJsonObject;
                    fairyBag->insert("index",j);
                    fairyBag->insert("fairyname",tempfairy->fairyname);
                    fairyBag->insert("type",tempfairy->type);
                    fairyBag->insert("stage",tempfairy->stage);
                    fairyBag->insert("experience",tempfairy->experience);
                    fairyBag->insert("aggressivity",tempfairy->aggressivity);
                    fairyBag->insert("defense",tempfairy->defense);
                    fairyBag->insert("life",tempfairy->life);
                    fairyBag->insert("attack_interval",tempfairy->attack_interval);
                    tempFairyArray->append(QJsonValue(*fairyBag));
                    delete tempfairy;
                    delete fairyBag;
                }
                delete tempFairyName;
            }
        }
    delete typeNumList;
    return tempFairyArray;
    }
}

/*插入精灵到数据表中，参数是一个精灵，其包含用户名和精灵等所有信息*/
void myTcpServer::insertFairy(QString* tempUserName,fairy *tempfairy){
    if(tempfairy==NULL) return;
    QString *tempFairyName;
    tempFairyName=new QString;
    *tempFairyName=tempfairy->fairyname;
    QList<int>* typeNumList;
    typeNumList=getUserFairiesTypeNum(tempUserName);
    int index;
    index=typeNumList->at(getFairyIndex(tempFairyName));
    QSqlQuery insertQuery;
    QString queryStr;
    queryStr=QString("INSERT INTO fairies \
                     VALUES\
                     ('%1','%2',%3,%4,%5,%6,%7,%8,%9,%10);").arg(*tempUserName).arg(tempfairy->fairyname).arg(index).arg(tempfairy->type).\
                          arg(tempfairy->stage).arg(tempfairy->experience).arg(tempfairy->aggressivity).\
                          arg(tempfairy->defense).arg(tempfairy->life).arg(tempfairy->attack_interval);
    insertQuery.exec(queryStr);
    addFairyNum(tempUserName,tempFairyName,1);
    delete typeNumList;
    delete tempfairy;
    delete tempFairyName;
}

/*小工具函数：获取用户精灵的数目，存储在user表中*/
QList<int> *myTcpServer::getUserFairiesTypeNum(QString *tempUserName){
    QList<int>* typeNumList;
    QSqlQuery query;
    QString queryStr;
    queryStr=QString("SELECT FayeNum, HebeNum, LalaNum, SquirrelNum, KayNum, BeenleNum FROM user where username='%1' ").arg(*tempUserName);
    query.exec(queryStr);
    if(query.next()){
        typeNumList=new QList<int>;
        for(int i=0;i<FAIRY_TYPE_NUM;i++)
            typeNumList->append(query.value(i).toInt());
    }
    return typeNumList;
}

/*小工具函数：获取用户的一个精灵，参数为用户名，精灵名，同种精灵标号，返回该精灵*/
fairy* myTcpServer::getUserAFairy(QString* tempUserName, QString *tempFairyName, int index){
    QSqlQuery query;
    QString queryStr;
    fairy* foundFairy;
    foundFairy=NULL;
    queryStr=QString("SELECT * FROM fairies where username='%1' AND fairyname='%2' AND no=%3 ").arg(*tempUserName).arg(*tempFairyName).arg(index);
    query.exec(queryStr);
    if(query.next()){
        foundFairy=newAFairy(index);
        foundFairy->fairyname=*tempFairyName;
        foundFairy->type=query.value("type").toInt();
        foundFairy->stage=query.value("stage").toInt();
        foundFairy->experience=query.value("experience").toInt();
        foundFairy->aggressivity=query.value("aggressivity").toInt();
        foundFairy->defense=query.value("defense").toInt();
        foundFairy->life=query.value("life").toInt();
        foundFairy->attack_interval=query.value("attack_interval").toInt();
        return foundFairy;
    }else return NULL;

}

/*小工具函数：用精灵编号可以得到精灵名称，六种精灵按定义顺序编号，注意此处index不是同种精灵编号*/
QString* myTcpServer::getFairyName(int index){
    QString* tempString;
    tempString=new QString;
    switch (index) {
    case 0:
        *tempString=QString("Faye");
        break;
    case 1:
        *tempString=QString("Hebe");
        break;
    case 2:
        *tempString=QString("Lala");
        break;
    case 3:
        *tempString=QString("Squirrel");
        break;
    case 4:
        *tempString=QString("Kay");
        break;
    case 5:
        *tempString=QString("Beenle");
        break;
    }
    return tempString;
}


/*统一发送用户登录，注册，登出等信息*/
void myTcpServer::sendInfoPre(int infoType, qintptr socketDescriptor){
    myTcpSocket* theSocket=getSocket(socketDescriptor);
    QJsonObject *info;
    info=new QJsonObject;
    *info={{"event",0},{"infoType",infoType}};
    qDebug()<<"start to send info"<<infoType;
    theSocket->send(info);
}

/*小工具函数：获取精灵编号，参数是精灵名称，返回在六种精灵之中的编号*/
int myTcpServer::getFairyIndex(QString *tempFairyName){
    if(*tempFairyName=="Faye") return 0;
    else if(*tempFairyName=="Hebe") return 1;
    else if(*tempFairyName=="Lala") return 2;
    else if(*tempFairyName=="Squirrel") return 3;
    else if(*tempFairyName=="Kay") return 4;
    else if(*tempFairyName=="Beenle") return 5;
    else return -1;
}

/*用户精灵增加后，要在user表中改变其精灵数目，参数是用户名，精灵名，增加的值，可以为负*/
void myTcpServer::addFairyNum(QString *tempUserName, QString *tempFairyName, int addNum){
    QString findName;
    findName=tempFairyName->append("Num");
    QSqlQuery query;
    QString queryStr=QString("SELECT %1 FROM user where username='%2'").arg(findName).arg(*tempUserName);
    query.exec(queryStr);
    int kindNum;
    if(query.next()) kindNum=query.value(0).toInt();
    queryStr=QString("UPDATE user SET %1=%2 where username='%3'").arg(findName).arg(kindNum+addNum).arg(*tempUserName);
    query.exec(queryStr);
}

void myTcpServer::processUserReq(QString* tempUserName, int req, qintptr socketDescriptor){
    QJsonObject* userBag;
    QJsonArray* userArray;
    QJsonObject* user;
    QSqlQuery query;
    QString queryStr;
    if(req==1) queryStr=QString("SELECT username, FayeNum, HebeNum, LalaNum, SquirrelNum, KayNum, BeenleNum, battleCount, winCount, FairiesNumBadge, FairiesStageBadge, online FROM user where online=1");
    else queryStr=QString("SELECT username, FayeNum, HebeNum, LalaNum, SquirrelNum, KayNum, BeenleNum, battleCount, winCount, FairiesNumBadge, FairiesStageBadge, online FROM user");
    query.exec(queryStr);
    userBag=new QJsonObject;
    *userBag={
      {"event",2},
      {"reqOnlineOrNot",req}
    };
    userArray=new QJsonArray;
    while(query.next()){
        if(query.value(0).toString()==tempUserName) continue;
        user=new QJsonObject;
        *user={
            {"username",query.value(0).toString()},
            {"FayeNum",query.value(1).toInt()},
            {"HebeNum",query.value(2).toInt()},
            {"LalaNum",query.value(3).toInt()},
            {"SquirrelNum",query.value(4).toInt()},
            {"KayNum",query.value(5).toInt()},
            {"BeenleNum",query.value(6).toInt()},
            {"winRate",query.value(8).toInt()/(double(query.value(7).toInt()))},
            {"FairiesNumBadge",query.value(9).toInt()},
            {"FairiesStageBadge",query.value(10).toInt()},
            {"online",query.value(11).toInt()}
        };
        userArray->append(QJsonValue(*user));
        delete user;
    }
    userBag->insert("userArray",QJsonValue(*userArray));
    myTcpSocket* theSocket=getSocket(socketDescriptor);
    theSocket->send(userBag);
    delete userArray;
}

myTcpSocket* myTcpServer::getSocket(qintptr socketDescriptor){
    int count=this->tcpSocketConnectedList.count();
    for(int i=0;i<count;i++){
        if(socketDescriptor==tcpSocketConnectedList.at(i)->qtcpsocket->socketDescriptor()) return tcpSocketConnectedList.at(i);
    }
    return NULL;
}

void myTcpServer::processBattleFairiesReq(QString* tempUserName,qintptr socketDescriptor){
    QJsonObject* battleFairiesInfo=new QJsonObject;
    *battleFairiesInfo={
        {"event",3}
    };
    QJsonArray* serverFairiesArray=getServerFairiesArray();
    battleFairiesInfo->insert("serverFairies",QJsonValue(*serverFairiesArray));
    delete serverFairiesArray;
    QJsonArray* userFairiesArray=getUserFairiesArray(tempUserName);
    battleFairiesInfo->insert("userFairies",QJsonValue(*userFairiesArray));
    delete userFairiesArray;
    myTcpSocket* theSocket=getSocket(socketDescriptor);
    theSocket->send(battleFairiesInfo);
}

QJsonArray* myTcpServer::getServerFairiesArray(){
    QSqlQuery query;
    QString queryStr;
    queryStr=QString("SELECT fairyname, no, type, stage, experience, aggressivity, defense, life, attack_interval FROM serverfairies");
    query.exec(queryStr);
    QJsonArray* fairiesArray=new QJsonArray;
    while(query.next()){
        QJsonObject* onefairy=new QJsonObject;
        *onefairy={{"fairyname",query.value(0).toString()},
                   {"index",query.value(1).toInt()},
                   {"type",query.value(2).toInt()},
                   {"stage",query.value(3).toInt()},
                   {"experience",query.value(4).toInt()},
                   {"aggressivity",query.value(5).toInt()},
                   {"defense",query.value(6).toInt()},
                   {"life",query.value(7).toInt()},
                   {"attack_interval",query.value(8).toInt()}
                   };
        fairiesArray->append(QJsonValue(*onefairy));
        delete onefairy;
    }
    return fairiesArray;
}

void myTcpServer::processBattleEnd(QJsonObject *recvdata, QString *tempUserName, qintptr socketDescriptor){
    int battleType=recvdata->value("battleType").toInt();
    int winOrLose=recvdata->value("winOrLose").toInt();
    QString* opponent=new QString;
    QString* myFairyName=new QString;
    *opponent=recvdata->value("opponentName").toString();
    qDebug()<<*opponent;
    *myFairyName=recvdata->value("myFairyName").toString();
    qDebug()<<*tempUserName<<"processBattleEnd";
    QJsonObject* battleResultBag=new QJsonObject;
    *battleResultBag={
        {"event",4}
    };
    if(battleType==1){
        //winLoseGame
        if(winOrLose){
            //win, user can get the fairy
            winAServerFairy(tempUserName,opponent);
        }
        else{
            //lose a fairy
            QJsonArray* mayGiveFairiesArray=new QJsonArray;
            mayGiveFairiesArray=choose3FairiesRandomly(tempUserName);
            battleResultBag->insert("mayGiveFairiesArray",*mayGiveFairiesArray);
        }
    }
    int updateRes=updateMyFairy(tempUserName,myFairyName,winOrLose,recvdata->value("countAttack").toInt(),recvdata->value("countHurt").toInt());
    battleResultBag->insert("updateRes",updateRes);
    myTcpSocket* theSocket=getSocket(socketDescriptor);
    theSocket->send(battleResultBag);
    updateWinRate(tempUserName,winOrLose);

}

int myTcpServer::updateMyFairy(QString* tempUserName, QString *fairyDescriptor, int winOrLose, int countAttack, int countHurt){
    fairy* myfairy;
    QString* fairyName=new QString;
    *fairyName=fairyDescriptor->section('_',0,0);
    int index=fairyDescriptor->section('_',1,1).toInt();
    myfairy=getUserAFairy(tempUserName,fairyName,index);
    if(myfairy!=NULL){
        int updateRes=myfairy->update(winOrLose,countAttack,countHurt);
        updateSQL(tempUserName,myfairy,index);
        delete fairyName;
        delete myfairy;
        return updateRes;
    }
    else return -1;
}

void myTcpServer::winAServerFairy(QString *tempUserName, QString *opponentDescriptor){
    QString* fairyName=new QString;
    *fairyName=opponentDescriptor->section('_',0,0);
    int index=opponentDescriptor->section('_',1,1).toInt();
    QSqlQuery query;
    QString queryStr;
    queryStr=QString("SELECT type, stage, experience, aggressivity, defense, life, attack_interval\
                      FROM serverfairies WHERE fairyname='%1' AND no=%2;").arg(*fairyName).arg(index);
    query.exec(queryStr);
    qDebug()<<queryStr;
    QList<int>* typeNumList;
    typeNumList=getUserFairiesTypeNum(tempUserName);
    int k=getFairyIndex(fairyName);
    index=typeNumList->at(k);
    qDebug()<<"add"<<*fairyName<<index;
    if(query.next()){
        QSqlQuery insertQuery;
        QString insertQueryStr=QString("INSERT INTO fairies \
                         VALUES\
                         ('%1','%2',%3,%4,%5,%6,%7,%8,%9,%10);").arg(*tempUserName).arg(*fairyName).arg(index).arg(query.value(0).toInt())\
                              .arg(query.value(1).toInt()).arg(query.value(2).toInt()).arg(query.value(3).toInt())\
                              .arg(query.value(4).toInt()).arg(query.value(5).toInt()).arg(query.value(6).toInt());
        insertQuery.exec(insertQueryStr);
        qDebug()<<insertQueryStr;
    }
    addFairyNum(tempUserName,fairyName,1);
}

QJsonArray* myTcpServer::choose3FairiesRandomly(QString *tempUserName){
    QJsonArray* mayGiveFairiesArray=new QJsonArray;
    QList<int>* typeNumList;
    typeNumList=getUserFairiesTypeNum(tempUserName);
    int totalNum=0,i,j,k;
    for(i=0;i<FAIRY_TYPE_NUM;i++){
        totalNum+=typeNumList->at(i);
    }
    QList<int> userFairyIndex;

    if(totalNum==1) userFairyIndex.append(0);
    else if(totalNum==2) {
        userFairyIndex.append(0);
        userFairyIndex.append(1);
    }
    else if(totalNum==3){
        userFairyIndex.append(0);
        userFairyIndex.append(1);
        userFairyIndex.append(2);
    }
    else{
        srand(time(NULL));
        for(i=0;i<3;i++){
            int ran=rand()%totalNum;
            for(j=0;j<i;j++){
                while(ran==userFairyIndex.at(j)) ran=rand()%totalNum;
            }
            userFairyIndex.append(ran);
        }
    }

    for(i=0;i<userFairyIndex.count();i++){
        qDebug()<<userFairyIndex.at(i);
        QSqlQuery query;
        QString queryStr;
        queryStr=QString("SELECT fairyname, no\
                          FROM fairies WHERE username='%1';").arg(*tempUserName);
        qDebug()<<queryStr;
        query.exec(queryStr);
        k=0;
        while(query.next()){
            if(k==userFairyIndex.at(i)){
                QJsonObject aFairy;
                aFairy={
                   {"fairyname",QString("%1_%2").arg(query.value(0).toString()).arg(query.value(1).toInt())}
                };
                mayGiveFairiesArray->append(QJsonValue(aFairy));
                qDebug()<<aFairy;
                break;
            }
            else ++k;
        }
    }
    delete typeNumList;
    if(totalNum==1) distributeFairiesRandomly(tempUserName,1);
    return mayGiveFairiesArray;
}

void myTcpServer::updateSQL(QString *tempUserName, fairy *myfairy, int index){
    QSqlQuery query;
    QString queryStr;
    queryStr=QString("UPDATE fairies SET %1=%2 where username='%3' AND fairyname='%4' AND no=%5").arg("type").arg(myfairy->type).arg(*tempUserName).arg(myfairy->fairyname).arg(index);
    query.exec(queryStr);
    queryStr=QString("UPDATE fairies SET %1=%2 where username='%3' AND fairyname='%4' AND no=%5").arg("stage").arg(myfairy->stage).arg(*tempUserName).arg(myfairy->fairyname).arg(index);
    query.exec(queryStr);
    queryStr=QString("UPDATE fairies SET %1=%2 where username='%3' AND fairyname='%4' AND no=%5").arg("experience").arg(myfairy->experience).arg(*tempUserName).arg(myfairy->fairyname).arg(index);
    query.exec(queryStr);
    queryStr=QString("UPDATE fairies SET %1=%2 where username='%3' AND fairyname='%4' AND no=%5").arg("aggressivity").arg(myfairy->aggressivity).arg(*tempUserName).arg(myfairy->fairyname).arg(index);
    query.exec(queryStr);
    queryStr=QString("UPDATE fairies SET %1=%2 where username='%3' AND fairyname='%4' AND no=%5").arg("life").arg(myfairy->life).arg(*tempUserName).arg(myfairy->fairyname).arg(index);
    query.exec(queryStr);
    queryStr=QString("UPDATE fairies SET %1=%2 where username='%3' AND fairyname='%4' AND no=%5").arg("defense").arg(myfairy->defense).arg(*tempUserName).arg(myfairy->fairyname).arg(index);
    query.exec(queryStr);
    queryStr=QString("UPDATE fairies SET %1=%2 where username='%3' AND fairyname='%4' AND no=%5").arg("attack_interval").arg(myfairy->attack_interval).arg(*tempUserName).arg(myfairy->fairyname).arg(index);
    query.exec(queryStr);
}

fairy* myTcpServer::newAFairy(int index){
    fairy* tempfairy;
    switch (index) {
    case 0:
        Faye* tempFaye;
        tempFaye=new Faye();
        tempfairy=tempFaye;
        break;
    case 1:
        Hebe* tempHebe;
        tempHebe=new Hebe();
        tempfairy=tempHebe;
        break;
    case 2:
        Lala* tempLala;
        tempLala=new Lala();
        tempfairy=tempLala;
        break;
    case 3:
        Squirrel* tempSquirrel;
        tempSquirrel=new Squirrel();
        tempfairy=tempSquirrel;
        break;
    case 4:
        Kay* tempKay;
        tempKay=new Kay();
        tempfairy=tempKay;
        break;
    case 5:
        Beenle* tempBeenle;
        tempBeenle=new Beenle();
        tempfairy=tempBeenle;
        break;
    }
    return tempfairy;
}

void myTcpServer::processLoseAFairy(QJsonObject* recvData, QString* tempUserName){
    QString fairyDescriptor=recvData->value("fairyname").toString();
    QString *fairyName=new QString;
    *fairyName=fairyDescriptor.section('_',0,0);
    int index=fairyDescriptor.section('_',1,1).toInt();
    qDebug()<<*tempUserName<<*fairyName<<index;
    QSqlQuery query;
    QString queryStr;
    queryStr=QString("DELETE FROM fairies where username='%1' AND fairyname='%2' AND no=%3 ").arg(*tempUserName).arg(*fairyName).arg(index);
    query.exec(queryStr);
    addFairyNum(tempUserName,fairyName,-1);
    delete fairyName;
}

void myTcpServer::updateWinRate(QString* tempUserName,int winOrLose){
    int currentWinCount,currentBattleCount;
    QSqlQuery query;
    QString queryStr;
    queryStr=QString("SELECT battleCount, winCount FROM user where username='%1'").arg(*tempUserName);
    query.exec(queryStr);
    if(query.next()){
        currentBattleCount=query.value(0).toInt();
        currentWinCount=query.value(1).toInt();
    }
    if(winOrLose) ++currentWinCount;
    queryStr=QString("UPDATE user SET battleCount=%1, winCount=%2 WHERE username='%3'").arg(currentBattleCount+1).arg(currentWinCount).arg(*tempUserName);
    query.exec(queryStr);
}

void myTcpServer::updateBadge(){
    int i;
    QSqlQuery query;
    QString queryStr;
    queryStr=QString("SELECT username FROM user");
    query.exec(queryStr);
    while(query.next()){
        int numBadge,stageBadge;
        //numBadge
        QList<int>* typeNumList;
        QString *username=new QString;
        *username=query.value("username").toString();
        qDebug()<<*username;
        typeNumList=getUserFairiesTypeNum(username);
        int totalNum=0;
        for(i=0;i<FAIRY_TYPE_NUM;i++){
            totalNum+=typeNumList->at(i);
        }
        qDebug()<<totalNum;
        if(totalNum<5) numBadge=0;
        else if(totalNum<10) numBadge=1;
        else if(totalNum<15) numBadge=2;
        else numBadge=3;
        //stageBadge
        QSqlQuery selectquery;
        queryStr=QString("SELECT username FROM fairies WHERE username='%1' AND stage=15").arg(*username);
        qDebug()<<queryStr;
        selectquery.exec(queryStr);
        int fullStageNum=0;
        while(selectquery
              .next()) ++fullStageNum;
        if(fullStageNum<3) stageBadge=0;
        else if(fullStageNum<5) stageBadge=1;
        else if(fullStageNum<8) stageBadge=2;
        else stageBadge=3;

        QSqlQuery updateQuery;
        queryStr=QString("UPDATE user SET FairiesNumBadge=%1 WHERE username='%2'").arg(numBadge).arg(*username);
        updateQuery.exec(queryStr);
        qDebug()<<queryStr;
        queryStr=QString("UPDATE user SET FairiesStageBadge=%1 WHERE username='%2'").arg(stageBadge).arg(*username);
        updateQuery.exec(queryStr);
        qDebug()<<queryStr;
    }
}
