#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    user=new client;
    ui->username_lineEdit->setMaxLength(20);
    ui->password_lineEdit->setMaxLength(20);
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
        {"event",1},//0 for signin
        {"username",ui->username_lineEdit->text()},
        {"password",ui->password_lineEdit->text()}
    };
    qDebug()<<ui->username_lineEdit->text()<<endl<<ui->password_lineEdit->text();
    user->sendMessage(signInBag);
}

void MainWindow::on_signUp_pushButton_clicked()
{

}
