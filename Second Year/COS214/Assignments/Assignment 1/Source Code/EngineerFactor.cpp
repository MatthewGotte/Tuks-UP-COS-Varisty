#include "EngineerFactory.h"

EngineerFactory::EngineerFactory() {

}

EngineerFactory::~EngineerFactory() {

}

Soldier *EngineerFactory::createSoldier(string name) {
    return new Engineer(name, 7, "Wrench", "secondary", 3);
}