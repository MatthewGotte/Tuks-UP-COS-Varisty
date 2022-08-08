#ifndef ENGINEER_H
#define ENGINEER_H

#include "Soldier.h"
#include <iostream>

using namespace std;

class Engineer : public Soldier {
private:

public:
    Engineer(string, int, string, string, int);
    ~Engineer();

    bool hitZombie(Zombie* z);
    void celebrate();
    bool getHit(Zombie* z);
    void die();
};

#endif