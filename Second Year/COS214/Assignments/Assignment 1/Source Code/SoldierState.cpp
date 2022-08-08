#include "SoldierState.h"

SoldierState::SoldierState(string s1, string s2, string s3, int i1, int i2) {
    this->stringVals[0] = s1;
    this->stringVals[1] = s2;
    this->stringVals[2] = s3;
    this->intVals[0] = i1;
    this->intVals[1] = i2;
}

int SoldierState::getIntFirst() {
    return this->intVals[0];
}

int SoldierState::getIntSecond() {
    return this->intVals[1];
}

string SoldierState::getStringFirst() {
    return this->stringVals[0];
}

string SoldierState::getStringSecond() {
    return this->stringVals[1];
}

string SoldierState::getStringThird() {
    return this->stringVals[2];
}