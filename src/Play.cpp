// ITP 365 Fall 2021
// HW04 – Poker Hands
// Name: Brian Xu
// Email: brianjxu@usc.edu
// Platform: Mac

#include "ITPVector.hpp"
#include "Cards.h"

#include <ctime>
#include <fstream>
#include <iostream>

void playPoker(std::istream& in, std::ostream& out, unsigned seed)
{
    srand(seed);
    
    //do while loop for "menu prompts"
    char choice = '\0';
    do
    {
        //an itpvector of cards
        ITPVector<Card> deck;
        //create the deck
        createDeck(deck);
        //generate hand
        PokerHand hand(deck);
        //print out hand
        out << "You drew: " << hand << endl;
        //print out situation of hand
        out << "You have a " << hand.getBestPokerHand() << endl;
        //do you want to try again
        out << "Try again (y/n):";
        in >> choice;
    } while (tolower(choice) != 'n'); 
    
}


void playPoker(const std::string& inFile, const std::string& outFile, unsigned seed)
{
    //in stream
    ifstream fin(inFile);
    //out stream
    ofstream fout(outFile);
    //call above playPoker function, passing in the newly created instream and outstream
    playPoker(fin, fout, seed);
    
}
