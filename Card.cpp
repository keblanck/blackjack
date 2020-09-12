//
//  Name: Kathleen Blanck
//  Date: Jan 26, 2017
//  This file includes the implementation of all Card class functions
//

#include "Card.hpp"




/*
 * Card(): the generic constructor for an instance of the Card class, randomly assigning a rank and suit
 * parameters: none
 * returns: none
 */
Card::Card() {
    srand((unsigned) time(0));
    r = Rank((rand() % 13) + 1);
    s = Suit(rand() % 4);
}


/*
 * getValue(): an accessor function that returns the value of each card
 * parameters: none
 * returns: an int with the value of the card
 */
int Card::getValue() const {
    if (r == 1)
        return 11;
    if (r == 2)
        return 2;
    if (r == 3)
        return 3;
    if (r == 4)
        return 4;
    if (r == 5)
        return 5;
    if (r == 6)
        return 6;
    if (r == 7)
        return 7;
    if (r == 8)
        return 8;
    if (r == 9)
        return 9;
    if (r == 10)
        return 10;
    if (r == 11)
        return 10;
    if (r == 12)
        return 10;
    if (r == 13)
        return 10;
    else
        return 0;
}


/*
 * setRank(): sets the rank of the card as the parameter dictates
 * parameters: Rank rr, a given rank for the card
 * returns: none
 */
void Card::setRank(Rank rr) {
    r = rr;
}


/*
 * setSuit(): sets the suit of the card as the parameter dictates
 * parameters: Suit ss, a given suit for the card
 * returns: none
 */
void Card::setSuit(Suit ss) {
    s = ss;
}


/*
 * showCard(): evaluates the variables of the card and creates a string to represent the rank and suit
 * parameters: none
 * returns: a string that represents the card's rank and suit
 */
string Card::showCard() {
    string ss;
    
    if (r == 1)
        ss += "[A";
    if (r == 2)
        ss += "[2";
    if (r == 3)
        ss += "[3";
    if (r == 4)
        ss += "[4";
    if (r == 5)
        ss += "[5";
    if (r == 6)
        ss += "[6";
    if (r == 7)
        ss += "[7";
    if (r == 8)
        ss += "[8";
    if (r == 9)
        ss += "[9";
    if (r == 10)
        ss += "[10";
    if (r == 11)
        ss += "[J";
    if (r == 12)
        ss += "[Q";
    if (r == 13)
        ss += "[K";

    if (s == 0)
        ss += "C] ";
    if (s == 1)
        ss += "D] ";
    if (s == 2)
        ss += "S] ";
    if (s == 3)
        ss += "H] ";
    
    return ss;
}

