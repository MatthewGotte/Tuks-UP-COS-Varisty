#include "Shirt.h"

Shirt::Shirt(string club, double price, string size) : Merchandise(club, price, "shirt") {
    this->size = size;
}

string Shirt::getDescription() {
    string out = Merchandise::getDescription();
    out += ", Size: " + this->size;
    return out;
}
Shirt::~Shirt() {}