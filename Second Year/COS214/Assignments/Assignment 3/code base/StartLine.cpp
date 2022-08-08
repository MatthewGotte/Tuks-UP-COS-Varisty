#include "StartLine.h"

StartLine::StartLine() {

}

StartLine::~StartLine() {

}

void StartLine::print() {
    Decorator::print();
    cout << "\tStarting Line";
}