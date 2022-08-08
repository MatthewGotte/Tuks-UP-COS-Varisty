#ifndef ZOMBIESTATE_H
#define ZOMBIESTATE_H

#include <iostream>

using namespace std;

class ZombieState {
private:
    int intVals[2];
    string stringVals[1];
public:
    ZombieState(string, int, int);

    int getIntFirst();
    int getIntSecond();
    string getStringFirst();

};

#endif