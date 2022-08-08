#ifndef SOLDIERMEMENTO_H
#define SOLDIERMEMENTO_H

#include <iostream>
#include "SoldierState.h"
class Soldier;

using namespace std;

class SoldierMemento {
private:
    SoldierState * state;
    friend class Soldier;
    SoldierMemento(string, string, string, int, int);
public:
    virtual ~SoldierMemento();
};

#endif