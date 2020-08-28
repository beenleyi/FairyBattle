#include<iostream>
using namespace std;
#include<string>
/**********fairy************/
class fairy
{
protected:
    /******
     * type
     * 0:powerful
     * 1:high life
     * 2:high defense
     * 3:sharp
     *****/
    int type;
    int stage;//0-15
    int experience;//0-100
    int aggressivity;//0-20
    int defense;//0-20
    int life;//0-
    int attack_interval;//0-10s
public:
    fairy(/* args */);
    ~fairy();
    virtual void upgrade();
    void check_attribute();
    virtual void attack(fairy* pfairy);
    virtual void hurted(int power);
};

fairy::fairy(/* args */)
{
}

fairy::~fairy()
{
}

void fairy::upgrade()
{
}

void fairy::check_attribute()
{
    if(aggressivity>20) aggressivity=20;
    if(defense>20) defense=20;
    if(life>200) life=200;
    if(attack_interval<1) attack_interval=1;
}

/**********Faye************/
class Faye:public fairy
{
private:
    /* data */
public:
    Faye(/* args */);
    ~Faye();
    virtual void upgrade();
    virtual void attack(fairy* pfairy);
    virtual void hurted(int power);
};

Faye::Faye(/* args */)
{
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

/**********Hebe************/
class Hebe:public fairy
{
private:
    /* data */
public:
    Hebe(/* args */);
    ~Hebe();
    virtual void upgrade();
    virtual void attack(fairy* pfairy);
    virtual void hurted(int power);
};

Hebe::Hebe(/* args */)
{
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

/**********Lala************/
class Lala:public fairy
{
private:
    /* data */
public:
    Lala(/* args */);
    ~Lala();
    virtual void upgrade();
    virtual void attack(fairy* pfairy);
    virtual void hurted(int power);
};

Lala::Lala(/* args */)
{
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

/**********Squirrel************/
class Squirrel:public fairy
{
private:
    /* data */
public:
    Squirrel(/* args */);
    ~Squirrel();
    virtual void upgrade();
    virtual void attack(fairy* pfairy);
    virtual void hurted(int power);
};

Squirrel::Squirrel(/* args */)
{
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

/**********Kay************/
class Kay:public fairy
{
private:
    /* data */
public:
    Kay(/* args */);
    ~Kay();
    virtual void upgrade();
    virtual void attack(fairy* pfairy);
    virtual void hurted(int power);
};

Kay::Kay(/* args */)
{
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

/**********Beenle************/
class Beenle:public fairy
{
private:
    /* data */
public:
    Beenle(/* args */);
    ~Beenle();
    virtual void upgrade();
    virtual void attack(fairy* pfairy);
    virtual void hurted(int power);
};

Beenle::Beenle(/* args */)
{
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