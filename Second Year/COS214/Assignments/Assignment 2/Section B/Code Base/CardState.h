#ifndef CARDSTATE_H
#define CARDSTATE_H

#include <iostream>

using namespace std;

class CardState {
protected:
    string cardColour;
public:
    virtual void handle() = 0;
    virtual CardState* changeCardState() = 0;
    string getCardColour();
};


#endif
