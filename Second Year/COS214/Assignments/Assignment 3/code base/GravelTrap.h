#ifndef GRAVELTRAP_H
#define GRAVELTRAP_H

#include "Decorator.h"
#include <iostream>

class GravelTrap : public Decorator {
public:
    GravelTrap();
    ~GravelTrap();

    void print();
};

#endif