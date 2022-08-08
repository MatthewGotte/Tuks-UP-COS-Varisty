#ifndef MEDICFACTORY_H
#define MEDICFACTORY_H

#include "SoldierFactory.h"
#include "Soldier.h"
#include "Medic.h"

class MedicFactory : public SoldierFactory {
public:
    MedicFactory();
    ~MedicFactory();

    Soldier* createSoldier(string);
};

#endif