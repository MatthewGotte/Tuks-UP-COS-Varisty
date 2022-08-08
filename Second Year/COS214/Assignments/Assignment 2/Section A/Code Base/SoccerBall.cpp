#include "SoccerBall.h"

SoccerBall::SoccerBall(string club, double price, bool inflated) : Merchandise(club, price, "Soccer Ball") {
    this->inflated = inflated;
}

string SoccerBall::getDescription() {
//    string out = "Club: " this->club + " Price: " + to_string(this->price) + " Type: " + this->type + " ID: " + to_string(this->id);
    string out = Merchandise::getDescription();
    string b = "True";
    if (!inflated) {
        b = "False";
    }
    out += ", Inflation: " + b;
    return out;
}

SoccerBall::~SoccerBall() {}