#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QList>
const QString serverIP="127.0.0.1";
const int port=6666;
#include <QWidget>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include "fairy.h"
class client:public QWidget
{
    Q_OBJECT
public:
    client();
    void sendMessage(QJsonObject*);
    int connectToHost();
private:
    QTcpSocket *mysocket;
    QList<fairy*> myfairies;
private slots:
    void preProcessRecvData();
signals:
    void signUp_usernameExisted();
    void signUp_signUpSecceed();
    void signIn_signInSecceed();
    void signIn_passwordErr();
    void signIn_accountNotExist();
};

#endif // CLIENT_H
