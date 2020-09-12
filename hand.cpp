//
//  Name: Kathleen Blanck
//  Date: Jan 26, 2017
//  This file includes the implementation of all Hand class functions
//
#include "hand.hpp"


/*
 * Hand(): the generic constructor for an instance of the Hand class, set to size 0
 * parameters: none
 * returns: none
 */
Hand::Hand() {
    size = 0;
}


/*
 * add(): takes in a card to the hand vector and increases the size of the vector by 1
 * parameters: Card cc, the Card instance to be added to the hand vector
 * returns: none
 */
void Hand::add(Card cc) {
    hand.push_back(cc);
    size++;
}


/*
 * getTotal(): adds the values of the cards to create a total amount, adjusting for the Ace in cases of being busted
 * parameters: none
 * returns: an int that is that value of all the cards in the hand
 */
int Hand::getTotal() const {
    int total = 0;
    
    for (int i = 0; i < size; i++) {
        total += hand.at(i).getValue();
    }
    for (int i = 0; i < size; i++) {
        if (hand.at(i).getValue() == 11) {
            if (total > 21)
            total -= 10;
        }
    }
    return total;
}


/*
 * getSize(): an accessor function that returns the size of the hand
 * parameters: none
 * returns: an int with the number of cards in the hand
 */
int Hand::getSize() const {
    return size;
}


/*
 * getHand(): an accessor that returns the hand vector from the instance of the Hand class
 * parameters: none
 * returns: an accessible vector of Cards called hand
 */
vector<Card> Hand::getHand() const {
    return hand;
}
