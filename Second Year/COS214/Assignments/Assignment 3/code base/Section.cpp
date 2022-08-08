#include "Section.h"

Section::Section() {

}

Section::~Section() {

}

void Section::add(Section *) {

}

void Section::remove() {

}

void Section::attach(Observer * o) {
    observerList.push_back(o);
}

void Section::detach(Observer * o) {
    vector< Observer* > temp;
    for (int i = 0; i < observerList.size(); i++) {
        if (observerList.at(i) != o)
            temp.push_back(observerList.at(i));
    }
    observerList = temp;
}

void Section::notify() {
    for (int i = 0; i < observerList.size(); i++) {
        observerList.at(i)->update();
    }
}