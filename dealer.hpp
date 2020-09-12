//
//  Name: Kathleen Blanck
//  Date: Jan 26, 2017
//  This file includes the class definition for the Dealer class, inherited from the BlackJackPlayer class
//

#ifndef dealer_hpp
#define dealer_hpp

#include <stdio.h>
#include "blackjack.hpp"

class Dealer : public BlackJackPlayer {
private:
    int winnings;
public:
    Dealer();
    string toHit(void);
    void updateWinnings(int i);
    int getWinnings() const;
    void null();
};

#endif /* dealer_hpp */
