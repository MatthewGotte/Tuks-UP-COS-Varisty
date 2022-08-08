#ifndef FLAGOBSERVER_H
#define FLAGOBSERVER_H

#include "Observer.h"
#include <iostream>
#include "Track.h"

using namespace std;

class FlagObserver : public Observer {
private:
    Track * raceTrack;
    bool waving;
public:
    FlagObserver(Track*);
    ~FlagObserver();

    void update();
    void print();
};

#endif