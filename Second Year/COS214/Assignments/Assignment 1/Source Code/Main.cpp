#include "Soldier.h"
#include "Zombie.h"
#include "SniperFactory.h"
#include "BerserkerFactory.h"
#include "MedicFactory.h"
#include "EngineerFactory.h"
#include <sstream>
#include <iostream>

using namespace std;

string TEXT_RESET = "\u001B[0m";
string TEXT_RED = "\u001B[31m";
string TEXT_GREEN = "\u001B[32m";

int main()
{
	const int numFactories = 4;
	SoldierFactory** factories = new SoldierFactory*[numFactories];
	factories[0] = new SniperFactory();
	factories[1] = new BerserkerFactory();
	factories[2] = new MedicFactory();
	factories[3] = new EngineerFactory();
	short numSoldiers;
	cout << "How may soldiers in your squad? ";
	cin >> numSoldiers;
	Soldier** soldiers = new Soldier*[numSoldiers];
	short type;
	char name[30];

	for (short i = 0; i < numSoldiers; i++)
	{
		cout << "What is the name of soldier " << i+1 << "? ";
		cin >> name;
		cout << endl;
		cout << "0 - Sniper" << endl;
		cout << "1 - Berserker" << endl;
		cout << "2 - Medic" << endl;
		cout << "3 - Engineer" << endl;
		cout << "What class is soldier " << i+1 << "? ";
		cin >> type;
		soldiers[i] = factories[type]->createSoldier(name);
	}

	const short numZombieTypes = 4;
	Zombie** zombiePrototypes = new Zombie*[numZombieTypes];
	zombiePrototypes[0] = new Zombie("bite",2);
	zombiePrototypes[1] = new Zombie("slash",3);
	zombiePrototypes[2] = new Zombie("spit",4);
	zombiePrototypes[3] = new Zombie("pounce",5);

	Zombie** zombies = new Zombie*[numSoldiers];

	for (short i = 0; i < numSoldiers; i++)
	{
		cout << "0 - Biting zombie" << endl;
		cout << "1 - Slashing zombie" << endl;
		cout << "2 - Spitting zombie" << endl;
		cout << "3 - Pouncing zombie" << endl;
		cout << "What type is zombie #" << i+1 << "? ";
		cin >> type;
		zombies[i] = zombiePrototypes[type]->clone();
	}

    //Save states:
    ////////////////
    SoldierMemento** soldierMemento = new SoldierMemento*[numSoldiers];
    ZombieMemento** zombieMemento = new ZombieMemento*[numSoldiers];
    for (short i = 0; i < numSoldiers; i++) {
        soldierMemento[i] = soldiers[i]->createMemento();
        zombieMemento[i] = zombies[i]->createMemento();
    }
    ////////////////

    cout << "The long and bloody battle commences!" << endl;
    string output = "";
    int soldierCount = 0;
    int zombieCount = 0;
	for (int i = 0; i < numSoldiers; i++)
	{
        cout << endl;
        for (int j = 0; j < numSoldiers; j++) {
            cout << TEXT_GREEN << soldiers[i]->getName() << TEXT_RESET;
            cout << " attacks " << TEXT_RED << "zombie " << j + 1 << endl << TEXT_RESET;
            soldiers[i]->attack(zombies[j]);
            if (soldiers[i]->getHP() > 0) {
                //won the round
                stringstream ss;
                ss << (j + 1);
                string z;
                ss >> z;
                output += TEXT_GREEN + soldiers[i]->getName() + TEXT_RESET + " won against " + TEXT_RED + "Zombie " + z + TEXT_RESET + "\n";
                soldierCount++;
            }
            else zombieCount++;
            cout << endl;
            soldiers[i]->reinstateMemento(soldierMemento[i]);
            zombies[j]->reinstateMemento(zombieMemento[j]);
        }
        output += "\n";
	}

    cout << "Summary of the battle:" << endl << output << endl;
    cout << "Result of battle:" << endl;
    if (soldierCount > (zombieCount / 2)) {
        cout << TEXT_GREEN << "Soldiers won the battle!" << endl;
    }
    else {
        cout << TEXT_GREEN << "Soldiers lost the battle!" << endl;
    }
    cout << TEXT_RESET;
    cout << "Soldiers alive: " << soldierCount << endl;
    cout << "Zombies alive: " << zombieCount << endl;
    cout << endl;

    ////////////////

	for (int i = 0; i < numSoldiers; i++)
	{
		delete soldiers[i];
		delete zombies[i];
	}
	delete [] soldiers;
	delete [] zombies;

	for (int i = 0; i < numFactories; i++)
	{
		delete factories[i];
	}
	delete [] factories;

	for (int i = 0; i < numZombieTypes; i++)
	{
		delete zombiePrototypes[i];
	}
	delete [] zombiePrototypes;
	return 0;
}
