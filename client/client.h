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
#include "battlefieldform.h"
#include "selectopponentform.h"
#include <QJsonParseError>
class client:public QWidget
{
    Q_OBJECT
public:
    client();
    ~client();
    int connectToHost();
private:
    QString *username;
private:
    QTcpSocket *mysocket;
    signInForm* mySignInForm;
    userForm* myUserForm;
    signUpForm* mySignUpForm;
    battlefieldForm* myBattlefieldForm;
    selectOpponentForm* mySelectOpponentForm;

private slots:
    void preProcessRecvData();
    void processSignUpReq();
    void sendMessage(QJsonObject*);
    void getFairies();
    void toSelectOpponent();
    void showBattlefield(int,QJsonObject*,QJsonObject*);

signals:
    void signUp_usernameExisted();
    void signUp_signUpSecceed();
    void signIn_signInSecceed();
    void signIn_passwordErr();
    void signIn_accountNotExist();
    void getMyFairy(QJsonObject*);
    void getUserBag(QJsonObject*);
    void getBattleFairiesBag(QJsonObject*);
};

#endif // CLIENT_H
