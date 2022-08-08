#ifndef PITSTOP_H
#define PITSTOP_H

#include "Decorator.h"
#include <iostream>

class PitStop : public Decorator {
public:
    PitStop();
    ~PitStop();

    void print();
};

#endif