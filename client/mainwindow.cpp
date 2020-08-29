#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->username_lineEdit->setMaxLength(20);
    ui->password_lineEdit->setMaxLength(20);
    signUpForm=new signup;
    connect(signUpForm,SIGNAL(showSignInFormReq()),this,SLOT(showForm()));
    myBattleForm=new battleForm;
    connect(myBattleForm,SIGNAL(showSignInForm()),this,SLOT(showForm()));
    connect(user,SIGNAL(signIn_accountNotExist()),this,SLOT(signIn_accountNotExist()));
    connect(user,SIGNAL(signIn_passwordErr()),this,SLOT(signIn_passwordErr()));
    connect(user,SIGNAL(signIn_signInSecceed()),this,SLOT(signIn_signInSecceed()));
    connect(user,SIGNAL(signUp_signUpSecceed()),this,SLOT(signUp_signUpsecceed()));
    connect(user,SIGNAL(signUp_usernameExisted()),signUpForm,SLOT(signUp_usernameExisted()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_signIn_pushButton_clicked()
{
    QJsonObject *signInBag;
    signInBag=new QJsonObject;
    *signInBag={
        {"event",0},//0 for signin
        {"username",ui->username_lineEdit->text()},
        {"password",ui->password_lineEdit->text()}
    };
    user->sendMessage(signInBag);
}

void MainWindow::signIn_signInSecceed(){
    myBattleForm->show();
    this->hide();
}

void MainWindow::signIn_accountNotExist(){
    QMessageBox messageBox(QMessageBox::NoIcon,
                           "Error", "Cannot find your account.\nPlease checkout your username or sign up first.",
                           QMessageBox::Ok, NULL);
    int result=messageBox.exec();
    return;
}

void MainWindow::signIn_passwordErr(){
    QMessageBox messageBox(QMessageBox::NoIcon,
                           "Error", "Your password is wrong.\nPlease check your username and your password.",
                           QMessageBox::Ok, NULL);
    int result=messageBox.exec();
//    switch (result)
//    {
//    case QMessageBox::Ok:
//        messageBox.close();
//        break;
//    default:
//        break;
//    }
//    return;
}

void MainWindow::showForm(){
    this->show();
}


void MainWindow::on_signUp_pushButton_2_clicked()
{
    signUpForm->show();
    this->hide();
}

void MainWindow::signUp_signUpsecceed(){
    signUpForm->hide();
    this->show();
}
