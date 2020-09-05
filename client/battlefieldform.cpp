#include "battlefieldform.h"
#include "ui_battlefieldform.h"
#include "fairy.h"
battlefieldForm::battlefieldForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::battlefieldForm)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/fig/icon.ico"));
    this->setWindowTitle("Crazy Arcade");
    myAttackTimer=new QTimer;
    opponentAttackTimer=new QTimer;
    countAttack=0;
    countHurt=0;
    gameIsOver=0;
}

battlefieldForm::~battlefieldForm()
{
    delete ui;
}


void battlefieldForm::setBattlefieldForm(int type, QJsonObject* myFairyInfo,QJsonObject* opponentInfo){
    battleType=type;
    if(type) ui->gameType_label->setText("Win-lose Battle");
    else ui->gameType_label->setText("Upgrade Battle");
    QString *myFairyName=new QString;
    *myFairyName=myFairyInfo->value("fairyname").toString();
    //qDebug()<<*myFairyName;
    int index=getFairyIndex(myFairyName);
    //qDebug()<<index;
    QString mySkillName=*getSkillName(index);
    //qDebug()<<mySkillName;
    ui->myskill_label->setText(mySkillName);
    QImage img;
    img.load(QString(":/fig/%1.png").arg(*myFairyName));
    ui->myFig_label->setPixmap(QPixmap::fromImage(img));
    myFairyName->append(QString("_%1").arg(myFairyInfo->value("index").toInt()));
    ui->myFairyName_label->setText(*myFairyName);
    myfairy=createFairy(myFairyInfo,index);
    qDebug()<<"my life"<<myfairy->life;
    ui->myBlood_progressBar->setMaximum(myfairy->life);
    ui->myBlood_progressBar->setValue(myfairy->life);
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
    opponent=createFairy(opponentInfo,index);
    ui->opponentBlood_progressBar->setMaximum(opponent->life);
    ui->opponentBlood_progressBar->setValue(opponent->life);
    delete opponentInfo;
    delete opponentName;

    connect(myAttackTimer,SIGNAL(timeout()),this,SLOT(myTimetoAttack()));
    connect(opponentAttackTimer,SIGNAL(timeout()),this,SLOT(opponentTimetoAttack()));
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

fairy* battlefieldForm::createFairy(QJsonObject* fairyInfo,int index){
    fairy* tempfairy=NULL;
    int type=fairyInfo->value("type").toInt();
    int stage=fairyInfo->value("stage").toInt();
    int aggressivity=fairyInfo->value("aggressivity").toInt();
    int experience=fairyInfo->value("experience").toInt();
    int life=fairyInfo->value("life").toInt();
    int attack_interval=fairyInfo->value("attack_interval").toInt();
    int defense=fairyInfo->value("defense").toInt();
    switch (index) {
    case 0:
        Faye* tempFaye;
        tempFaye=new Faye(type,stage,experience,aggressivity,defense,life,attack_interval);
        tempfairy=tempFaye;
        break;
    case 1:
        Hebe* tempHebe;
        tempHebe=new Hebe(type,stage,experience,aggressivity,defense,life,attack_interval);
        tempfairy=tempHebe;
        break;
    case 2:
        Lala* tempLala;
        tempLala=new Lala(type,stage,experience,aggressivity,defense,life,attack_interval);
        tempfairy=tempLala;
        break;
    case 3:
        Squirrel* tempSquirrel;
        tempSquirrel=new Squirrel(type,stage,experience,aggressivity,defense,life,attack_interval);
        tempfairy=tempSquirrel;
        break;
    case 4:
        Kay* tempKay;
        tempKay=new Kay(type,stage,experience,aggressivity,defense,life,attack_interval);
        tempfairy=tempKay;
        break;
    case 5:
        Beenle* tempBeenle;
        tempBeenle=new Beenle(type,stage,experience,aggressivity,defense,life,attack_interval);
        tempfairy=tempBeenle;
        break;
    }
    return tempfairy;
}

void battlefieldForm::on_start_pushButton_clicked(){
    myAttackTimer->start(myfairy->attack_interval*300);
    opponentAttackTimer->start(opponent->attack_interval*300);

}

void battlefieldForm::myTimetoAttack(){
    if(gameIsOver) return;
    countAttack++;
    srand(time(NULL));
    //随机产生暴击事件
    int IsCrit,critNum=0,hurtPower;
    IsCrit=rand()%10;
    hurtPower=myfairy->aggressivity;
    if(IsCrit>=8){
        //威力增加值也随机产生
        critNum=rand()%10;
        if(critNum==0) critNum=1;
        hurtPower+=critNum;
        ui->myCase_label->setText(QString("Attack Strongly with %1 power!!!").arg(hurtPower));
    }
    else ui->myCase_label->setText(QString("Attack with %1 power").arg(hurtPower));
    myfairy->attack(opponent,critNum);

    int IsDodge;
    IsDodge=rand()%10;
    if(IsDodge==5){
        ui->opponentCase_label->setText(QString("Dodge successfully!!!"));
    }else{
        ui->opponentCase_label->setText(QString("Hurted by %1 power").arg(hurtPower));
    }
    if(opponent->life<0){
        ui->opponentBlood_progressBar->setValue(0);
        gameIsOver=1;
        myAttackTimer->stop();
        opponentAttackTimer->stop();
        gameOver();
    }
    else{
        ui->opponentBlood_progressBar->setValue(opponent->life);
        myAttackTimer->start(myfairy->attack_interval*300);
    }
}

void battlefieldForm::opponentTimetoAttack(){
    if(gameIsOver) return;
    countHurt++;
    //避免攻击间隔相同的两个精灵得到的随机值也一样
    srand(time(NULL)+1);
    //随机产生暴击事件
    int IsCrit,critNum=0,hurtPower;
    IsCrit=rand()%10;
    hurtPower=opponent->aggressivity;
    if(IsCrit>=8){
        //威力增加值也随机产生
        critNum=rand()%10;
        if(critNum==0) critNum=1;
        hurtPower+=critNum;
        ui->opponentCase_label->setText(QString("Attack Strongly with %1 power!!!").arg(hurtPower));
    }
    else ui->opponentCase_label->setText(QString("Attack with %1 power").arg(hurtPower));
    opponent->attack(myfairy,critNum);
    int IsDodge;
    IsDodge=rand()%10;
    if(IsDodge==5){
        ui->myCase_label->setText(QString("Dodge successfully!!!"));
    }else{
        ui->myCase_label->setText(QString("Hurted by %1 power").arg(hurtPower));
    }
    if(myfairy->life<0){
        ui->myBlood_progressBar->setValue(0);
        gameIsOver=1;
        opponentAttackTimer->stop();
        myAttackTimer->stop();
        gameOver();
    }
    else{
        qDebug()<<"my life"<<myfairy->life;
        ui->myBlood_progressBar->setValue(myfairy->life);
        opponentAttackTimer->start(opponent->attack_interval*300);
    }
}

void battlefieldForm::gameOver(){
    qDebug()<<"gameOver";
    QString *myFairyName, *opponentName;
    myFairyName=new QString;
    opponentName=new QString;
    *myFairyName=ui->myFairyName_label->text();
    *opponentName=ui->opponentName_label->text();
    qDebug()<<battleType<<opponent->life<<countAttack<<countHurt<<*myFairyName<<*opponentName;
    if(opponent->life<=0){
        emit battleEnd(battleType,1,countAttack,countHurt,myFairyName,opponentName);
    }
    else{
        emit battleEnd(battleType,0,countAttack,countHurt,myFairyName,opponentName);
    }

}

//void battlefieldForm::giveAFairy(){
//    QString winStr, loseStr;
//    if(battleType) winStr="Congratulations! You can get your opponent fairy!";
//    else winStr=;
//    if(battleType) loseStr="What a pity! You have to lose one of your three fairies";
//    else loseStr="What a pity!";


//    if(opponent->life==0){
//        QMessageBox messageBox(QMessageBox::NoIcon,
//                               "Result", winStr,
//                               QMessageBox::Ok, NULL);
//        messageBox.exec();
//        messageBox.close();
//        emit battleEnd(battleType,1,countAttack,countHurt,myFairyName,opponentName);
//    }
//    else{
//        QMessageBox messageBox(QMessageBox::NoIcon,
//                               "Result", loseStr,
//                               QMessageBox::Ok, NULL);
//        messageBox.exec();
//        messageBox.close();
//        emit battleEnd(battleType,0,countAttack,countHurt,myFairyName,opponentName);
//    }
//}


void battlefieldForm::showBattleRes(QJsonObject *recvData){
    int i;
    QJsonArray myfairies;
    QList<QPushButton*> chooseButtonList;
    QString winTitle="WIN!";
    QString loseTitle="LOSE!";
    QString winMsg1="You can acquire your opponent!";
    QString loseMsg1="You have to choose one of these fairies to lose.";
    QString resMsg;
    QJsonObject* loseAFairyBag;
    int updateRes=recvData->value("updateRes").toInt();
    if(updateRes==0) resMsg="Your fairy upgrade!";
    else resMsg=QString("Your fairy earn %1 experiences!").arg(updateRes);
    QMessageBox msg;
    QPushButton* okButton;
    int winOrLose=(opponent->life<=0);
    if(opponent->life<=0) {
        msg.setWindowTitle(winTitle);
        if(battleType==1) {
            msg.setText(winMsg1.append(resMsg));
        }
        else msg.setText(resMsg);
        okButton=msg.addButton(QMessageBox::Ok);
    }
    else{
        msg.setWindowTitle(loseTitle);
        if(battleType==1){
            msg.setText(loseMsg1.append(resMsg));
            myfairies=recvData->value("mayGiveFairiesArray").toArray();
            for(i=0;i<myfairies.count();i++){
                QPushButton *button=msg.addButton(myfairies.at(i).toObject().value("fairyname").toString(),QMessageBox::ActionRole);
                chooseButtonList.append(button);
            }
        }
        else{
            okButton=msg.addButton(QMessageBox::Ok);
            msg.setText(resMsg);
        }
    }
   msg.exec();
   if(battleType&&!winOrLose){
       for(i=0;i<myfairies.count();i++)
           if(msg.clickedButton()==chooseButtonList.at(i)) {
               loseAFairyBag=new QJsonObject;
               *loseAFairyBag={
                   {"event",8},
                   {"fairyname",chooseButtonList.at(i)->text()}
               };

               emit sendLoseAFairyBag(loseAFairyBag);
           }
   }
   msg.close();
   gameIsOver=0;
}

void battlefieldForm::on_return_pushButton_clicked(){
    emit showUserFormReq();
}
