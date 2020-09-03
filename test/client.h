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
#include <QDebug>
#include "signInForm.h"
#include "signUpForm.h"
#include "userForm.h"
#include "fairy.h"
#include <QJsonParseError>
class client:public QWidget
{
    Q_OBJECT
public:
    client();

    int connectToHost();
private:
    QString *username;
private:
    QTcpSocket *mysocket;
    QList<fairy*> myfairies;
    signInForm* mySignInForm;
    userForm* myUserForm;
    signUpForm* mySignUpForm;
private slots:
    void preProcessRecvData();
    void processSignUpReq();
    void sendMessage(QJsonObject*);
signals:
    void signUp_usernameExisted();
    void signUp_signUpSecceed();
    void signIn_signInSecceed();
    void signIn_passwordErr();
    void signIn_accountNotExist();
    void getMyFairy(QJsonObject*);
    void getUserBag(QJsonObject*);
};

#endif // CLIENT_H
