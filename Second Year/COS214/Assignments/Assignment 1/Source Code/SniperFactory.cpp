#include "SniperFactory.h"

SniperFactory::SniperFactory() {

}

SniperFactory::~SniperFactory() {

}

Soldier *SniperFactory::createSoldier(string name) {
    return new Sniper(name, 6, ".308 Rifle", "secondary", 5);
}
