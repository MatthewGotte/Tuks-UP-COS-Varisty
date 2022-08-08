#include "PitStop.h"

PitStop::PitStop() {

}

PitStop::~PitStop() {

}

void PitStop::print() {
    Decorator::print();
    cout << "\tPit Stop";
}