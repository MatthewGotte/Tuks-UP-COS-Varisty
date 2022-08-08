#ifndef DECORATOR_H
#define DECORATOR_H

#include "Section.h"

class Decorator : public Section {
public:
    Section * section;
    Decorator();
    ~Decorator();

    virtual void print();
    void add(Section *);
    void remove();
};

#endif