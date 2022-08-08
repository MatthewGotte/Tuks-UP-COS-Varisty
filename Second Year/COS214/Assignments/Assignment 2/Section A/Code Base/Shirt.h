#ifndef SHIRT_H
#define SHIRT_H
#include "Merchandise.h"

using namespace std;

class Shirt : public Merchandise {
private:
    string size;
public:
    Shirt(string club, double price, string size);
    virtual string getDescription();
    virtual ~Shirt();
};

#endif