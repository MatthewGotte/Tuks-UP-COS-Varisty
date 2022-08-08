#include "weapon.h"

#include <string>
#include <iostream>

using namespace std;

weapon::weapon() {

}

weapon::weapon(int a, string t, string n) {
    this->ammo = a;
    this->type = t;
    this->name = n;
}

int weapon::getAmmo() {
    return this->ammo;
}

void weapon::setAmmo(int a) {
    this->ammo = a;
}

string weapon::getType() {
    return this->type;
}

void weapon::setType(string s) {
    this->type = s;
}

string weapon::getName() {
    return this->name;
}

void weapon::setName(string s) {
    this->name = s;
}

//Virtual

weapon::~weapon() {

}

/*string weapon::fire() {

}*/

//Template
template <class T>
void weapon::ventWeapon(T heat) {
    int counter = 0;
    if (heat >= 10) {
        while (heat >= 10) {
            counter++;
            heat -= 10;
            cout << "Heat Cycle " << counter << endl;
        }
    }
    else {
        cout << "Insufficient heat to vent" << endl;
    }
}

template void weapon::ventWeapon<double>(double);
template void weapon::ventWeapon<int>(int);

weapon::ammoOut::ammoOut() {}

weapon::ammoOut::~ammoOut() throw() {}

const char * weapon::ammoOut::what() const throw() {
    return "Ammo Depleted!";
}
