#ifndef ZOMBIEMEMENTO_H
#define ZOMBIEMEMENTO_H

#include <iostream>
#include "ZombieState.h"
class Zombie;
using namespace std;

class ZombieMemento {
private:
    ZombieState * state;
    friend class Zombie;
    ZombieMemento(string, int, int);
public:
    virtual ~ZombieMemento();
};

#endif