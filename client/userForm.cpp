#include "userForm.h"
#include "ui_userForm.h"

userForm::userForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userForm)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/fig/icon.ico"));
    this->setWindowTitle("Crazy Arcade");
    this->setWindowIcon(QIcon(":/fig/icon.ico"));
    this->setWindowTitle("Crazy Arcade");
    ui->fairy_tableWidget->verticalHeader()->setVisible(false);
    ui->fairy_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->fairy_tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->fairy_tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    fairyRows=8;
    userRows=11;
}

userForm::~userForm()
{
    delete ui;
}

void userForm::on_upgradeBattle_pushButton_clicked()
{

}

void userForm::on_signOut_pushButton_clicked()
{
    QJsonObject *signOutBag;
    signOutBag=new QJsonObject;
    *signOutBag={
        {"event",2}//2 for signout
    };
    emit sendMessageReq(signOutBag);
    emit showSignInFormReq();
    this->hide();
}

void userForm::setUsername(QString* tempUsername){
    ui->username_label->setText(*tempUsername);
    return;
}

void userForm::AddMyFairiesTable(QJsonObject* fairyObj){
    ui->fairy_tableWidget->clear();
    ui->fairy_tableWidget->setRowCount(0);
    ui->fairy_tableWidget->setColumnCount(fairyRows);
    QStringList header;
    header<<"Fairy"<<"type"<<"stage"<<"experience"<<"aggressivity"<<"defense"<<"life"<<"attack_interval";
    ui->fairy_tableWidget->setHorizontalHeaderLabels(header);
    QJsonArray myFairiesArray;
    if(fairyObj->contains("fairiesArray")){
        QJsonValue fairiesValue=fairyObj->take("fairiesArray");
        if (fairiesValue.isArray()) myFairiesArray=fairiesValue.toArray();
    }
    int fairiesNum;
    fairiesNum=myFairiesArray.count();
    for(int i=0;i<fairiesNum;i++){
        QString fairyname;
        int index,type,stage,experience,aggressivity,defense,life,attack_interval;
        fairyname=myFairiesArray.at(i).toObject().value("fairyname").toString();
        index=myFairiesArray.at(i).toObject().value("index").toInt();
        type=myFairiesArray.at(i).toObject().value("type").toInt();
        stage=myFairiesArray.at(i).toObject().value("stage").toInt();
        experience=myFairiesArray.at(i).toObject().value("experience").toInt();
        aggressivity=myFairiesArray.at(i).toObject().value("aggressivity").toInt();
        defense=myFairiesArray.at(i).toObject().value("defense").toInt();
        life=myFairiesArray.at(i).toObject().value("life").toInt();
        attack_interval=myFairiesArray.at(i).toObject().value("attack_interval").toInt();
        QString tempStr=QString("_%1").arg(index);
        int rowcount=ui->fairy_tableWidget->rowCount();
        QTableWidgetItem *itemFig=new QTableWidgetItem(QIcon(QString(":/fig/%1.png").arg((fairyname))),fairyname.append(tempStr));
        ui->fairy_tableWidget->insertRow(rowcount);
        ui->fairy_tableWidget->setItem(rowcount,0,itemFig);
        ui->fairy_tableWidget->setItem(rowcount,1,new QTableWidgetItem(QString("%1").arg(type)));
        ui->fairy_tableWidget->setItem(rowcount,2,new QTableWidgetItem(QString("%1").arg(stage)));
        ui->fairy_tableWidget->setItem(rowcount,3,new QTableWidgetItem(QString("%1").arg(experience)));
        ui->fairy_tableWidget->setItem(rowcount,4,new QTableWidgetItem(QString("%1").arg(aggressivity)));
        ui->fairy_tableWidget->setItem(rowcount,5,new QTableWidgetItem(QString("%1").arg(defense)));
        ui->fairy_tableWidget->setItem(rowcount,6,new QTableWidgetItem(QString("%1").arg(life)));
        ui->fairy_tableWidget->setItem(rowcount,7,new QTableWidgetItem(QString("%1").arg(attack_interval)));
    }
    int numBadge, stageBadge;
    numBadge=fairyObj->value("numBadge").toInt();
    stageBadge=fairyObj->value("stageBadge").toInt();
    QImage img;
    img.load(QString(":/fig/NumBadge%1.png").arg(numBadge));
    ui->NumBadge_label->setPixmap(QPixmap::fromImage(img));
    img.load(QString(":/fig/StageBadge%1.png").arg(stageBadge));
    ui->StageBadge_label->setPixmap(QPixmap::fromImage(img));
}

