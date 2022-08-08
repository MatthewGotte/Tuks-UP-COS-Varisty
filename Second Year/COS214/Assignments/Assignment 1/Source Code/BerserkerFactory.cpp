#include "BerserkerFactory.h"
#include "Berserker.h"
#include "Sniper.h"

BerserkerFactory::BerserkerFactory() {

}

BerserkerFactory::~BerserkerFactory() {

}

Soldier *BerserkerFactory::createSoldier(string name) {
    return new Berserker(name, 10, "Big Chainsaw", "secondary", 4);
}