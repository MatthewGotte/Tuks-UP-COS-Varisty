#ifndef CHICANE_H
#define CHICANE_H

#include "Section.h"
#include <iostream>

class Chicane : public Section {
public:
    Chicane();
    ~Chicane();

    void print();
};

#endif