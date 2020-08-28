#include "signup.h"
#include "ui_signup.h"

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_signIn_pushButton_clicked()
{
    emit showSignInFormReq();

    this->hide();
}

void signup::on_signUp_pushButton_2_clicked()
{
    QJsonObject *signUpBag;
    signUpBag=new QJsonObject;
    *signUpBag={
        {"event",1},//1 for signup
        {"username",ui->username_lineEdit->text()},
        {"password",ui->password_lineEdit->text()}
    };
    user->sendMessage(signUpBag);
}
