//
//  Name: Kathleen Blanck
//  Date: Jan 26, 2017
//  This file includes the class definition for the BlackJAckPlayer class, inherited from the Player class
//

#ifndef blackjack_hpp
#define blackjack_hpp

#include <stdio.h>
#include "player.hpp"

class BlackJackPlayer : public Player {
private:
    string name;
    bool inPlay;
    int cash;
    bool done;
    int bet;
public:
    BlackJackPlayer();
    BlackJackPlayer(string s, int c);
    string getName(void) const;
    void setBet(int b);
    void setName(string s);
    int getBet() const;
    void loseMoney();
    void winMoney();
    void setMoney(int m);
    int getMoney(void) const;
    void reset();
};

#endif /* blackjack_hpp */
