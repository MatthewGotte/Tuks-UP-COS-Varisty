#include "Engineer.h"

Engineer::Engineer(string name, int HP, string primary, string secondary, int damage) : Soldier(name, HP, primary, secondary, damage) {

}

Engineer::~Engineer() {

}

bool Engineer::hitZombie(Zombie *z) {
    int zombie_hp = z->takeDamage(this->getDamage());
    cout << "Engineer " << this->getName() << " bludgeons the zombie with a " << this->getPrimaryWeapon() << endl;
    if (zombie_hp <= 0)
        return true;
    return false;
}

void Engineer::celebrate() {
    cout << this->getName() << " shakes his " << this->getPrimaryWeapon() << " at the zombie's remains." << endl;
}

bool Engineer::getHit(Zombie *z) {
    //get damage
    int zombie_damage = z->getDamage();
    //remove from soldier
    this->takeDamage(zombie_damage);
    cout << this->getName() << " hides behind the nearest rock after taking " << zombie_damage << " damage." << endl;
    if (this->getHP() <= 0)
        return true;
    return false;
}

void Engineer::die() {
    cout << this->getName() << " was eaten by a zombie." << endl;
}