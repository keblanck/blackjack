//
//  Name: Kathleen Blanck
//  Date: Jan 26, 2017
//  This file includes the implementation of all Dealer class functions
//

#include "dealer.hpp"


/*
 * Dealer(): the generic constructor for an instance of the Dealer class
 * parameters: none
 * returns: none
 */
Dealer::Dealer() {
    winnings = 0;
}


/*
 * toHit(): a function that determines whether or not the dealer should take another card, according to its strategy
 * parameters: none
 * returns: a string "s" or "h" to indicate if it will stay or hit
 */
string Dealer::toHit() {
    if (getTotal() < 17 ){
        cout << "\nDealer chooses to hit." << endl;
        return "h";
    }
    cout << "\nDealer chooses to stay." << endl;
    return "s";
}


/*
 * updateWinnings(): changes the dealer's winnings according to the outcome of the player's hand and bet
 * parameters: int i, with the player's bet's value
 * returns: none
 */
void Dealer::updateWinnings(int i) {
    winnings += i;
}


/*
 * getWinnings(): an accessor function for the dealer's winnings (the amount that the house has taken total over the rounds)
 * parameters: none
 * returns: an int with the value of the dealer's winnings
 */
int Dealer::getWinnings() const {
    return winnings;
}

/*
 * null(): a function used when the dealer busts to allow other players to have a higher hand value when their hand is not busted. Basically used to insure fair comparison of cards
 * parameters: none
 * returns: none
 */
void Dealer::null() {
    hand.clear();
    size = 0;
}
