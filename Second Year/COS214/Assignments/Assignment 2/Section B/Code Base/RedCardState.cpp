#include "RedCardState.h"

RedCardState::RedCardState() {
    cardColour = "red";
}

CardState *RedCardState::changeCardState() {
    return nullptr;
}

void RedCardState::handle() {
    cout << "The player has already been sent off with a red card." << endl;
}
