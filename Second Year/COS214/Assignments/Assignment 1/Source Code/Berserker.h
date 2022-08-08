#ifndef BERSERKER_H
#define BERSERKER_H

#include "Soldier.h"
#include <iostream>

using namespace std;

class Berserker : public Soldier {
private:

public:
    Berserker(string, int, string, string, int);
    ~Berserker();

    bool hitZombie(Zombie* z);
    void celebrate();
    bool getHit(Zombie* z);
    void die();
};

#endif