void userForm::showUserBag(QJsonObject *userBag){
    ui->fairy_tableWidget->setColumnCount(userRows);
    ui->fairy_tableWidget->setRowCount(0);
    ui->fairy_tableWidget->clear();
    QStringList header;
    header<<"username"<<"Faye"<<"Hebe"<<"Lala"<<"Squirrel"<<"Kay"<<"Beenle"<<"Win Rate"<<"NumBadge"<<"StageBadge"<<"online";
    ui->fairy_tableWidget->setHorizontalHeaderLabels(header);
    int reqOnlineOrNot=userBag->value("reqOnlineOrNot").toInt();
    if(reqOnlineOrNot) ui->tableTitle->setText("Online Users");
    else ui->tableTitle->setText("All Users");
    QJsonArray userArray;
    if(userBag->contains("userArray")){
        QJsonValue userValue=userBag->take("userArray");
        if (userValue.isArray()) userArray=userValue.toArray();
    }
    int userNum;
    userNum=userArray.count();

    for(int i=0;i<userNum;i++){
        int rowcount=ui->fairy_tableWidget->rowCount();
        ui->fairy_tableWidget->insertRow(rowcount);
        int numBadge, stageBadge;
        numBadge=userArray.at(i).toObject().value("FairiesNumBadge").toInt();
        stageBadge=userArray.at(i).toObject().value("FairiesStageBadge").toInt();
        ui->fairy_tableWidget->setItem(rowcount,8,new QTableWidgetItem(QIcon(QString(":/fig/NumBadge%1.png").arg(numBadge)),""));
        ui->fairy_tableWidget->setItem(rowcount,9,new QTableWidgetItem(QIcon(QString(":/fig/StageBadge%1.png").arg(stageBadge)),""));
        ui->fairy_tableWidget->setItem(rowcount,0,new QTableWidgetItem(userArray.at(i).toObject().value("username").toString()));
        ui->fairy_tableWidget->setItem(rowcount,1,new QTableWidgetItem(QString("%1").arg(userArray.at(i).toObject().value("FayeNum").toInt())));
        ui->fairy_tableWidget->setItem(rowcount,2,new QTableWidgetItem(QString("%1").arg(userArray.at(i).toObject().value("HebeNum").toInt())));
        ui->fairy_tableWidget->setItem(rowcount,3,new QTableWidgetItem(QString("%1").arg(userArray.at(i).toObject().value("LalaNum").toInt())));
        ui->fairy_tableWidget->setItem(rowcount,4,new QTableWidgetItem(QString("%1").arg(userArray.at(i).toObject().value("SquirrelNum").toInt())));
        ui->fairy_tableWidget->setItem(rowcount,5,new QTableWidgetItem(QString("%1").arg(userArray.at(i).toObject().value("KayNum").toInt())));
        ui->fairy_tableWidget->setItem(rowcount,6,new QTableWidgetItem(QString("%1").arg(userArray.at(i).toObject().value("BeenleNum").toInt())));
        ui->fairy_tableWidget->setItem(rowcount,7,new QTableWidgetItem(QString("%1").arg(userArray.at(i).toObject().value("Win Rate").toDouble())));
        ui->fairy_tableWidget->setItem(rowcount,10,new QTableWidgetItem(QString("%1").arg(userArray.at(i).toObject().value("online").toInt())));
    }
}

void userForm::on_lookUpOnlineUsers_pushButton_clicked(){
    QJsonObject *lookUpOnlineUsersBag;
    lookUpOnlineUsersBag=new QJsonObject;
    *lookUpOnlineUsersBag={
        {"event",4}
    };
    emit sendMessageReq(lookUpOnlineUsersBag);
}

void userForm::on_lookUpAllUsers_pushButton_clicked(){
    QJsonObject *lookUpAllUsersBag;
    lookUpAllUsersBag=new QJsonObject;
    *lookUpAllUsersBag={
        {"event",5}
    };
    emit sendMessageReq(lookUpAllUsersBag);
}

void userForm::on_myFairies_pushButton_clicked(){
    emit needMyFairies();
}

void userForm::on_battle_pushButton_clicked(){
//    QList<QTableWidgetItem*> items=ui->fairy_tableWidget->selectedItems();
//    if(items.count()==0){
//        qDebug()<<"no selected";
//    }else{
//        int row=ui->fairy_tableWidget->row(items.at(1));
//        QString tempName=ui->fairy_tableWidget->item(row,1)->text();
//        QString *fairyName=new QString;
//        *fairyName=tempName.section('_',0,0);
//        int stage=ui->fairy_tableWidget->item(row,3)->text().toInt();
//        int experience=ui->fairy_tableWidget->item(row,4)->text().toInt();
//        int aggressivity=ui->fairy_tableWidget->item(row,5)->text().toInt();
//        int defense=ui->fairy_tableWidget->item(row,6)->text().toInt();
//        int life=ui->fairy_tableWidget->item(row,7)->text().toInt();
//        int attack_interval=ui->fairy_tableWidget->item(row,8)->text().toInt();
//        int index=getFairyIndex(fairyName);
//        fairy *tempfairy=NULL;
//        switch (index) {
//        case 0:
//            Faye* tempFaye;
//            tempFaye=new Faye;
//            tempfairy=tempFaye;
//            break;
//        case 1:
//            Hebe* tempHebe;
//            tempHebe=new Hebe;
//            tempfairy=tempHebe;
//            break;
//        case 2:
//            Lala* tempLala;
//            tempLala=new Lala;
//            tempfairy=tempLala;
//            break;
//        case 3:
//            Squirrel* tempSquirrel;
//            tempSquirrel=new Squirrel;
//            tempfairy=tempSquirrel;
//            break;
//        case 4:
//            Kay* tempKay;
//            tempKay=new Kay;
//            tempfairy=tempKay;
//            break;
//        case 5:
//            Beenle* tempBeenle;
//            tempBeenle=new Beenle;
//            tempfairy=tempBeenle;
//            break;
//        }
//        if(tempfairy!=NULL){
//            tempfairy->aggressivity=aggressivity;
//            tempfairy->attack_interval=attack_interval;
//            tempfairy->defense=defense;
//            tempfairy->experience=experience;
//            tempfairy->life=life;
//            tempfairy->stage=stage;
//            emit gotoSelectOpponent(tempfairy);
//        }


//    }
    emit gotoSelectOpponent();
}


