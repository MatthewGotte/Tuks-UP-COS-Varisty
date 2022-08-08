#include "fireControl.h"
#include "laser.h"
#include "missile.h"

#include <string>
#include <iostream>

using namespace std;

fireControl::fireControl(int numWeapons, string *weaponList) {
    this->weapons = new weapon*[numWeapons];
    for (int i = 0; i < numWeapons; i++) {
        int pos = -1;

        string temp = weaponList[i];
        for (int i = 0; i < temp.length(); i++) {
            temp[i] = tolower(temp[i]);
        }

        pos = temp.find("missile");
        if (pos != -1) {
            this->weapons[i] = new missile();
            this->weapons[i]->setName(weaponList[i]);
        }
        else {
            this->weapons[i] = new laser(5);
            this->weapons[i]->setName(weaponList[i]);
        }

    }
    this->numWeapons = numWeapons;
}

fireControl::~fireControl() {
    for (int i = 0; i < numWeapons; i++) {
        delete this->weapons[i];
    }
    delete [] weapons;
}

weapon * fireControl::accessWeapon(int i) {
    if (!((0 <= i) && (i < numWeapons))) {
        throw weaponFailure();
    }
    return this->weapons[i];
}

fireControl::weaponFailure::weaponFailure() {}

fireControl::weaponFailure::~weaponFailure() throw() {}

const char * fireControl::weaponFailure::what() const throw() {
    return "Weapon System Failure!";
}