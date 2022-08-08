#ifndef CHELSEAFACTORY_H
#define CHELSEAFACTORY_H

#include "MerchandiseFactory.h"
#include "ChelseaShirt.h"
#include "ChelseaSoccerBall.h"

class ChelseaFactory : public MerchandiseFactory {
private:

public:
    ChelseaFactory();
    ~ChelseaFactory();
    Shirt * CreateShirt(string size);
    SoccerBall * CreateSoccerBall(bool inflated);
};

#endif