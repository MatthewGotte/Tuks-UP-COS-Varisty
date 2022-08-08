#ifndef SNIPER_H
#define SNIPER_H

#include "Soldier.h"
#include <iostream>

using namespace std;

class Sniper : public Soldier {
private:

public:
    Sniper(string, int, string, string, int);
    ~Sniper();

    bool hitZombie(Zombie* z);
    void celebrate();
    bool getHit(Zombie* z);
    void die();
};

#endif