#ifndef TRACK_H
#define TRACK_H

#include <vector>
#include "Section.h"
#include <iostream>

class Track : public Section {
private:
    bool crash;
public:
    Track();
    ~Track();

    vector< Section* > sections;
    void print();
    void add(Section*);
    void remove();

    bool hasCrash();
    void setCrash(bool);
};

#endif