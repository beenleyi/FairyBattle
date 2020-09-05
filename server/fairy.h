#include <QString>
/**********fairy************/
#include <QDebug>
#include <QWidget>
class myTcpServer;
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
    friend class myTcpServer;
    int update(int, int, int);
};


/**********Faye************/
class Faye:public fairy
{
    //

private:
    /* data */
public:
    Faye(int _type=2,int _stage=1, int _experience=0, int _aggre=3, int _defense=8, int _life=100, int _attack_int=7);
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
    Hebe(int _type=2,int _stage=1, int _experience=0, int _aggre=3, int _defense=8, int _life=100, int _attack_int=7);
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
    Lala(int _type=2,int _stage=1, int _experience=0, int _aggre=3, int _defense=8, int _life=100, int _attack_int=7);
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
    Squirrel(int _type=2,int _stage=1, int _experience=0, int _aggre=3, int _defense=8, int _life=100, int _attack_int=7);
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
    Kay(int _type=2,int _stage=1, int _experience=0, int _aggre=3, int _defense=8, int _life=100, int _attack_int=7);
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
    Beenle(int _type=2,int _stage=1, int _experience=0, int _aggre=3, int _defense=8, int _life=100, int _attack_int=7);
    ~Beenle();
    virtual void upgrade();
    virtual void attack(fairy* , int);
    virtual void hurted(int power);
    friend class battlefieldForm;


};
