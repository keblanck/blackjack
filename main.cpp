//
//  Name: Kathleen Blanck
//  Date: Jan 26, 2017
//  This file includes the main function and implementation of the Blackjack game
//  I believe I have implemented an interesting shuffle function, but I'm not really sure what interesting is.
//


#include <iostream>
#include "Card.hpp"
#include "hand.hpp"
#include "deck.hpp"
#include "dealer.hpp"


/*
 * verifyInt(): makes sure an int is positive
 * parameters: int a, the integer the user input
 * returns: an positive integer or a recursive call to continue evaluating new integers until it is positive
 */
int verifyInt(int a) {
    if (a > 0) {
        return a;
    }
    cout << "That's not a valid number! Try something positive: ";
    cin >> a;
    return verifyInt(a);
}



/*
 * verifyInt(): makes sure an integer b is positive but smaller than the money the player has
 * parameters: int a, the money the player has in their bank; int b, the money the player wants to bet
 * returns: a positive integer lesser than or equal to the person's available money or a recursive call until the integer is positive and lesser than or equal to the person's available money
 */
int verifyInt(int a, int b) {
    if ((b > 0) && (b <= a)) {
        return b;
    }
    cout << "That's not a valid number! Try something else: ";
    cin >> b;
    return verifyInt(a, b);
}


/*
 * yesOrNo(): verifies that the user input is valid and turns the yes or no input into a boolean
 * parameters: string s, user input for verification
 * returns: a boolean or a recursive call to the function until the user types y or n
 */
bool yesOrNo(string s) {
    if (s == "y")
        return true;
    if (s == "n")
        return false;
    cout << "Sorry that wasn't an option! Try again (y or n): ";
    cin >> s;
    return yesOrNo(s);
}

/*
 * hitOrStay(): verifies that the user input is valid
 * parameters: string s, user input for verification
 * returns: a 1-character string, either h or s, or a recursive call to the function until the user inputs h or s
 */
string hitOrStay(string s) {
    if (s == "h")
        return s;
    if (s == "s")
        return s;
    cout << "Sorry that wasn't an option! Try again (h or s): ";
    cin >> s;
    return hitOrStay(s);
}

/*
 * rules(): prints the rules to Blackjack
 * parameters: bool o, true for reading the rules and false to skip the rules
 * returns: none
 */
void rules(bool o) {
    if (o == true) {
        cout << "Each player starts with 2 cards. Ace can equal 1 or 11, in this game it will always be counted as 11 until the player busts, then it will be counted as 1. All face cards equal 10, no wild cards, no jokers. Each player can ask for additional cards during their turn by typing 'h' for hit when prompted. Once they type 's' for stay, their turn is over and their hand is finalized. Once they bust, their turn is over and they have lost. The goal is to get cards totaling to as close to 21 as possible without exceeding 21.\n\nIf a player gets Blackjack on their first 2 cards, the dealer will return them 150% of their original bet. Players must bet at least $1 every round and cannot bet more than they have access to. If there is a tie, or a push, no one's money changes." << endl << endl;
    }
    return;
}

/*
 * getInfo(): gets and verifies info about the players and assigns it to the objects
 * parameters: BlackJackPlayer &p1, the object of player 1, passed by reference so that the changes made within the function are perminent without returning; BlackJackPlayer &p2, the object of player 2, passed by reference so that the changes made within the function are perminent without returning
 * returns: none
 */
void getInfo(BlackJackPlayer &p1, BlackJackPlayer &p2) {
    string s;
    int i;
    
    cout << "Player 1, what's your name? ";
    cin >> s;
    cout << "How much money are you playing with? ";
    cin >> i;
    i = verifyInt(i);
    p1.setName(s);
    p1.setMoney(i);
    cout << "Player 2, what's your name? ";
    cin >> s;
    cout << "How much money are you playing with? ";
    cin >> i;
    i = verifyInt(i);
    p2.setName(s);
    p2.setMoney(i);
}


/*
 * finalStatus(): handles all cases and adjusts the money of all three players while printing out the outcome of the game
 * parameters: BlackJackPlayer &p1, the object of player 1, passed by reference so that the changes made within the function are perminent without returning; BlackJackPlayer &p2, the object of player 2, passed by reference so that the changes made within the function are perminent without returning; me, the Dealer object, passed by reference
 * returns: none
 */
