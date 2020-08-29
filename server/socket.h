#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
class myTcpSocket:public QObject
{
    Q_OBJECT
public:
    myTcpSocket(QTcpSocket*);
    QTcpSocket* qtcpsocket;
public slots:
    void preProcessRecvData();
    void sendInfo(int);
signals:
    void getSignInBag(QJsonObject*);
    void getSignUpBag(QJsonObject*);
    void getSignOutBag(QJsonObject*);

};
