#ifndef STRAIGHT_H
#define STRAIGHT_H

#include "Section.h"
#include <iostream>

class Straight : public Section {
public:
    Straight();
    ~Straight();

    void print();
};

#endif