#ifndef SNIPERFACTORY_H
#define SNIPERFACTORY_H

#include "SoldierFactory.h"
#include "Soldier.h"
#include "Sniper.h"

class SniperFactory : public SoldierFactory {
public:
    SniperFactory();
    ~SniperFactory();

    Soldier* createSoldier(string);
};

#endif