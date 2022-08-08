#include "Sniper.h"

Sniper::Sniper(string name, int HP, string primary, string secondary, int damage) : Soldier(name, HP, primary, secondary, damage) {

}

Sniper::~Sniper() {

}

bool Sniper::hitZombie(Zombie *z) {
    int zombie_hp = z->takeDamage(this->getDamage());
    cout << "Sniper " << this->getName() << " fires a " << this->getPrimaryWeapon() << " at the zombie." << endl;
    if (zombie_hp <= 0)
        return true;
    return false;
}

void Sniper::celebrate() {
    cout << this->getName() << " exclaims \"HEADSHOT!\"" << endl;
}

bool Sniper::getHit(Zombie *z) {
    //get damage
    int zombie_damage = z->getDamage();
    //remove from soldier
    this->takeDamage(zombie_damage);
    cout << this->getName() << " swears in 13 different languages as he takes " << zombie_damage << " damage." << endl;
    if (this->getHP() <= 0)
        return true;
    return false;
}

void Sniper::die() {
    cout << this->getName() << " lead a good life. He will be missed." << endl;
}