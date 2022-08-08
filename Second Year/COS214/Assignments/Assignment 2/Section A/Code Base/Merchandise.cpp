#include "Merchandise.h"
#include <iomanip>
#include <cmath>

int Merchandise::counter = 0;

Merchandise::Merchandise(string club, double price, string type) {
    this->club = club;
    this->price = price;
    this->type = type;
    this->id = ++counter;
}

string Merchandise::getDescription() {
//    string out = "Club: " + club + ", Price: " + to_string(price) + ", Type: " + type + ", ID: " + to_string(id);
    ostringstream o;
    o.precision(2);
    o << fixed << price;
    string out = "Item #" + to_string(id) + ": " + club + " " + type + ", Price: " + o.str();
    return out;
}

Merchandise::~Merchandise() {}