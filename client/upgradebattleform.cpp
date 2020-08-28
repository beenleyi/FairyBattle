#include "upgradebattleform.h"
#include "ui_upgradebattleform.h"

upgradeBattleForm::upgradeBattleForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::upgradeBattleForm)
{
    ui->setupUi(this);
}

upgradeBattleForm::~upgradeBattleForm()
{
    delete ui;
}
