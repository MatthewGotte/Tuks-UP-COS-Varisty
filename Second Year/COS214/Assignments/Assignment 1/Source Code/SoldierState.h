#ifndef SOLDIERSTATE_H
#define SOLDIERSTATE_H

#include <iostream>

using namespace std;

class SoldierState {
private:
    int intVals[2];
    string stringVals[3];
public:
    SoldierState(string, string, string, int, int);

    int getIntFirst();
    int getIntSecond();
    string getStringFirst();
    string getStringSecond();
    string getStringThird();
};

#endif