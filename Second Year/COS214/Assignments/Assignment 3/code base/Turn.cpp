#include "Turn.h"

Turn::Turn(int rotation) : Section() {
    this->rotation = rotation;
}

Turn::~Turn() {

}

void Turn::print() {
    if (rotation == 0) {
        cout << "Right Turn";
    }
    else if (rotation == 180) {
        cout << "Left Turn";
    }
}