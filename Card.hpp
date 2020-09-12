//
//  Name: Kathleen Blanck
//  Date: Jan 26, 2017
//  This file includes the class definition for the Card class
//

using namespace std;

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <iostream>

enum Rank{Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
const Rank START_RANK = Ace;
const Rank END_RANK = King;

enum Suit{Clubs, Diamonds, Spades, Hearts};
const Suit START_SUIT = Clubs;
const Suit END_SUIT = Hearts;


class Card {
private:
    Rank r;
    Suit s;
public:
    Card(); //functioning
    //Card(Rank r, Suit s);
    int getValue(void) const; //functioning
    void setRank(Rank r); //functioning
    void setSuit(Suit s); //functioning
    string showCard(void); //functioning
};

#endif /* Card_hpp */
