#include <QTcpServer>
#include "socket.h"
#include <QSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <time.h>
#include <stdlib.h>
#include <fairy.h>
#include <QDebug>
#include <QJsonArray>
const int DISTRIBUTE_NUM=3;
const int FAIRY_TYPE_NUM=6;
class myTcpServer:public QTcpServer{
    Q_OBJECT
public:
    myTcpServer();
    ~myTcpServer();
    //listen and return the connection num
    int startListen();
protected:
    virtual void incomingConnection(int socketDescriptor);
private:
    QList<myTcpSocket*> tcpSocketConnectedList;
    QString hostName;
    QString dbName;
    QString userName;
    QString password;
    QSqlDatabase dbconn;
    void distributeFairiesRandomly(QString*);
    void insertFairy(fairy*);
    QList<int>* getUserFairiesTypeNum(QString*);
    fairy* getUserAFairy(QString*, QString*, int);
    QString* getFairyName(int);
    void sendFairyDetail(int index, fairy*tempFairy);
    void sendInfoPre(int,qintptr);
    int getFairyIndex(QString*);
    void addFairyNum(QString* tempUserName, QString* tempFairyName,int addNum);
    myTcpSocket* getSocket(qintptr socketDescriptor);
    QJsonArray* getServerFairiesArray();
    QJsonArray* getUserFairiesArray(QString *tempUserName);
private slots:
    void processDisconnect(QString*);
    void processSignInBag(QJsonObject*,qintptr);
    void processSignUpBag(QJsonObject*,qintptr);
    void processSignOutBag(QString*);
    void processUserFairiesReq(QString*,qintptr);
    void processUserReq(QString*,int,qintptr);
    void processBattleFairiesReq(QString*,qintptr);
};
