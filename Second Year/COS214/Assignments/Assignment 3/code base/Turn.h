#ifndef TURN_H
#define TURN_H

#include "Section.h"
#include <iostream>

class Turn : public Section {
private:
    int rotation;
public:
    Turn(int rotation);
    ~Turn();

    void print();
};

#endif