#ifndef DIESELLOCOMOTIVE_H
#define DIESELLOCOMOTIVE_H

#include <string>
#include "vehicle.h"

using namespace std;

class dieselLocomotive : public vehicle {
private:
    int passengerLimit;
public:
    dieselLocomotive();
    ~dieselLocomotive();
    int getPassengerLimit();
    void setPassengerLimit(int s);
    void determineRouteStatistics();
};

#endif