#ifndef SECTION_H
#define SECTION_H

#include <vector>

#include "Observer.h"

using namespace std;

class Section {
private:
    vector< Observer* > observerList;
public:
    Section();
    virtual ~Section();

    virtual void print() = 0;
    virtual void add(Section*);
    virtual void remove();

    void attach(Observer *);
    void detach(Observer *);
    void notify();
};

#endif