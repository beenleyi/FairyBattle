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
    void processRecvData();
};
