#include "locomotive.h"

#include <string>
#include <iostream>

locomotive::locomotive() : vehicle() {

}

locomotive::~locomotive() {


    cout << "locomotive removed" << endl;
}

int locomotive::getSupplyRange() {
    return supplyRange;
}

void locomotive::setSupplyRange(int s) {
    this->supplyRange = s;
}

void locomotive::determineRouteStatistics() {
    int orX, orY, exX, exY, distance, noStations;
    bool status;

    cout << "Name: " << this->getName() << endl;
    cout << "Supply Range: " << supplyRange << " units" << endl;

    for (int i = 0; i < this->getSize(); i++) {
        for (int j = 0; j < this->getSize(); j++) {
            if (this->getMapAt(i, j) == 'O') {
                orX = i;
                orY = j;
            }
        }
    }
    cout << "Origin Coordinates: " << orX << "," << orY << endl;

    for (int i = 0; i < this->getSize(); i++) {
        for (int j = 0; j < this->getSize(); j++) {
            if (this->getMapAt(i, j) == 'O') {
                exX = i;
                exY = j;
            }
        }
    }
    cout << "Exit Coordinates: " << exX << "," << exY << endl;

    distance = 0;
    for (int i = 0; i < this->getSize(); i++) {
        for (int j = 0; j < this->getSize(); j++) {
            if (this->getMapAt(i, j) == '#') {
                distance++;
            }
        }
    }
    cout << "Distance: " << distance << endl;

    noStations = 0;
    for (int i = 0; i < this->getSize(); i++) {
        for (int j = 0; j < this->getSize(); j++) {
            if (this->getMapAt(i, j) == '*') {
                noStations++;
            }
        }
    }
    cout << "Number of Stations: " << noStations << endl;
    if ((supplyRange > distance) || (noStations != 0)) {
        cout << "Status: Viable" << endl;
    }
    else {
        cout << "Status: Not Viable" << endl;
    }

}