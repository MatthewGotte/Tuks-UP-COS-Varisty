#ifndef LASER_H
#define LASER_H

#include "weapon.h"
#include <string>

using namespace std;

class laser : public weapon {
private:
    int strength;
public:
    laser (int s);
    ~laser();

    void setStrength(int s);
    int getStrength();

    string fire();
};

#endif