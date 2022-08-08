#include "SoccerPlayer.h"

SoccerPlayer::SoccerPlayer(string name, PlayStyle* style) {
    this->name = name;
    this->style = style;
    card = new NoCardState();
}

SoccerPlayer::~SoccerPlayer() {

}

void SoccerPlayer::commitFoul() {
    card->handle();
    if (card->getCardColour() != "red")
        card = card->changeCardState();
}

void SoccerPlayer::play() {
    if (card->getCardColour() != "red")
        cout << name << " " << this->style->play() << endl;
    else
        cout << "The player cannot demonstrate their play-style, as they have been sent of." << endl;
}

void SoccerPlayer::setPlayStyle(PlayStyle *style) {
    this->style = style;
}