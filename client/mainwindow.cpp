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
    myBattleForm->show();
    this->hide();
}


void MainWindow::showForm(){
    this->show();
}


void MainWindow::on_signUp_pushButton_2_clicked()
{
    signUpForm->show();
    this->hide();
}
