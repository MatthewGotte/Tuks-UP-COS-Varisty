#ifndef SOLDIER_H
#define SOLDIER_H
#include "Zombie.h"
#include "SoldierMemento.h"

#include <string>

using namespace std;

class Soldier {
private:
    string name;
    int HP;
    string primary_weapon;
    string secondary_weapon;
    int damage;

public:
    Soldier(string, int, string, string, int);
    ~Soldier();

    void attack(Zombie * z);
    SoldierMemento* createMemento();
    void reinstateMemento(SoldierMemento*);

    virtual bool hitZombie(Zombie* z) = 0;
    virtual void celebrate() = 0;
    virtual bool getHit(Zombie* z) = 0;
    virtual void die() = 0;

    string getName();
    void setName(string);

    int getHP();
    int setHP(int);

    void takeDamage(int);

    string getPrimaryWeapon();
    void setPrimaryWeapon(string);

    string getSecondaryWeapon();
    void setSecondaryWeapon(string);

    int getDamage();
    int setDamage(int);

};

#endif