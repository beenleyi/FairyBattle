#include "selectopponentform.h"
#include "ui_selectopponentform.h"

selectOpponentForm::selectOpponentForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectOpponentForm)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/fig/icon.ico"));
    this->setWindowTitle("Crazy Arcade");
}

selectOpponentForm::~selectOpponentForm()
{
    delete ui;
}

void selectOpponentForm::on_upgradeBattle_pushButton_clicked(){

    QJsonObject *myFairyInfoObject=new QJsonObject;
    *myFairyInfoObject=ui->serverFairies_comboBox->currentData().toJsonObject();
    QJsonObject *opponentFairyInfoObject=new QJsonObject;
    *opponentFairyInfoObject=ui->userFairies_comboBox->currentData().toJsonObject();
    emit gotoBattlefield(0,myFairyInfoObject,opponentFairyInfoObject);

}

void selectOpponentForm::on_winLoseBattle_pushButton_clicked(){
    qDebug()<<"clicked";
    QJsonObject *myFairyInfoObject=new QJsonObject;
    *myFairyInfoObject=ui->serverFairies_comboBox->currentData().toJsonObject();
    QJsonObject *opponentFairyInfoObject=new QJsonObject;
    *opponentFairyInfoObject=ui->userFairies_comboBox->currentData().toJsonObject();
    emit gotoBattlefield(1,myFairyInfoObject,opponentFairyInfoObject);
    qDebug()<<"emit";
}

//void selectOpponentForm::showMyFairy(fairy *myBattleFairy){
//    QString myFairyInfo=QString("fairyname:'%1'\n").arg(myBattleFairy->fairyname);
//    myFairyInfo.append(QString("type:%1\n").arg(myBattleFairy->type));
//    myFairyInfo.append(QString("stage:%1\n").arg(myBattleFairy->stage));
//    myFairyInfo.append(QString("experience:%1\n").arg(myBattleFairy->experience));
//    myFairyInfo.append(QString("aggressivity:%1\n").arg(myBattleFairy->aggressivity));
//    myFairyInfo.append(QString("defense:%1\n").arg(myBattleFairy->defense));
//    myFairyInfo.append(QString("attack_interval:%1\n").arg(myBattleFairy->attack_interval));
//    ui->myFairy_textBrowser->setText(myFairyInfo);
//}

void selectOpponentForm::showBattleFairy(QJsonObject* battleFairiesBag){
    qDebug()<<"start show";
    QJsonArray serverFairiesArray;
    if(battleFairiesBag->contains("serverFairies")){
        QJsonValue serverFairiesArrayValue=battleFairiesBag->take("serverFairies");
        if (serverFairiesArrayValue.isArray()) serverFairiesArray=serverFairiesArrayValue.toArray();
    }

    int serverFairiesNum;
    serverFairiesNum=serverFairiesArray.count();
    for(int i=0;i<serverFairiesNum;i++){
        QJsonObject fairyObject=serverFairiesArray.at(i).toObject();
        QString fairyname=fairyObject.value("fairyname").toString();
        fairyname.append(QString("_%1").arg(fairyObject.value("index").toInt()));
        qDebug()<<fairyname;
        ui->serverFairies_comboBox->addItem(fairyname,QVariant(fairyObject));
    }

    QJsonArray userFairiesArray;
    if(battleFairiesBag->contains("userFairies")){
        QJsonValue userFairiesArrayValue=battleFairiesBag->take("userFairies");
        if (userFairiesArrayValue.isArray()) userFairiesArray=userFairiesArrayValue.toArray();
    }

    int userFairiesNum;
    userFairiesNum=userFairiesArray.count();
    for(int i=0;i<userFairiesNum;i++){
        QJsonObject fairyObject=userFairiesArray.at(i).toObject();
        QString fairyname=fairyObject.value("fairyname").toString();
        fairyname.append(QString("_%1").arg(fairyObject.value("index").toInt()));
        qDebug()<<fairyname;
        ui->userFairies_comboBox->addItem(fairyname,QVariant(fairyObject));
    }
    //delete battleFairiesBag;
    qDebug()<<"end show";
}

void selectOpponentForm::on_serverFairies_comboBox_currentIndexChanged(const QString &arg1){
    QJsonObject fairyInfoObject=ui->serverFairies_comboBox->currentData().toJsonObject();
    QString fairyInfo;
    fairyInfo=QString("type:%1\n").arg(fairyInfoObject.value("type").toInt());
    fairyInfo.append(QString("stage:%1\n").arg(fairyInfoObject.value("stage").toInt()));
    fairyInfo.append(QString("experience:%1\n").arg(fairyInfoObject.value("experience").toInt()));
    fairyInfo.append(QString("life:%1\n").arg(fairyInfoObject.value("life").toInt()));
    fairyInfo.append(QString("aggressivity:%1\n").arg(fairyInfoObject.value("aggressivity").toInt()));
    fairyInfo.append(QString("defense:%1\n").arg(fairyInfoObject.value("defense").toInt()));
    fairyInfo.append(QString("attack_interval:%1\n").arg(fairyInfoObject.value("attack_interval").toInt()));
    ui->opponentFairy_textBrowser->setText(fairyInfo);
}

void selectOpponentForm::on_userFairies_comboBox_currentIndexChanged(const QString &arg1){
    QJsonObject fairyInfoObject=ui->userFairies_comboBox->currentData().toJsonObject();
    QString fairyInfo;
    fairyInfo=QString("type:'%1'\n").arg(fairyInfoObject.value("type").toInt());
    fairyInfo.append(QString("stage:'%1'\n").arg(fairyInfoObject.value("stage").toInt()));
    fairyInfo.append(QString("experience:'%1'\n").arg(fairyInfoObject.value("experience").toInt()));
    fairyInfo.append(QString("life:'%1'\n").arg(fairyInfoObject.value("life").toInt()));
    fairyInfo.append(QString("aggressivity:'%1'\n").arg(fairyInfoObject.value("aggressivity").toInt()));
    fairyInfo.append(QString("defense:'%1'\n").arg(fairyInfoObject.value("defense").toInt()));
    fairyInfo.append(QString("attack_interval:'%1'\n").arg(fairyInfoObject.value("attack_interval").toInt()));
    ui->myFairy_textBrowser->setText(fairyInfo);
}



