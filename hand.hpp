//
//  Name: Kathleen Blanck
//  Date: Jan 26, 2017
//  This file includes the class definition for the Hand class
//

#ifndef hand_hpp
#define hand_hpp

#include <stdio.h>
#include <vector>
#include "Card.hpp"

class Hand {
protected:
    vector<Card> hand;
    int size;
public:
    Hand();
    void add(Card c); //functioning
    int getTotal(void) const; //functioning
    int getSize(void) const; // functioning
    vector<Card> getHand() const; //functioning
};

#endif /* hand_hpp */
