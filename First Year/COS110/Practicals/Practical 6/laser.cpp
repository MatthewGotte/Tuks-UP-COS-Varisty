#include "laser.h"
#include "fireControl.h"

#include <iostream>

using namespace std;

laser::laser(int s) : weapon() {
    this->strength = s;
}

laser::~laser() {
    cout << this->getName() << " Uninstalled!" << endl;
}

void laser::setStrength(int s) {
    this->strength = s;
}

int laser::getStrength() {
    return this->strength;
}

string laser::fire() {
    if (this->getAmmo() == 0) {
        throw ammoOut();
    }
    int temp = this->getAmmo();
    this->setAmmo(temp - 1);
    string output = this->getName() + " fired at strength: " + to_string(this->strength);
    this->strength++;
    return output;
}