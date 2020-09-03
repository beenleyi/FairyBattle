#ifndef userForm_H
#define userForm_H
#include <QWidget>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include <QPixmap>
#include "fairy.h"
namespace Ui {
class userForm;
}

class userForm : public QWidget
{
    Q_OBJECT

public:
    explicit userForm(QWidget *parent = 0);
    ~userForm();
    void setUsername(QString*);
private slots:
    void on_upgradeBattle_pushButton_clicked();
    void on_signOut_pushButton_clicked();
    void AddMyFairiesTable(QJsonObject*);
    void showUserBag(QJsonObject*);
    void on_lookUpOnlineUsers_pushButton_clicked();
    void on_lookUpAllUsers_pushButton_clicked();
    void on_myFairies_pushButton_clicked();
    void on_battle_pushButton_clicked();
private:
    Ui::userForm *ui;
    int fairyRows;
    int userRows;
    int getFairyIndex(QString *tempFairyName);
signals:
    void showSignInFormReq();
    void sendMessageReq(QJsonObject*);
    void needMyFairies();
    void gotoSelectOpponent();
};

#endif // userForm_H
