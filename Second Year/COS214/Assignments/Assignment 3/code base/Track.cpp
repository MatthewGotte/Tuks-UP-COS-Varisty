#include "Track.h"

Track::Track() {

}

Track::~Track() {

}

void Track::print() {
    for (int i = 0; i < sections.size(); i++) {
        sections.at(i)->print();
        cout << endl;
    }
}

void Track::add(Section * s) {
    sections.push_back(s);
}

void Track::remove() {
    sections.pop_back();
}

bool Track::hasCrash() {
    return crash;
}

void Track::setCrash(bool crash) {
    this->crash = crash;
}