#ifndef CREATURE_H
#define CREATURE_H

using namespace std;

// uncomment what you need or add more
#include <string>
// #include <cstring>
#include <iostream>
// #include <sstream>
// #include <cstdlib>

class creature
{
	 private:
		 string name;
		 string type;
		 int hp;
		 double mana;

	 public:
		 creature(creature* c);
		 creature(string cname,string ctype,int chp,double cmana);
		 ~creature();
		 string getName();
		 string getType();
		 int getHP();
		 double getMana();
		 void print();
};
 #endif