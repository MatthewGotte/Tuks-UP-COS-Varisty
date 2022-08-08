#include "SoldierStore.h"

SoldierStore::~SoldierStore() {
    delete this->mem;
}

SoldierMemento *SoldierStore::getMemento() {
    return this->mem;
}

void SoldierStore::storeMemento(SoldierMemento * mem) {
    this->mem = mem;
}