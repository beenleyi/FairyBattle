#include "signUpForm.h"
#include "ui_signupform.h"

signUpForm::signUpForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signUpForm)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/fig/icon.ico"));
    this->setWindowTitle("Crazy Arcade");
}

signUpForm::~signUpForm()
{
    delete ui;
}

void signUpForm::on_signIn_pushButton_clicked()
{
    emit showSignInFormReq();

    this->hide();
}

void signUpForm::on_signUp_pushButton_clicked()
{
    QJsonObject *signUpBag;
    signUpBag=new QJsonObject;
    *signUpBag={
        {"event",1},//1 for signup
        {"username",ui->username_lineEdit->text()},
        {"password",ui->password_lineEdit->text()}
    };
    emit sendMessageReq(signUpBag);
}

void signUpForm::signUp_usernameExisted(){
    QMessageBox messageBox(QMessageBox::NoIcon,
                           "Error", "username has existed.\nPlease use other usernames.",
                           QMessageBox::Ok, NULL);
    int result=messageBox.exec();
    switch (result)
    {
    case QMessageBox::Ok:
        messageBox.close();
        break;
    default:
        break;
    }
    return;
}
