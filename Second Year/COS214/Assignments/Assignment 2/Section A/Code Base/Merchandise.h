#ifndef MERCHANDISE_H
#define MERCHANDISE_H

#include <iostream>

using namespace std;

class Merchandise {
private:
    string club;
    double price;
    string type; //eg. Ball
    int id; //static?
    static int counter;
public:
    Merchandise(string club, double price, string type);
    virtual string getDescription();
    virtual ~Merchandise();
};

#endif