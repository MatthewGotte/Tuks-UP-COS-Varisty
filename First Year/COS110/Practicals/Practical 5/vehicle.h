#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

using namespace std;

class vehicle {
private:
    char ** map;
    string name;
    int size;
public:
    vehicle();

    void setName(string s);
    string getName();
    char ** getMap();
    int getSize();
    void setMap(string s);
    char getMapAt(int x, int y);

    virtual ~vehicle();
    virtual void operator--();
    virtual void determineRouteStatistics();
};

#endif