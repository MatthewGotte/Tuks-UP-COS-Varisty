#ifndef SOCCERPLAYER_H
#define SOCCERPLAYER_H

#include <iostream>
#include "CardState.h"
#include "PlayStyle.h"
#include "NoCardState.h"

using namespace std;

class SoccerPlayer {
private:
    string name;
    CardState* card;
    PlayStyle* style;
public:
    SoccerPlayer(string name, PlayStyle* style);
    ~SoccerPlayer();
    void commitFoul();
    void play();
    void setPlayStyle(PlayStyle* style);
};


#endif
