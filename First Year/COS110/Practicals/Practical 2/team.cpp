#include "team.h"
#include "creature.h"

using namespace std;

team::team(string tName,string tID,int sizeTeam,int crank)
{
	trainerName = tName;
	trainerID = tID;
	teamLimit = sizeTeam;
	rank = crank;
	
	list = new creature*[teamLimit];
	
	for (int i = teamSize; i < teamLimit; i++)
	{
		list[i] = nullptr;
	}
}

team::team(string tName,string tID,int crank,creature** creatures, int sizeTeam, int currSize)
{
	trainerName = tName;
	trainerID = tID;
	rank = crank;
	teamLimit = sizeTeam;
	teamSize = currSize;
	
	list = new creature*[teamLimit];
	
	for (int i = 0; i < teamSize; i++)
		list[i] = new creature(creatures[i]);
	
	for (int i = teamSize; i < teamLimit; i++)
		list[i] = nullptr;
}

team::~team()
{
	for (int i = 0; i < teamLimit; i++)
	{
		if (list[i] != nullptr)
		{
			delete list[i];
			list[i] = nullptr;
		}
	}
	delete [] list;
	list = nullptr;
}

int team::addCreature(creature* c)
{
	if (teamSize < teamLimit)
	{
		for (int i = 0; i < teamLimit; i++)
		{
			if (list[i] == nullptr)
			{
				list[i] = new creature(c);
				teamSize++;
				return i;
			}
		}
	}
	return -1;
}

int team::removeCreature(string name)
{
	for (int i = 0; i < teamLimit; i++)
	{
		if (list[i] != nullptr)
		{
			if(list[i]->getName() == name)
			{	
				delete list[i];
				teamSize--;
				list[i] = nullptr;			
				return i;
			}
		}
	}
	return -1;
}

string team::getName()
{
	return  trainerName;
}

string team::getID()
{
	return trainerID;
}

int team::getCurrSize()
{
	return teamSize;
}

int team::getLimit()
{
	return teamLimit;
}

void team::printTeam(string s)
{
	cout << "Trainer Name: " << trainerName << endl;
	cout << "ID: " << trainerID << endl;
	cout << "Number of Creatures: " << teamSize << endl;
	cout	<< "Creature Limit: " << teamLimit << endl;
	
	string rankOut = "";
	for (int i = 0; i < rank; i++)
		rankOut += "*";
	cout << "Rank: " << rankOut << endl;
	
	//Create New Array:
	int min, minVal, q, start;
	bool flag;
	
	creature * temp;
	q = 0;
	
	creature * tAry[teamSize];
	for(int i = 0; i < teamLimit; i++)
	{
		if(list[i] != nullptr)
		{
			tAry[q] = new creature(list[i]);
			q++;
		}
	}
	
	if(s == "hp")
	{
		for (start = 0; start < (teamSize); start++)
		{
			min = start;
			minVal = tAry[start]->getHP();
			flag = false;
			for (int index = start + 1; index < teamSize; index++)
			{
				if(tAry[index]->getHP() < minVal)
				{
					minVal = tAry[index]->getHP();
					temp = tAry[index];
					min = index;
					flag = true;
				}
			}
			if (flag)
			{
				tAry[min] = tAry[start];
				tAry[start] = temp;
			}
		}
	}
	else
	{
		for (start = 0; start < (teamSize); start++)
		{
			min = start;
			minVal = tAry[start]->getMana();
			flag = false;
			for (int index = start + 1; index < teamSize; index++)
			{
				if(tAry[index]->getMana() > minVal)
				{
					minVal = tAry[index]->getMana();
					temp = tAry[index];
					min = index;
					flag = true;
				}
				if (flag)
				{
					tAry[min] = tAry[start];
					tAry[start] = temp;
				}
			}		
		}
	}
	///////////////////////////////////////
		
	for (int i = 0; i < teamSize; i++)
		if (tAry[i] != nullptr)
			cout << tAry[i]->getName() << endl;
	
	//delete [] tAry;
}

