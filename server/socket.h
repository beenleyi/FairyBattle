#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
class myTcpSocket:public QObject
{
    Q_OBJECT
public:
    QString* username;
public:
    myTcpSocket(QTcpSocket*);
    QTcpSocket* qtcpsocket;
    void send(QJsonObject*);
public slots:
    void preProcessRecvData();
    void preProcessDisconnect();

signals:
    void getSignInBag(QJsonObject*,qintptr);
    void getSignUpBag(QJsonObject*,qintptr);
    void getSignOutBag(QString*);
    void clientDisconnect(QString*);
    void getUserFairiesReq(QString*,qintptr);
    void getUserReq(QString*,int,qintptr);
    void getBattleFairiesReqBag(QString*,qintptr);
    void getBattleEndBag(QJsonObject*,QString*,qintptr);
    void getLoseAFairyBag(QJsonObject*, QString*);
};
