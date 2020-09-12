//
//  Name: Kathleen Blanck
//  Date: Jan 26, 2017
//  This file includes the implementation of all Deck class functions
//

#include "deck.hpp"


/*
 * Deck(): the generic constructor for an instance of the class Deck. Generates 52 different cards in a vector.
 * parameters: none
 * returns: none
 */
Deck::Deck() {
    Card a;
    
    for (int i = 1; i < 14; i++) { //14-1=13 ranks
        for (int j = 0; j < 4; j++) { //4 suits
            a.setRank(Rank(i));
            a.setSuit(Suit(j));
            deck.push_back(a);
        }
    }
}


/*
 * confirm(): prints all cards to verify that the deck is correctly constructed and filled
 * parameters: none
 * returns: none
 */
void Deck::confirm() {
    for (int i = 0; i < size; i++) {
        cout << deck.at(i).showCard();
    }
}


/*
 * shuffle(): swaps 2 cards in the deck 52 times to randomize the cards in the deck and make Blackjack possible
 * parameters: none
 * returns: none
 */
void Deck::shuffle() {
    srand((unsigned) time(0));
    for (int i = 0; i < 52; i++) {
        int a = rand() % 52;
        int b = rand() % 52;
        swap(deck[a], deck[b]);
    }
}


/*
 * deal(): removes the first item from the deck, erasing it and returning the card item, also adjusting the size of the deck to prevent issues with the confirm function
 * parameters: none
 * returns: the Card instance at the "top" of the deck
 */
Card Deck::deal() {
    Card c = deck[0];
    deck.erase(deck.begin());
    size--;
    return c;
}



