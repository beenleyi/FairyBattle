#include "fairy.h"

fairy::fairy(int _type,int _stage, int _experience, int _aggre, int _defense, int _life, int _attack_int)
{
    type=_type;
    stage=_stage;
    experience=_experience;
    aggressivity=_aggre;
    defense=_defense;
    life=_life;
    attack_interval=_attack_int;
    //qDebug()<<type<<stage<<experience<<aggressivity<<defense;
}

fairy::~fairy()
{
}

void fairy::check_attribute()
{
    if(aggressivity>20) aggressivity=20;
    if(defense>20) defense=20;
    if(life>150) life=200;
    if(attack_interval<1) attack_interval=1;
}

int fairy::update(int winOrLose, int countAttack, int countHurt){
    int addNum;
    if(winOrLose) addNum=(countAttack*5+countHurt*3)*1.5;
    else addNum=countAttack*5+countHurt*3;
    experience+=addNum;
    if(experience>100) {
        this->upgrade();
        return 0;
    }else return addNum;
}

Faye::Faye(int _type,int _stage, int _experience, int _aggre, int _defense, int _life, int _attack_int)
    :fairy(_type,_stage,_experience,_aggre,_defense,_life,_attack_int)
{
    fairyname="Faye";
}

Faye::~Faye()
{
}

void Faye::upgrade(){
    if(stage==15) return;
    else{
        ++stage;
        experience=0;
        ++aggressivity;
        defense+=2;
        --attack_interval;
    }
    check_attribute();
}

void Faye::attack(fairy* pfairy, int critNum=0){
    pfairy->hurted(aggressivity+critNum);
}

void Faye::hurted(int power){
    life-=power;
}

Hebe::Hebe(int _type,int _stage, int _experience, int _aggre, int _defense, int _life, int _attack_int)
    :fairy(_type,_stage,_experience,_aggre,_defense,_life,_attack_int)
{
    fairyname="Hebe";
//    type=3;
//    stage=1;
//    experience=0;
//    aggressivity=5;
//    defense=4;
//    life=100;
//    attack_interval=4;
}

Hebe::~Hebe()
{
}

void Hebe::upgrade(){
    if(stage==15) return;
    else{
        ++stage;
        experience=0;
        ++aggressivity;
        ++defense;
        attack_interval-=2;
    }
    check_attribute();
}

void Hebe::attack(fairy* pfairy, int critNum=0){
    pfairy->hurted(aggressivity+critNum);
}

void Hebe::hurted(int power){
    life-=power;
}


Lala::Lala(int _type,int _stage, int _experience, int _aggre, int _defense, int _life, int _attack_int)
     :fairy(_type,_stage,_experience,_aggre,_defense,_life,_attack_int)
{
    fairyname="Lala";
//    type=3;
//    stage=1;
//    experience=0;
//    aggressivity=4;
//    defense=5;
//    life=100;
//    attack_interval=4;
}

Lala::~Lala()
{
}

void Lala::upgrade(){
    if(stage==15) return;
    else{
        ++stage;
        experience=0;
        ++aggressivity;
        ++defense;
        attack_interval-=2;
    }
    check_attribute();
}

void Lala::attack(fairy* pfairy, int critNum=0){
    pfairy->hurted(aggressivity+critNum);
}

void Lala::hurted(int power){
    life-=power;
}

Squirrel::Squirrel(int _type,int _stage, int _experience, int _aggre, int _defense, int _life, int _attack_int)
     :fairy(_type,_stage,_experience,_aggre,_defense,_life,_attack_int)
{
    fairyname="Squirrel";
//    type=0;
//    stage=1;
//    experience=0;
//    aggressivity=4;
//    defense=3;
//    life=100;
//    attack_interval=8;
}

Squirrel::~Squirrel()
{
}

void Squirrel::upgrade(){
    if(stage==15) return;
    else{
        ++stage;
        experience=0;
        aggressivity+=2;
        ++defense;
        --attack_interval;
    }
    check_attribute();
}

void Squirrel::attack(fairy* pfairy, int critNum=0){
    pfairy->hurted(aggressivity+critNum);
}

void Squirrel::hurted(int power){
    life-=power;
}

Kay::Kay(int _type,int _stage, int _experience, int _aggre, int _defense, int _life, int _attack_int)
     :fairy(_type,_stage,_experience,_aggre,_defense,_life,_attack_int)
{
    fairyname="Kay";
//    type=1;
//    stage=1;
//    experience=0;
//    aggressivity=2;
//    defense=6;
//    life=100;
//    attack_interval=6;
}

Kay::~Kay()
{
}

void Kay::upgrade(){
    if(stage==15) return;
    else{
        ++stage;
        experience=0;
        ++aggressivity;
        ++defense;
        attack_interval-=2;
        life+=5;
    }
    check_attribute();
}

void Kay::attack(fairy* pfairy, int critNum=0){
    pfairy->hurted(aggressivity+critNum);
}

void Kay::hurted(int power){
    life-=power;
}

Beenle::Beenle(int _type,int _stage, int _experience, int _aggre, int _defense, int _life, int _attack_int)
     :fairy(_type,_stage,_experience,_aggre,_defense,_life,_attack_int)
{
    fairyname="Beenle";
//    type=2;
//    stage=1;
//    experience=0;
//    aggressivity=5;
//    defense=2;
//    life=100;
//    attack_interval=5;
}

Beenle::~Beenle()
{
}

void Beenle::upgrade(){
    if(stage==15) return;
    else{
        ++stage;
        experience=0;
        ++aggressivity;
        defense+=2;
        --attack_interval;
    }  
    check_attribute();
}

void Beenle::attack(fairy* pfairy, int critNum=0){
    pfairy->hurted(aggressivity+critNum);
}

void Beenle::hurted(int power){
    life-=power;
}