void finalStatus(BlackJackPlayer &p1, BlackJackPlayer &p2, Dealer &me) {
    cout << endl << endl;
    
    //if the dealer busts, any active hand will beat them
    if (me.getTotal() > 21 ) {
        me.null();
    }

    
    if (p1.getTotal() == 21 && me.getTotal() != 21) {
        if (p1.getSize() == 2) {
            cout << p1.getName() << " got Blackjack! They win 150% of their bet, which is $" << (p1.getBet() * 1.5) << endl;
            p1.setBet(p1.getBet()*1.5);
            p1.winMoney();
            me.updateWinnings(-p1.getBet());
        }
        else if (p1.getTotal() == me.getTotal()) {
            cout << "Looks like there's a push! " << p1.getName() << " keeps their money this round." << endl;
        }
        else {
            cout << p1.getName() << " wins $" << p1.getBet() << endl;
            p1.winMoney();
            me.updateWinnings(-p1.getBet());
        }
    }
    
    if (p2.getTotal() == 21 && me.getTotal() != 21) {
        if (p2.getSize() == 2) {
            cout << p2.getName() << " got Blackjack! They win 150% of their bet, which is $" << (p2.getBet() * 1.5) << endl;
            p2.setBet(p2.getBet()*1.5);
            p2.winMoney();
            me.updateWinnings(-p2.getBet());
        }
        else if (p2.getTotal() == me.getTotal()) {
            cout << "Looks like there's a push! " << p2.getName() << " keeps their money this round." << endl;
        }
        else {
            cout << p2.getName() << " wins $" << p2.getBet() << endl;
            p2.winMoney();
            me.updateWinnings(-p2.getBet());
        }
        
    }
    
    
    if ((p2.getTotal() > me.getTotal()) && (p1.getTotal() > me.getTotal())) {
        if (p1.isBusted() && p2.isBusted()) {
            cout << "Oh no, both " << p1.getName() << " and " << p2.getName() << " busted." << endl;
            cout << "Looks like the dealer collected $" << p1.getBet() + p2.getBet() << endl;
            p1.loseMoney();
            p2.loseMoney();
            me.updateWinnings(p1.getBet() + p2.getBet());
            
        }
        
        else if (p1.isBusted()) {
            cout << "Oh no, " << p1.getName() << " busted." << endl;
            cout << "The dealer collects $" << p1.getBet();
            p1.loseMoney();
            me.updateWinnings(p1.getBet());
        }
        
        else if (p2.isBusted()) {
            cout << "Oh no, " << p2.getName() << " busted." << endl;
            cout << "The dealer collects $" << p2.getBet();
            p2.loseMoney();
            me.updateWinnings(p2.getBet());
        }
        
        if (p1.getTotal() == 21 && p2.getTotal() != 21) {
            cout << p2.getName() << " wins $" << p2.getBet() << endl;
            p2.winMoney();
            me.updateWinnings(-p2.getBet());
        }
        else if (p2.getTotal() == 21 && p1.getTotal() != 21) {
            cout << p1.getName() << " wins $" << p1.getBet() << endl;
            p1.winMoney();
            me.updateWinnings(-p1.getBet());
        }
        else if (!p1.isBusted() && !p2.isBusted()) {
            if (p1.getTotal() != 21 && p2.getTotal() != 21) {
            cout << p1.getName() << " and " << p2.getName() << " both beat the dealer!" << endl;
            cout << p1.getName() << " wins $" << p1.getBet() << endl;
            p1.winMoney();
            me.updateWinnings(-p1.getBet());
            cout << p2.getName() << " wins $" << p2.getBet() << endl;
            p2.winMoney();
            me.updateWinnings(-p2.getBet());
            }
        }
    }
    
    
    else if ((p1.getTotal() > me.getTotal()) && (p2.getTotal() < me.getTotal())) {
        if (p1.getTotal() == 21) {
            cout << p2.getName() << " lost to the dealer, losing $" << p2.getBet() << endl;
            p2.loseMoney();
            me.updateWinnings(p2.getBet());
        }
        else if (p1.getTotal() > 21) {
            cout << p1.getName() << " busted, which means the dealer collects $" << p1.getBet() << endl;
            p1.loseMoney();
            me.updateWinnings(p1.getBet());
            cout << p2.getName() << " lost to the dealer, losing $" << p2.getBet() << endl;
            p2.loseMoney();
            me.updateWinnings(p2.getBet());
        }
        else {
            cout << p1.getName() << " beat the dealer, winning $" << p1.getBet() << endl;
            p1.winMoney();
            me.updateWinnings(-p1.getBet());
            cout << p2.getName() << " lost to the dealer, losing $" << p2.getBet() << endl;
            p2.loseMoney();
            me.updateWinnings(p2.getBet());
        }
    }
    
    
    else if ((p1.getTotal() < me.getTotal()) && (p2.getTotal() > me.getTotal())) {
        if (p2.getTotal() == 21) {
            cout << p1.getName() << " lost to the dealer, losing $" << p1.getBet() << endl;
            p1.loseMoney();
            me.updateWinnings(p1.getBet());
        }
        else if (p2.getTotal() > 21) {
            cout << p2.getName() << " busted, which means the dealer collects $" << p2.getBet() << endl;
            p2.loseMoney();
            me.updateWinnings(p2.getBet());
            cout << p1.getName() << " lost to the dealer, losing $" << p1.getBet() << endl;
            p1.loseMoney();
            me.updateWinnings(p1.getBet());
        }
        else {
            cout << p2.getName() << " beat the dealer, winning $" << p2.getBet() << endl;
            p2.winMoney();
            me.updateWinnings(-p2.getBet());
            cout << p1.getName() << " lost to the dealer, losing $" << p1.getBet() << endl;
            p1.loseMoney();
            me.updateWinnings(p1.getBet());
        }
    }
    
    
    else if ((p1.getTotal() == me.getTotal()) || (p2.getTotal() == me.getTotal())) {
        if ((p1.getTotal() == me.getTotal()) && (p2.getTotal() == me.getTotal())) {
            cout << "Both players push the dealer! Everyone keeps their money this round." << endl;
        }
        else if (p1.getTotal() == me.getTotal() && (p2.getTotal() != me.getTotal())) {
            cout << "Look's like there's a push. " << p1.getName() << " keeps their money." << endl;
            if (p2.getTotal() < me.getTotal()) {
                cout << p2.getName() << " lost to the dealer, losing $" << p2.getBet() << endl;
                p2.loseMoney();
                me.updateWinnings(p2.getBet());
            }
            else if (p2.getTotal() < 21) {
                cout << p2.getName() << " beat the dealer, winning $" << p2.getBet() << endl;
                p2.winMoney();
                me.updateWinnings(-p2.getBet());
            }
            else {
                cout << p2.getName() << " busted, so the dealer collects $" << p2.getBet() << endl;
                p2.loseMoney();
                me.updateWinnings(p2.getBet());
            }
        }
        
        
        else {
            cout << "Look's like there's a push. " << p2.getName() << " keeps their money." << endl;
            if (p1.getTotal() < me.getTotal()) {
                cout << p1.getName() << " lost to the dealer, losing $" << p1.getBet() << endl;
                p1.loseMoney();
                me.updateWinnings(p1.getBet());
            }
            else if (p1.getTotal() < 21) {
                cout << p1.getName() << " beat the dealer, winning $" << p1.getBet() << endl;
                p1.winMoney();
                me.updateWinnings(-p1.getBet());
            }
            else {
                cout << p1.getName() << " busted, so the dealer collects $" << p1.getBet() << endl;
                p1.loseMoney();
                me.updateWinnings(p1.getBet());
            }
        }
    }
    
    
    else {
        cout << "Looks like both players lost!" << endl;
        cout << p1.getName() << " loses $" << p1.getBet() << endl;
        p1.loseMoney();
        me.updateWinnings(p1.getBet());
        cout << p2.getName() << " loses $" << p2.getBet() << endl;
        p2.loseMoney();
        me.updateWinnings(p2.getBet());
        
    }
    
    
    //printing out the final standings
    cout << "\nAt the end of this round: \n\n" << p1.getName() << " has $" << p1.getMoney() << endl;
    cout << p2.getName() << " has $" << p2.getMoney() << endl;
    cout << "Dealer is up $" << me.getWinnings() << endl << endl;
}




