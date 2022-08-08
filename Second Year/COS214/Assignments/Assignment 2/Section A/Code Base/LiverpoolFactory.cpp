#include "LiverpoolFactory.h"

Shirt *LiverpoolFactory::CreateShirt(string size)  {
    cout << "Creating";
    return new LiverpoolShirt(size);
}

SoccerBall *LiverpoolFactory::CreateSoccerBall(bool inflated) {
    cout << "Creating";
    return new LiverpoolSoccerBall(inflated);
}

LiverpoolFactory::LiverpoolFactory() : MerchandiseFactory() {}

LiverpoolFactory::~LiverpoolFactory() {}