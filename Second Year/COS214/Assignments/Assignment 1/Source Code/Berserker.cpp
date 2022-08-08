#include "Berserker.h"

Berserker::Berserker(string name, int HP, string primary, string secondary, int damage) : Soldier(name, HP, primary, secondary, damage) {

}

Berserker::~Berserker() {

}

bool Berserker::hitZombie(Zombie *z) {
    int zombie_hp = z->takeDamage(this->getDamage());
    cout << "Berserker " << this->getName() << " swings a " << this->getPrimaryWeapon() << " at the zombie's head." << endl;
    if (zombie_hp <= 0)
        return true;
    return false;
}

void Berserker::celebrate() {
    cout << this->getName() << " slices the zombie in half!" << endl;
}

bool Berserker::getHit(Zombie *z) {
    //get damage
    int zombie_damage = z->getDamage();
    //remove from soldier
    this->takeDamage(zombie_damage);
    cout << this->getName() << " pretends not to notice the " << zombie_damage << " damage he takes." << endl;
    if (this->getHP() <= 0)
        return true;
    return false;
}

void Berserker::die() {
    cout << "Nobody really liked " << this->getName() << "'s company, anyway." << endl;
}