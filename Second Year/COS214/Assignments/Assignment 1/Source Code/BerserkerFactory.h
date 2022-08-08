#ifndef BERSERKERFACTORY_H
#define BERSERKERFACTORY_H

#include "SoldierFactory.h"
#include "Soldier.h"
#include "Berserker.h"

class BerserkerFactory : public SoldierFactory {
public:
    BerserkerFactory();
    ~BerserkerFactory();

    Soldier* createSoldier(string);
};

#endif