int main(void) {
    
    string s;
    bool again = true;
    BlackJackPlayer p1, p2;
    Dealer me;
    
    cout << "Welcome to the Blackjack table at the Blanck Check Casino!" << endl;
    cout << "Would you like to see the rules? Type y for yes or n for no" << endl;
    cin >> s;
    rules(yesOrNo(s));
    
    cout << "Wonderful, let's begin!" << endl << endl;
    
    getInfo(p1, p2);
    cout << endl;
    
    int j = 1; //keeps track of the round number
    
    
    //game play loop
    while (again) {
        int b = 0;
        
        cout << endl << "Round " << j << ": " << endl;
        
        cout << p1.getName() << " has $" << p1.getMoney() << endl;
        cout << p1.getName() << ", how much would you like to bet? ";
        cin >> b;
        b = verifyInt(p1.getMoney(), b);
        p1.setBet(b);
        cout << p2.getName() << " has $" << p2.getMoney() << endl;
        cout << p2.getName() << ", how much would you like to bet? ";
        cin >> b;
        b = verifyInt(p2.getMoney(), b);
        p2.setBet(b);
        
        
        Deck d;
        d.shuffle();
        
        p1.add(d.deal());
        p2.add(d.deal());
        me.add(d.deal());
        
        p1.add(d.deal());
        p2.add(d.deal());
        me.add(d.deal());
        
        cout << "\nStarting cards: " << endl;
        cout << p1.getName() << ": " << p1.getHand().at(0).showCard() << " [??]" << endl;
        cout << p2.getName() << ": " << p2.getHand().at(0).showCard() << " [??]" << endl;
        cout << "Dealer: " << me.getHand().at(0).showCard() << " [??]" << endl;
        
        
        //player 1's turn begins
        cout << endl << p1.getName() << "'s turn!" << endl;
        while (!p1.isDone()) {
            string n = "";
            cout << "\nYour cards: " ;
            for (int i = 0; i < p1.getSize(); i++) {
                cout << p1.getHand().at(i).showCard();}
            cout << "\nYour hand is worth " << p1.getTotal() << " points." << endl;
            cout << "Would you like to (h)it or (s)tay? ";
            cin >> n;
            p1.action(hitOrStay(n), d);
        }
        if (p1.isBusted()) {
            cout << "Shoot! " << p1.getName() << " busted with " << p1.getTotal() << " points." << endl;
            cout << p1.getName() << "'s final hand: ";
            for (int i = 0; i < p1.getSize(); i++) {
                cout << p1.getHand().at(i).showCard();}
        }
        else {
            cout << p1.getName() << "'s final hand: ";
            for (int i = 0; i < p1.getSize(); i++) {
                cout << p1.getHand().at(i).showCard();}
            cout << endl << p1.getName() << "'s hand is worth " << p1.getTotal() << " points." << endl;
        }
        
        
        //player 2's turn begins
        cout << endl << p2.getName() << "'s turn!" << endl;
        while (!p2.isDone()) {
            string n = "";
            cout << "\nYour cards: " ;
            for (int i = 0; i < p2.getSize(); i++) {
                cout << p2.getHand().at(i).showCard();}
            cout << "\nYour hand is worth " << p2.getTotal() << " points." << endl;
            cout << "Would you like to (h)it or (s)tay? ";
            cin >> n;
            p2.action(hitOrStay(n), d);
        }
        if (p2.isBusted()) {
            cout << "Shoot! " << p2.getName() << " busted with " << p2.getTotal() << " points." << endl;
            cout << p2.getName() << "'s final hand: " ;
            for (int i = 0; i < p2.getSize(); i++) {
                cout << p2.getHand().at(i).showCard();}
            cout << endl;
        }
        else {
            cout << p2.getName() << "'s final hand: " ;
            for (int i = 0; i < p2.getSize(); i++) {
                cout << p2.getHand().at(i).showCard();}
            cout << endl << p2.getName() << "'s hand is worth " << p2.getTotal() << " points." << endl;
        }
        
        
        //dealer's turn
        cout << endl << "Dealer's turn!" << endl;
        while(!me.isDone()) {
            cout << "\nDealer's cards: ";
            for (int i = 0; i < me.getSize(); i++) {
                cout << me.getHand().at(i).showCard();}
            me.action(me.toHit(), d);
        }
        cout << "Dealer's final hand: ";
        for (int i = 0; i < me.getSize(); i++) {
            cout << me.getHand().at(i).showCard();}
        
        
        
        finalStatus(p1, p2, me);
        cout << "Would you like to play again? ";
        cin >> s;
        again = yesOrNo(s);
        
        
        //potentially clearing all player info for the next round
        p1.reset();
        p2.reset();
        me.reset();
        j++;
    }
    
    cout << "\nThanks for playing! We'll see you back soon." << endl;
}
