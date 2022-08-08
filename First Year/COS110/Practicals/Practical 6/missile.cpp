#include "missile.h"
#include "fireControl.h"

#include <iostream>

using namespace std;

missile::missile() : weapon() {

}

missile::~missile() {
    cout << this->getName() << " Uninstalled!" << endl;
}

string missile::fire() {
    if (this->getAmmo() == 0) {
        throw ammoOut();
    }
    int temp = this->getAmmo();
    this->setAmmo(temp - 1);
    string output = this->getName() + " fired!";
    return output;
}