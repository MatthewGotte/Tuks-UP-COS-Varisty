#include "YellowCardState.h"

YellowCardState::YellowCardState() {
    cardColour = "yellow";
}

CardState *YellowCardState::changeCardState() {
    return new RedCardState();
}

void YellowCardState::handle() {
    cout << "The player has already recieved a yellow card, and will now be given a red card." << endl;
}
