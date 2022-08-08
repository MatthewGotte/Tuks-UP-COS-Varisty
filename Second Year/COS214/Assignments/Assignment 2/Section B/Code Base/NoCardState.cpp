#include "NoCardState.h"

NoCardState::NoCardState() {
    cardColour = "none";
}

CardState *NoCardState::changeCardState() {
    return new YellowCardState();
}

void NoCardState::handle() {
    cout << "The player hasn’t committed any previous fouls, and will now be given a yellow card." << endl;
}