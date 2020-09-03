#include <QString>
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
    QString username;
    QString fairyname;
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
    virtual void upgrade()=0;
    void check_attribute();
    virtual void attack(fairy* pfairy)=0;
    virtual void hurted(int power)=0;
};


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
