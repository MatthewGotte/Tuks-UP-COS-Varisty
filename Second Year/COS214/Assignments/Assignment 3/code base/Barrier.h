#ifndef BARRIER_H
#define BARRIER_H

#include "Decorator.h"
#include <iostream>

class Barrier : public Decorator {
public:
    Barrier();
    ~Barrier();

    void print();
};

#endif