#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "ZombieMemento.h"

#include <string>

using namespace std;

class Zombie
{
private:
	int hp;
	string attackType;
	int damage;

public:
	Zombie(const char*,int);
	~Zombie();

    ZombieMemento* createMemento();
    void reinstateMemento(ZombieMemento*);
	
	// reduces the zombie's hp and returns the new value of hp
	int takeDamage(int);
	
	// returns the zombie's damage
	int getDamage();

    Zombie* clone();

    bool isAlive();

};

#endif