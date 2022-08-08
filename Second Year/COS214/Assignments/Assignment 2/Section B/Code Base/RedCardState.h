#ifndef REDCARDSTATE_H
#define REDCARDSTATE_H

#include "CardState.h"

class RedCardState : public CardState {

public:
    RedCardState();
    void handle();
    CardState* changeCardState();
};


#endif
