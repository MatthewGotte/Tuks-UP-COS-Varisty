#ifndef MERCHANDISEFACTORY_H
#define MERCHANDISEFACTORY_H

#include "Shirt.h"
#include "SoccerBall.h"

using namespace std;

class MerchandiseFactory {
private:

public:
    MerchandiseFactory();
    virtual ~MerchandiseFactory();
    virtual Shirt* CreateShirt(string size) = 0;
    virtual SoccerBall* CreateSoccerBall(bool inflated) = 0;
};

#endif