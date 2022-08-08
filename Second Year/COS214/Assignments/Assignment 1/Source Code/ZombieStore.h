#ifndef ZOMBIESTORE_H
#define ZOMBIESTORE_H

#include "ZombieMemento.h"

class ZombieStore {
private:
    ZombieMemento* mem;
public:
    ~ZombieStore();

    void storeMemento(ZombieMemento*);
    ZombieMemento* getMemento();

};

#endif