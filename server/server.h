#include <QTcpServer>
#include "socket.h"
#include <QSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
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

private slots:
    void processDisconnect();
    void processSignInBag(QJsonObject*);
    void processSignUpBag(QJsonObject*);
    void processSignOutBag(QJsonObject*);
signals:
    void sendInformation(int);
};
