//
//  Name: Kathleen Blanck
//  Date: Jan 26, 2017
//  This file includes the implementation of all Player class functions
//

#include "player.hpp"


/*
 * Player(): the constructor for a generic player instance
 * parameters: none
 * returns: none
 */
Player::Player() {
    playing = true;
    done = false;
}


/*
 * Player(): the constructor for a named player instance
 * parameters: string s, storing the name of the player
 * returns: none
 */
Player::Player(string s) {
    name = s;
    playing = true;
    done = false;
}


/*
 * isBusted(): the function that determines whether or not a player's hand is over 21
 * parameters: none
 * returns: a boolean, indicating whether a player is busted or not
 */
bool Player::isBusted() {
    int value = getTotal();
    if (value > 21) {
        playing = false;
        return true;
    }
    return false;
}


/*
 * setName(): a function that assigns a name to a player
 * parameters: string s, storing the name input by the user
 * returns: none
 */
void Player::setName(string s) {
    name = s;
}


/*
 * isDone(): looks at if the player has busted or if they have stayed on their turn and determines if they are done with their turn
 * parameters: none
 * returns: a boolean, indicating whether or not their turn is over
 */
bool Player::isDone() {
    if (isBusted() || done)
        return true;
    return false;
}


/*
 * action(): either gives the player another card or ends their turn when they stay
 * parameters: string s, a variable storing their previously verified input of "h" or "s"; Deck &d, the deck which is passed by reference to allow sequential drawing from the deck;
 * returns: none
 */
void Player::action(string s, Deck &d) {
    if (s == "s")
        done = true;
    else {
        add(d.deal());
        playing = !isBusted();
    }
}


/*
 * resetToo(): makes sure that all variables are reset at the end of each round so that play can resume as usual
 * parameters: none
 * returns: none
 */
void Player::resetToo() {
    playing = true;
    done = false;
}







