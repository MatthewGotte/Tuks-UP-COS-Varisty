#include "electricLocomotive.h"
#include "vehicle.h"

#include <string>
#include <iostream>
#include <math.h>

electricLocomotive::electricLocomotive() : vehicle() {

}

electricLocomotive::~electricLocomotive() {
    cout << "electric locomotive removed" << endl;
}

double electricLocomotive::getUnitCost() {
    return perUnitCost;
}

void electricLocomotive::setUnitCost(double s) {
    this->perUnitCost = s;
}

void electricLocomotive::determineRouteStatistics() {
	
    int count = 0, orX = 0, orY = 0, exX = 0, exY = 0;


    for (int i = 0; i < this->getSize(); i++) {
        for (int j = 0; j < this->getSize(); j++) {

            if (this->getMapAt(i, j) == '#') {
                count++;
            }
	    
	    if (this->getMapAt(i, j) == 'E') {
                exX = i;
                exY = j;
            }

            if (this->getMapAt(i, j) == 'O') {
                orX = i;
                orY = j;
            }
        }
    }

    cout << "Name: " << this->getName() << endl;

    cout << "Origin Coordinates: " << orX << "," << orY << endl;
    cout << "Exit Coordinates: " << exX << "," << exY << endl;

    cout << "Distance: " << count << endl;
    cout << "Cost: " << floor(perUnitCost * count) << endl;


}