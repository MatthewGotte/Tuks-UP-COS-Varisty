#ifndef SOLDIERSTORE_H
#define SOLDIERSTORE_H

#include "SoldierMemento.h"

class SoldierStore {
private:
    SoldierMemento* mem;
public:
    ~SoldierStore();

    void storeMemento(SoldierMemento*);
    SoldierMemento* getMemento();
};

#endif