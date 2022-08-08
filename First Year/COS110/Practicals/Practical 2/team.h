#ifndef TEAM_H
#define TEAM_H

#include "creature.h"

using namespace std;

// uncomment what you need or add more
#include <string>
// #include <cstring>
#include <iostream>
// #include <sstream>
// #include <cstdlib>

class team
{
	 private:
		 creature** list;
		 string trainerID;
		 string trainerName;
		 int rank;
		 int teamLimit;
		 int teamSize;
	 public:
		 team(string tName,string tID,int sizeTeam,int crank);
		 team(string tName,string tID,int crank,creature** creatures,int sizeTeam, int currSize);
		 ~team();
		 int addCreature(creature* c);
		 int removeCreature(string name);
		 string getName();
		 string getID();
		 int getCurrSize();
		 int getLimit();
		 void printTeam(string s);
};
 #endif