#ifndef ARSENALFACTORY_H
#define ARSENALFACTORY_H

#include "MerchandiseFactory.h"

#include "ArsenalShirt.h"
#include "ArsenalSoccerBall.h"


class ArsenalFactory : public MerchandiseFactory {
private:

public:
    ArsenalFactory();
    ~ArsenalFactory();
    Shirt * CreateShirt(string size);
    SoccerBall * CreateSoccerBall(bool inflated);
};

#endif