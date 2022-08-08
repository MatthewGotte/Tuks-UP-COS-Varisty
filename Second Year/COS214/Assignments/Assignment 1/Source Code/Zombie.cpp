#include "Zombie.h"
#include <iostream>
#include <cstring>

Zombie::Zombie(const char* att, int dam)
	: attackType(att), damage(dam)
{
  hp = 5;
}

Zombie::~Zombie()
{

}

int Zombie::takeDamage(int amount)
{
	cout << "Zombie took " << amount << " damage." << endl;
	hp -= amount;
	return hp;
}

int Zombie::getDamage()
{
	cout << "Zombie used " << attackType << "." << endl;
	return damage;
}

Zombie *Zombie::clone() {
    int len = attackType.length() + 1;
    char arr[len];
    strcpy(arr, attackType.c_str());
    return new Zombie(arr, this->damage);
}

bool Zombie::isAlive() {
    return this->hp > 0;
}

ZombieMemento *Zombie::createMemento() {
    return new ZombieMemento(attackType, hp, damage);
}

void Zombie::reinstateMemento(ZombieMemento * mem) {
    this->attackType = mem->state->getStringFirst();
    this->hp = mem->state->getIntFirst();
    this->damage = mem->state->getIntSecond();
}