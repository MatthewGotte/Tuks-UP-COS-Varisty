#include "Barrier.h"

Barrier::Barrier() {

}

Barrier::~Barrier() {

}

void Barrier::print() {
    Decorator::print();
    cout << "\tBarriers";
}