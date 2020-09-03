#include "fairy.h"

fairy::fairy(/* args */)
{
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


Faye::Faye(/* args */)
{
    fairyname="Faye";
    type=2;
    stage=1;
    experience=0;
    aggressivity=3;
    defense=8;
    life=100;
    attack_interval=7;
}

Faye::~Faye()
{
}

void Faye::upgrade(){
    if(stage==15) return;
    else{
        experience=0;
        ++aggressivity;
        defense+=2;
        --attack_interval;
    }
    fairy::check_attribute();
}

void Faye::attack(fairy* pfairy){
    pfairy->hurted(aggressivity);
}

void Faye::hurted(int power){
    life-=power;
}

Hebe::Hebe(/* args */)
{
    fairyname="Hebe";
    type=3;
    stage=1;
    experience=0;
    aggressivity=5;
    defense=4;
    life=100;
    attack_interval=4;
}

Hebe::~Hebe()
{
}

void Hebe::upgrade(){
    if(stage==15) return;
    else{
        experience=0;
        ++aggressivity;
        ++defense;
        attack_interval-=2;
    }
    fairy::check_attribute();
}

void Hebe::attack(fairy* pfairy){
    pfairy->hurted(aggressivity);
}

void Hebe::hurted(int power){
    life-=power;
}


Lala::Lala(/* args */)
{
    fairyname="Lala";
    type=3;
    stage=1;
    experience=0;
    aggressivity=4;
    defense=5;
    life=100;
    attack_interval=4;
}

Lala::~Lala()
{
}

void Lala::upgrade(){
    if(stage==15) return;
    else{
        experience=0;
        ++aggressivity;
        ++defense;
        attack_interval-=2;
    }
    fairy::check_attribute();
}

void Lala::attack(fairy* pfairy){
    pfairy->hurted(aggressivity);
}

void Lala::hurted(int power){
    life-=power;
}

Squirrel::Squirrel(/* args */)
{
    fairyname="Squirrel";
    type=0;
    stage=1;
    experience=0;
    aggressivity=4;
    defense=3;
    life=100;
    attack_interval=8;
}

Squirrel::~Squirrel()
{
}

void Squirrel::upgrade(){
    if(stage==15) return;
    else{
        experience=0;
        aggressivity+=2;
        ++defense;
        --attack_interval;
    }
    fairy::check_attribute();
}

void Squirrel::attack(fairy* pfairy){
    pfairy->hurted(aggressivity);
}

void Squirrel::hurted(int power){
    life-=power;
}

Kay::Kay(/* args */)
{
    fairyname="Kay";
    type=1;
    stage=1;
    experience=0;
    aggressivity=2;
    defense=6;
    life=100;
    attack_interval=6;
}

Kay::~Kay()
{
}

void Kay::upgrade(){
    if(stage==15) return;
    else{
        experience=0;
        ++aggressivity;
        ++defense;
        attack_interval-=2;
        life+=5;
    }
    fairy::check_attribute();
}

void Kay::attack(fairy* pfairy){
    pfairy->hurted(aggressivity);
}

void Kay::hurted(int power){
    life-=power;
}

Beenle::Beenle(/* args */)
{
    fairyname="Beenle";
    type=2;
    stage=1;
    experience=0;
    aggressivity=5;
    defense=2;
    life=100;
    attack_interval=5;
}

Beenle::~Beenle()
{
}

void Beenle::upgrade(){
    if(stage==15) return;
    else{
        experience=0;
        ++aggressivity;
        defense+=2;
        --attack_interval;
    }  
    fairy::check_attribute();
}

void Beenle::attack(fairy* pfairy){
    pfairy->hurted(aggressivity);
}

void Beenle::hurted(int power){
    life-=power;
}
