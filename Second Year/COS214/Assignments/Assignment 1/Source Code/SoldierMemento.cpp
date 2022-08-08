#include "SoldierMemento.h"

SoldierMemento::SoldierMemento(string s1, string s2, string s3, int i1, int i2) {
    this->state = new SoldierState(s1, s2, s3, i1, i2);
}

SoldierMemento::~SoldierMemento() {
    delete this->state;
    this->state = nullptr;
}