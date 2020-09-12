//
//  Name: Kathleen Blanck
//  Date: Jan 26, 2017
//  This file includes the implementation of all BlackJackPlayer class functions
//

#include "blackjack.hpp"




/*
 * BlackJackPlayer(): the constructor for a generic blackjack player instance
 * parameters: none
 * returns: none
 */
BlackJackPlayer::BlackJackPlayer() {
    inPlay = true;
    done = false;
}


/*
 * Player(): the constructor for a named player instance with a finite amount of money
 * parameters: string s, the name of the player; int c, the amount of cash the player is using
 * returns: none
 */
BlackJackPlayer::BlackJackPlayer(string s, int c) {
    name = s;
    cash = c;
    inPlay = true;
    done = false;
}


/*
 * getName(): accessor for the player's name
 * parameters: none
 * returns: the player's name
 */
string BlackJackPlayer::getName() const {
    return name;
}


/*
 * setBet(): assigns an integer value to the bet variable to show what a player is betting
 * parameters: int b, the value the player is betting
 * returns: none
 */
void BlackJackPlayer::setBet(int b) {
    bet = b;
}


/*
 * setName(): gives the player a name
 * parameters: string s, the player's input name
 * returns: none
 */
void BlackJackPlayer::setName(string s) {
    name = s;
}


/*
 * getBet(): accessor for the player's bet
 * parameters: none
 * returns: an int with the player's bet's value
 */
int BlackJackPlayer::getBet() const {
    return bet;
}


/*
 * loseMoney(): adjusts the player's cash according to the bet they lost
 * parameters: none
 * returns: none
 */
void BlackJackPlayer::loseMoney() {
    cash -= bet;
}


/*
 * winMoney(): adjusts the player's cash according to the bet they won
 * parameters: none
 * returns: none
 */
void BlackJackPlayer::winMoney() {
    cash += bet;
}


/*
 * setMoney(): assigns an input integer to the player's cash amount
 * parameters: int m, the cash the player wants to play with
 * returns: none
 */
void BlackJackPlayer::setMoney(int m) {
    cash = m;
}


/*
 * getMoney(): accessor for the player's money
 * parameters: none
 * returns: an int with the amount of money the player has access to
 */
int BlackJackPlayer::getMoney(void) const {
    return cash;
}

/*
 * reset(): used at the end of the round to set all of the variables back to their initial state for smooth game play during future rounds
 * parameters: none
 * returns: none
 */
void BlackJackPlayer::reset() {
    hand.clear();
    size = 0;
    bet = 0;
    inPlay = true;
    done = false;
    resetToo();
}





