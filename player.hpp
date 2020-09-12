//
//  Name: Kathleen Blanck
//  Date: Jan 26, 2017
//  This file includes the class definition for the Player class, inherited from the Hand class
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include "hand.hpp"
#include "deck.hpp"


class Player : public Hand {
private:
    string name;
    bool playing;
    bool done;
public:
    Player();
    Player(string s);
    bool isBusted(void);
    void setName(string s);
    bool isDone(void);
    void action(string s, Deck &d); //handles the idea of hitting or staying for the player
    void resetToo(); //implemented at the end of the round to reset and clear variables
};

#endif /* player_hpp */
