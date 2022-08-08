#ifndef ENGINEERFACTORY_H
#define ENGINEERFACTORY_H

#include "SoldierFactory.h"
#include "Soldier.h"
#include "Engineer.h"

class EngineerFactory : public SoldierFactory {
public:
    EngineerFactory();
    ~EngineerFactory();

    Soldier* createSoldier(string);
};

#endif