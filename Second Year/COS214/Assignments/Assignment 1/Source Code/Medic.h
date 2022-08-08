#ifndef MEDIC_H
#define MEDIC_H

#include "Soldier.h"
#include <iostream>

using namespace std;

class Medic : public Soldier {
private:

public:
    Medic(string, int, string, string, int);
    ~Medic();

    bool hitZombie(Zombie* z);
    void celebrate();
    bool getHit(Zombie* z);
    void die();
};

#endif