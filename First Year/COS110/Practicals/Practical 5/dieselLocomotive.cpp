#include "dieselLocomotive.h"
#include "vehicle.h"

#include <iostream>
#include <string>

dieselLocomotive::dieselLocomotive() : vehicle() {

}

dieselLocomotive::~dieselLocomotive() {
    cout << "diesel locomotive removed" << endl;
}

int dieselLocomotive::getPassengerLimit() {
    return passengerLimit;
}

void dieselLocomotive::setPassengerLimit(int s) {
    this->passengerLimit = s;
}

void dieselLocomotive::determineRouteStatistics() {
    int distance = 0, passengers = 0;
    int orX = 0, orY = 0, exX = 0, exY = 0;

    for (int i = 0; i < this->getSize(); i++) {
        for (int j = 0; j < this->getSize(); j++) {
	    if (this->getMapAt(i, j) == 'E') {
                exX = i;
                exY = j;
            }
            if (this->getMapAt(i, j) == '#') {
                distance++;
            }
            if (this->getMapAt(i, j) == 'M') {
                distance++;
                passengers += 50;
            }
            if (this->getMapAt(i, j) == 'N') {
                distance++;
                passengers += 25;
            }
            if (this->getMapAt(i, j) == 'P') {
                distance++;
                passengers += 10;
            }
            if (this->getMapAt(i, j) == 'O') {
                orX = i;
                orY = j;
            }
           
        }
    }

    bool viable = false;
    if (passengerLimit > passengers) {
        viable = true;
    }

    cout << "Name: " << this->getName() << endl;
    cout << "Origin Coordinates: " << orX << "," << orY << endl;
    cout << "Exit Coordinates: " << exX << "," << exY << endl;
    cout << "Distance: " << distance << endl;
    cout << "Passengers Carried: " << passengers << endl;
    if (viable) {
        cout << "Status: Viable" << endl;
    }
    else {
        cout << "Status: Not Viable" << endl;
    }
}