#ifndef YELLOWCARDSTATE_H
#define YELLOWCARDSTATE_H

#include "CardState.h"
#include "RedCardState.h"

class YellowCardState : public CardState {

public:
    YellowCardState();
    void handle();
    CardState* changeCardState();
};


#endif
