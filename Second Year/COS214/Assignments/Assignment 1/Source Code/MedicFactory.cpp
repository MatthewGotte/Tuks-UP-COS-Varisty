#include "MedicFactory.h"

MedicFactory::MedicFactory() {

}

MedicFactory::~MedicFactory() {

}

Soldier *MedicFactory::createSoldier(string name) {
    return new Medic(name, 8, "Syringe", "secondary", 2);
}