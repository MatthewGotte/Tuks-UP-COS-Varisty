#include "ZombieState.h"

ZombieState::ZombieState(string s1, int i1, int i2) {
    this->intVals[0] = i1;
    this->intVals[1] = i2;
    this->stringVals[0] = s1;
}

int ZombieState::getIntFirst() {
    return this->intVals[0];
}

int ZombieState::getIntSecond() {
    return this->intVals[1];
}

string ZombieState::getStringFirst() {
    return this->stringVals[0];
}