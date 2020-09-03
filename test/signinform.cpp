#include "signInForm.h"
#include "ui_signInForm.h"

signInForm::signInForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signInForm)
{
    ui->setupUi(this);
    ui->username_lineEdit->setMaxLength(20);
    ui->password_lineEdit->setMaxLength(20);
    this->setWindowIcon(QIcon(":/fig/icon.ico"));
    this->setWindowTitle("Crazy Arcade");

}

signInForm::~signInForm()
{
    delete ui;
}

void signInForm::on_signIn_pushButton_clicked()
{
    QJsonObject *signInBag;
    signInBag=new QJsonObject;
    *signInBag={
        {"event",0},//0 for signin
        {"username",ui->username_lineEdit->text()},
        {"password",ui->password_lineEdit->text()}
    };
    emit sendMessageReq(signInBag);
}

void signInForm::signIn_accountNotExist(){
    QMessageBox messageBox(QMessageBox::NoIcon,
                           "Error", "Cannot find your account.\nPlease checkout your username or sign up first.",
                           QMessageBox::Ok, NULL);
    messageBox.exec();
    return;
}

void signInForm::signIn_passwordErr(){
    QMessageBox messageBox(QMessageBox::NoIcon,
                           "Error", "Your password is wrong.\nPlease check your username and your password.",
                           QMessageBox::Ok, NULL);
    messageBox.exec();
    return;
}

void signInForm::showForm(){
    this->show();
}


QString* signInForm::getUserName(){
    QString *userNameStr;
    userNameStr=new QString;
    *userNameStr=ui->username_lineEdit->text();
    return userNameStr;
}

void signInForm::on_signUp_pushButton_clicked(){
    emit signUpReq();
}
