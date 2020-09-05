#include <QString>
/**********fairy************/
#include <QDebug>
#include <QWidget>
#include "battlefieldform.h"
class fairy:public QWidget
{


protected:
    /******
     * type
     * 0:powerful
     * 1:high life
     * 2:high defense
     * 3:sharp
     *****/
    //QString username;
    QString fairyname;
    int type;
    int stage;//0-15
    int experience;//0-100
    int aggressivity;//0-20
    int defense;//0-20
    int life;//0-
    int attack_interval;//0-10s
public:
    fairy(int,int,int,int,int,int,int);
    ~fairy();
    virtual void upgrade()=0;
    void check_attribute();
    virtual void attack(fairy*,int)=0;
    virtual void hurted(int power)=0;
    friend class battlefieldForm;


};


/**********Faye************/
class Faye:public fairy
{
    //

private:
    /* data */
public:
    Faye(int,int,int,int,int,int,int);
    ~Faye();
    virtual void upgrade();
    virtual void attack(fairy* , int);
    virtual void hurted(int power);
    friend class battlefieldForm;


};

/**********Hebe************/
class Hebe:public fairy
{
    //

private:
    /* data */
public:
    Hebe(int,int,int,int,int,int,int);
    ~Hebe();
    virtual void upgrade();
    virtual void attack(fairy* , int);
    virtual void hurted(int power);
    friend class battlefieldForm;


};

/**********Lala************/
class Lala:public fairy
{
    //

private:
    /* data */
public:
    Lala(int,int,int,int,int,int,int);
    ~Lala();
    virtual void upgrade();
    virtual void attack(fairy* , int);
    virtual void hurted(int power);
    friend class battlefieldForm;


};

/**********Squirrel************/
class Squirrel:public fairy
{
    //

private:
    /* data */
public:
    Squirrel(int,int,int,int,int,int,int);
    ~Squirrel();
    virtual void upgrade();
    virtual void attack(fairy* , int);
    virtual void hurted(int power);
    friend class battlefieldForm;


};


/**********Kay************/
class Kay:public fairy
{
    //

private:
    /* data */
public:
    Kay(int,int,int,int,int,int,int);
    ~Kay();
    virtual void upgrade();
    virtual void attack(fairy*, int);
    virtual void hurted(int);
    friend class battlefieldForm;


};

/**********Beenle************/
class Beenle:public fairy
{
    //

private:
    /* data */
public:
    Beenle(int,int,int,int,int,int,int);
    ~Beenle();
    virtual void upgrade();
    virtual void attack(fairy* , int);
    virtual void hurted(int power);
    friend class battlefieldForm;


};
