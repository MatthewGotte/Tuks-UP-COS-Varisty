#ifndef ELECTRICLOCOMOTIVE_H
#define ELECTRICLOCOMOTIVE_H

#include <string>
#include "vehicle.h"

class electricLocomotive : public vehicle {
private:
    double perUnitCost;
public:
    electricLocomotive();
    ~electricLocomotive();

    double getUnitCost();
    void setUnitCost(double s);
    void determineRouteStatistics();
};

#endif