#ifndef SOCCERBALL_H
#define SOCCERBALL_H
#include "Merchandise.h"

using namespace std;

class SoccerBall : public Merchandise {
private:
    bool inflated;
public:
    SoccerBall(string club, double price, bool inflated);
    virtual string getDescription();
    virtual ~SoccerBall();
};

#endif