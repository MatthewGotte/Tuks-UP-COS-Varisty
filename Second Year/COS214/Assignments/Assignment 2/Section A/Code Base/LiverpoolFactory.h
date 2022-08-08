#ifndef LIVERPOOLFACTORY_H
#define LIVERPOOLFACTORY_H

#include "MerchandiseFactory.h"
#include "LiverpoolShirt.h"
#include "LiverpoolSoccerBall.h"

using namespace std;

class LiverpoolFactory : public MerchandiseFactory {
private:

public:
    LiverpoolFactory();
    ~LiverpoolFactory();
    Shirt * CreateShirt(string size);
    SoccerBall * CreateSoccerBall(bool inflated);
};

#endif