#include "Medic.h"

Medic::Medic(string name, int HP, string primary, string secondary, int damage): Soldier(name, HP, primary, secondary, damage) {

}

Medic::~Medic() {

}

bool Medic::hitZombie(Zombie *z) {
    int zombie_hp = z->takeDamage(this->getDamage());
    cout << "Medic " << this->getName() << " frantically stabs at the zombie with a " << this->getPrimaryWeapon() << endl;
    if (zombie_hp <= 0)
        return true;
    return false;
}

void Medic::celebrate() {
    cout << this->getName() << " sighs in relief." << endl;
}

bool Medic::getHit(Zombie *z) {
    //get damage
    int zombie_damage = z->getDamage();
    //remove from soldier
    this->takeDamage(zombie_damage);
    cout << this->getName() << " gives himself painkillers to numb the " << zombie_damage << " damage suffered." << endl;
    if (this->getHP() <= 0)
        return true;
    return false;
}

void Medic::die() {
    cout << "After saving so many lives, " << this->getName() << " could not save himself." << endl;
}