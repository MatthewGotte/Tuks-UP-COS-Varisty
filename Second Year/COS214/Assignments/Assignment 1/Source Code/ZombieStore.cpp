#include "ZombieStore.h"

ZombieStore::~ZombieStore() {
    delete this->mem;
}

ZombieMemento *ZombieStore::getMemento() {
    return this->mem;
}

void ZombieStore::storeMemento(ZombieMemento* mem) {
    this->mem = mem;
}