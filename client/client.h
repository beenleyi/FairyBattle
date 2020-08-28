#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
const QString serverIP="127.0.0.1";
const int port=6666;
#include <QWidget>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
class client:public QWidget
{
    Q_OBJECT
public:
    client();
    void sendMessage(QJsonObject*);
private:
    QTcpSocket *mysocket;

};

#endif // CLIENT_H
