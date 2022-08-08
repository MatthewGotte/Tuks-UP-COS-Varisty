#include "FlagObserver.h"

FlagObserver::FlagObserver(Track * t) {
    this->raceTrack = t;
    this->waving = false;
}

FlagObserver::~FlagObserver() {

}

void FlagObserver::update() {
    this->waving = raceTrack->hasCrash();
    raceTrack->setCrash(waving);
}

void FlagObserver::print() {
    if (this->waving) {
        cout << "Waving: There is a crash!" << endl;
    }
    else {
        cout << "Not Waving: There is no crash." << endl;
    }
}