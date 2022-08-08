#include "ZombieMemento.h"

ZombieMemento::ZombieMemento(string s1, int i1, int i2) {
    this->state = new ZombieState(s1, i1, i2);
}

ZombieMemento::~ZombieMemento() {
    delete this->state;
    this->state = nullptr;
}