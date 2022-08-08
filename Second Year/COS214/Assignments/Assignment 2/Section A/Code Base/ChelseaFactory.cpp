#include "ChelseaFactory.h"

Shirt *ChelseaFactory::CreateShirt(string size)  {
    cout << "Creating";
    return new ChelseaShirt(size);
}

SoccerBall *ChelseaFactory::CreateSoccerBall(bool inflated)  {
    cout << "Creating";
    return new ChelseaSoccerBall(inflated);
}

ChelseaFactory::ChelseaFactory() : MerchandiseFactory() {}

ChelseaFactory::~ChelseaFactory() {}