#include "battleform.h"
#include "ui_battleform.h"

battleForm::battleForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::battleForm)
{
    ui->setupUi(this);
}

battleForm::~battleForm()
{
    delete ui;
}


void battleForm::on_upgradeBattle_pushButton_clicked()
{

}

void battleForm::on_signOut_pushButton_clicked()
{
    emit showSignInForm();
    this->hide();
}
