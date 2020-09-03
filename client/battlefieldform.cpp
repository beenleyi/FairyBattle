#include "battlefieldform.h"
#include "ui_battlefieldform.h"

battlefieldForm::battlefieldForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::battlefieldForm)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/fig/icon.ico"));
    this->setWindowTitle("Crazy Arcade");
}

battlefieldForm::~battlefieldForm()
{
    delete ui;
}


void battlefieldForm::setBattlefieldForm(int type, QJsonObject* myFairyInfo,QJsonObject* opponentInfo){
    if(type) ui->gameType_label->setText("Win-lose Battle");
    else ui->gameType_label->setText("Upgrade Battle");
    QString *myFairyName=new QString;
    *myFairyName=myFairyInfo->value("fairyname").toString();
    qDebug()<<*myFairyName;
    int index=getFairyIndex(myFairyName);
    qDebug()<<index;
    QString mySkillName=*getSkillName(index);
    qDebug()<<mySkillName;
    ui->myskill_label->setText(mySkillName);
    QImage img;
    img.load(QString(":/fig/%1.png").arg(*myFairyName));
    ui->myFig_label->setPixmap(QPixmap::fromImage(img));
    myFairyName->append(QString("_%1").arg(myFairyInfo->value("index").toInt()));
    ui->myFairyName_label->setText(*myFairyName);
    ui->myblood_label->setText(QString("%1").arg(myFairyInfo->value("life").toInt()));
    delete myFairyInfo;
    delete myFairyName;
    QString *opponentName=new QString;
    *opponentName=opponentInfo->value("fairyname").toString();
    index=getFairyIndex(opponentName);
    QString opponentSkillName=*getSkillName(index);
    ui->opponent_skill->setText(opponentSkillName);
    img.load(QString(":/fig/%1.png").arg(*opponentName));
    ui->opponentFig_label->setPixmap(QPixmap::fromImage(img));
    opponentName->append(QString("_%1").arg(opponentInfo->value("index").toInt()));
    ui->opponentName_label->setText(*opponentName);
    ui->opponentBlood_label->setText(QString("%1").arg(opponentInfo->value("life").toInt()));
    delete opponentInfo;
    delete opponentName;
}

QString* battlefieldForm::getSkillName(int index){
    QString *skillName=new QString;
    switch (index) {
    case 0:
        *skillName="bow and arrow";
        break;
    case 1:
        *skillName="magic stone";
        break;
    case 2:
        *skillName="gun";
        break;
    case 3:
        *skillName="dart";
        break;
    case 4:
        *skillName="infrasound";
        break;
    case 5:
        *skillName="bomb";
        break;
    default:
        break;
    }
    return skillName;
}

int battlefieldForm::getFairyIndex(QString *tempFairyName){
    if(*tempFairyName=="Faye") return 0;
    else if(*tempFairyName=="Hebe") return 1;
    else if(*tempFairyName=="Lala") return 2;
    else if(*tempFairyName=="Squirrel") return 3;
    else if(*tempFairyName=="Kay") return 4;
    else if(*tempFairyName=="Beenle") return 5;
    else return -1;
}
