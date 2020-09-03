#ifndef userForm_H
#define userForm_H
#include <QWidget>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include <QPixmap>
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
private:
    Ui::userForm *ui;
signals:
    void showSignInFormReq();
    void sendMessageReq(QJsonObject*);
};

#endif // userForm_H
