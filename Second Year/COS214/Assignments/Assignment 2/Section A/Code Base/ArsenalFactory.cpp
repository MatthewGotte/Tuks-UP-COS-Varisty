#include "ArsenalFactory.h"



Shirt *ArsenalFactory::CreateShirt(string size) {
    cout << "Creating";
    return new ArsenalShirt(size);
}

SoccerBall *ArsenalFactory::CreateSoccerBall(bool inflated)  {
    cout << "Creating";
    return new ArsenalSoccerBall(inflated);
}

ArsenalFactory::ArsenalFactory() : MerchandiseFactory() {}

ArsenalFactory::~ArsenalFactory() {}