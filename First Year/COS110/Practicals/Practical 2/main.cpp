#include "creature.h"
#include "team.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Begin of test" << endl;
	cout << "Testing creatures" << endl;
	creature* org = new creature("Shrek", "org", 100,50);
	cout << "Name of org: " << org->getName() << endl;
	cout << "Type of org: " << org->getType() << endl;
	cout << "HP of org: " << org->getHP() << endl;
	cout << "Mana of org: " << org->getMana() << endl;
	cout << "Print out of org: " << endl;
	org->print();
	
	cout << endl << "Now testing copy constructor: " << endl;
	creature* fakeorg = new creature(org);
	delete org;
	org = NULL;
	cout << "Name of fakeorg: " << fakeorg->getName() << endl;
	cout << "Type of fakeorg: " << fakeorg->getType() << endl;
	cout << "HP of fakeorg: " << fakeorg->getHP() << endl;
	cout << "Mana of fakeorg: " << fakeorg->getMana() << endl;
	cout << "Print out of fakeorg: " << endl;
	fakeorg->print();
	
	delete fakeorg;
	
	cout << "End testing creatures" << endl;
	cout << endl << "Begin testing team" << endl;
	
	string names[] = {"A","B","C","D","E"};
	string types[] = {"AA","BB","CC","DD","EE"};
	
	cout << "Testing first constructor for team" << endl;
	team* ATeam = new team("Hannobal", "ID45",5,10);
	
	cout << "ATeam name: " << ATeam->getName() << endl;
	cout << "ATeam id: " << ATeam->getID() << endl;
	cout << "ATeam current size: " << ATeam->getCurrSize() << endl;
	cout << "ATeam limit: " << ATeam->getLimit() << endl;
	cout << "ATeam print team: " << endl;
	ATeam->printTeam("hp");
	
	cout << "Testing the add creature function" << endl;
	
	creature** bteamlist = new creature*[5];
	
	for(int i=0; i < 4; i++)
	{
		creature* c = new creature(names[i], types[i], i*100, 1000*i);
		bteamlist[i] = new creature(c);
		cout << "Position of new member: " << ATeam->addCreature(c) << endl;
	}
	
	cout << "A Team current size:" << ATeam->getCurrSize() << endl;
	
	cout << "Testing remove of member AA at index: " << ATeam->removeCreature("AA") << endl;
	
	cout << "A Team current size:" << ATeam->getCurrSize() << endl;
	
	creature* nc = new creature(names[4],types[4], 250,41.5);
	creature* nnc = new creature(nc);
	cout << "Position of new member: " << ATeam->addCreature(nc) << endl;
	cout << "Position of new member: " << ATeam->addCreature(nnc) << endl;
	cout << "ATeam print team using hp: " << endl;
	ATeam->printTeam("hp");
	cout << "ATeam print team using m: " << endl;
	ATeam->printTeam("m");
	
	cout << "Testing 2nd constructor for team" << endl;
	team* BTeam = new team("Murdock","ID32",8,bteamlist,5,4);
	cout << "BTeam print team using hp: " << endl;
	BTeam->printTeam("hp");
	
	cout << "Now test u are properly copying the creatures in the constructor" << endl;
	for(int i=0; i < 4; i++)
	{
		delete bteamlist[i];
	}
	delete bteamlist;
	cout << "BTeam print team using hp: " << endl;
	BTeam->printTeam("hp");
	cout << "BTeam print team using mm: " << endl;
	BTeam->printTeam("m");
	
	for(int i=0; i < 5; i++)
	{
		cout << "Removing creature " << names[i] << " at index: " << BTeam->removeCreature(names[i]) << endl;
	}
	
	cout << "current size of BTeam: " << BTeam->getCurrSize() << endl;
	
	delete ATeam;
	delete BTeam;
	
	cout << "By reaching this point u did not receive any seg faults or other errors but that does not mean ur output is correct" << endl;
	cout << "Please manually check ur output." << endl;
	return 0;
}
