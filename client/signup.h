#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <QJsonObject>
#include <QJsonDocument>
#include "client.h"
extern client *user;
namespace Ui {
class signup;
}

class signup : public QWidget
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = 0);
    ~signup();

private slots:


    void on_signIn_pushButton_clicked();

    void on_signUp_pushButton_2_clicked();

private:
    Ui::signup *ui;
signals:
    void showSignInFormReq();
};

#endif // SIGNUP_H
