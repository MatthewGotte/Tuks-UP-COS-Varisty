#ifndef STARTLINE_H
#define STARTLINE_H

#include "Decorator.h"
#include <iostream>

class StartLine : public Decorator {
public:
    StartLine();
    ~StartLine();

    void print();
};

#endif