#include "Soldier.h"
#include "Zombie.h"
#include <iostream>

Soldier::Soldier(string n, int hp, string primary, string secondary, int damage) {
    this->name = n;
    this->HP = hp;
    this->primary_weapon = primary;
    this->secondary_weapon = secondary;
    this->damage = damage;
}

Soldier::~Soldier() {

}

void Soldier::attack(Zombie * z) {
    bool zombieDead = false, soldierDead = false;
    while (!soldierDead && !zombieDead) {
        zombieDead = this->hitZombie(z);
        if (zombieDead) {
            this->celebrate();
            return;
        }
        else {
            soldierDead = getHit(z);
            if (soldierDead) {
                this->die();
                return;
            }
        }
    }
}

SoldierMemento *Soldier::createMemento() {
    return new SoldierMemento(getName(), getPrimaryWeapon(), getSecondaryWeapon(), getHP(), getDamage());
}

void Soldier::reinstateMemento(SoldierMemento * mem) {
    this->name = mem->state->getStringFirst();
    this->primary_weapon = mem->state->getStringSecond();
    this->secondary_weapon = mem->state->getStringThird();
    this->HP = mem->state->getIntFirst();
    this->damage = mem->state->getIntSecond();
}

string Soldier::getName(){
    return this->name;
}

void Soldier::setName(string s) {
    this->name = s;
}

int Soldier::getHP() {
    return this->HP;
}

int Soldier::setHP(int i) {
    return this->HP;
}

void Soldier::takeDamage(int damage) {
    this->HP -= damage;
}

string Soldier::getPrimaryWeapon() {
    return this->primary_weapon;
}

void Soldier::setPrimaryWeapon(string s) {
    this->primary_weapon = s;
}

string Soldier::getSecondaryWeapon() {
    return this->secondary_weapon;
}

void Soldier::setSecondaryWeapon(string s) {
    this->secondary_weapon = s;
}

int Soldier::getDamage() {
    return this->damage;
}

