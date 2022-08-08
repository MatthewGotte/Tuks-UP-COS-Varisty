#include <iostream>
#include "electricLocomotive.h"
#include "dieselLocomotive.h"
#include "vehicle.h"
#include "locomotive.h"

using namespace std;

int main() {

    electricLocomotive * x = new electricLocomotive();
    x->setName("Test 1");
    x->setMap("map1.txt");
    x->setUnitCost(40.1);
    x->determineRouteStatistics();

    cout << "!!!!!!!!!!!!!!!!!!!" << endl;

    dieselLocomotive * y = new dieselLocomotive();
    y->setMap("map1.txt");
    y->setName("Test 2");
    y->setPassengerLimit(60);
    y->determineRouteStatistics();

	return 0;
}