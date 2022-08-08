#ifndef NOCARDSTATE_H
#define NOCARDSTATE_H

#include "CardState.h"
#include "YellowCardState.h"

class NoCardState : public CardState {

public:
    NoCardState();
    void handle();
    CardState* changeCardState();
};


#endif
