#include "creature.h"

#include <iostream>
#include <string>

using namespace std;

creature::creature(creature* c)
{
	name = c->getName();
	type = c->getType();
	hp = c->getHP();
	mana = c->getMana();
}

creature::creature(string cname,string ctype,int chp,double cmana)
{
	name = cname;
	type = ctype;
	hp = chp;
	mana = cmana;
}

creature::~creature()
{
	cout << name << " deleted" << endl;
}

string creature::getName()
{
	return name;
}

string creature::getType()
{
	return type;
}

int creature::getHP()
{
	return hp;
}

double creature::getMana()
{
	return mana;
}

void creature::print()
{
	cout << "Name: " << name << endl;
	cout << "Type: " << type << endl;
	cout << "HP: " << hp << endl;
	cout << "Mana: " << mana << endl;
}

