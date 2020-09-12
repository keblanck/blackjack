//
//  Name: Kathleen Blanck
//  Date: Jan 26, 2017
//  This file includes the class definition for the Deck class, inherited from the Hand class
//

#ifndef deck_hpp
#define deck_hpp

#include <stdio.h>
#include "hand.hpp"


class Deck : public Hand {
private:
    vector<Card> deck;
    int size = 52;
public:
    Deck(); //functioning
    void confirm(void); //functioning
    void shuffle(void); //functioning but maybe not efficient
    Card deal(void); //functioning
};


#endif /* deck_hpp */
