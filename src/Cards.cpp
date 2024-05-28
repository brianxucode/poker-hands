// ITP 365 Fall 2021
// HW04 – Poker Hands
// Name: Brian Xu
// Email: brianjxu@usc.edu
// Platform: Mac

// Cards.cpp
// Implements Cards and Poker Hand functionality
#include "Cards.h"

#include <algorithm>
#include <random>

// Function: Constructor
// Purpose: Draws 5 cards from the supplied deck, and sorts them
// by rank
// Input: Takes in a ITPVector of cards for the deck
// Returns: Nothing
PokerHand::PokerHand(ITPVector<Card>& deck)
{
    //creating the cards and putting them into the deck
    for (unsigned i = 0; i < 5; i++)
    {
        //if empty
        if (deck.size() == 0)
        {
            createDeck(deck);
        }
        //get the card from back function
        Card card = deck.back();
        //pop it out
        deck.pop_back();
        //push it into the hand
        mHand.push_back(card);
    }
    
    sortHand();
}


// Function: sortHand
// Purpose: Sorts the cards in ascending order by rank
// Input: None
// Returns: Nothing
void PokerHand::sortHand()
{
    //sort the hand
    sort(&mHand[0], &mHand[0] + mHand.size());
}


// Function: getBestPokerHand
// Purpose: Returns a string describing the poker hand this PokerHand
// contains
// Input: None
// Returns: The name of the best poker hand
std::string PokerHand::getBestPokerHand() const
{
    string msg = "";
    
    //appending to msg
    if (hasStraight() && hasFlush()){
        msg += "straight flush";
    }
    else if (hasStraight())
    {
        msg += "straight";
    }
    else if (hasFlush())
    {
        msg += "flush";
    }
    else if (hasFourOfAKind())
    {
        msg += "four of a kind";
    }
    else if (hasFullHouse())
    {
        msg += "full house";
    }
    else if (hasThreeOfAKind())
    {
        msg += "three of a kind";
    }
    else if (hasTwoPairs())
    {
        msg += "two pairs";
    }
    else if (hasPair())
    {
        msg += "pair";
    }
    else
    {
        msg += "high card";
    }
        
    return msg;
}

// Function: hasStraight
// Purpose: Determines if the hand has a straight
// Input: None
// Returns: true if there's a straight
bool PokerHand::hasStraight() const
{
    //count is how this function will work. basically it's a simple way of incrementing count if conditions are correct, then using this variable to determine if hasStraight is true or not
    unsigned count = 0;
    for (size_t i = 0; i < mHand.size()-1; i++){
      
        if ((mHand[i + 1].mRank - mHand[i].mRank) == 1)
            count++;
    }
    //if count hits 4, that means all cards were in a straight pattern
    if (count == 4)
        return true;
    
    return false;
}

// Function: hasFlush
// Purpose: Determines if the hand has a flush
// Input: None
// Returns: true if there's a flush
bool PokerHand::hasFlush() const
{
    //count is how this function will work. basically it's a simple way of incrementing count if conditions are correct, then using this variable to determine if hasStraight is true or not
    unsigned count = 0;
    for (size_t i = 0; i < mHand.size() - 1; i++) {

        if (mHand[i].mSuit == mHand[i + 1].mSuit)
            count++;

    }
    //if count hits 4, that means all cards were in a flush pattern
    if (count == 4)
        return true;

    return false;
}

// Function: hasFourOfAKind
// Purpose: Determines if the hand has a 4 of a kind
// Input: None
// Returns: true if there's a 4 of a kind
bool PokerHand::hasFourOfAKind() const
{
    // Since it's sorted, there are only two possibilities:
    // x x x x y
    // or
    // x y y y y

    // TODO: Fix this
    if ((mHand[0].mRank == mHand[1].mRank && mHand[0].mRank == mHand[2].mRank &&
         mHand[0].mRank == mHand[3].mRank) || (mHand[1].mRank == mHand[2].mRank &&
         mHand[1].mRank == mHand[3].mRank && mHand[1].mRank == mHand[4].mRank))
    {
        return true;
    }
           
    return false;
}

// Function: hasFullHouse
// Purpose: Determines if the hand has a full house
// Input: None
// Returns: true if there's a full house
bool PokerHand::hasFullHouse() const
{
    // Since it's sorted, there are only two possibilities:
    // x x x y y
    // or
    // x x y y y
    
    
    if ((mHand[0].mRank == mHand[1].mRank && mHand[0].mRank == mHand[2].mRank &&
        mHand[3].mRank == mHand[4].mRank) || (mHand[0].mRank == mHand[1].mRank &&
        mHand[2].mRank == mHand[3].mRank && mHand[2].mRank == mHand[4].mRank))
    {
        return true;
    }

    return false;
}

// Function: hasThreeOfAKind
// Purpose: Determines if the hand has a three of a kind
// Input: None
// Returns: true if there's a three of a kind
bool PokerHand::hasThreeOfAKind() const
{
    // There are three possibilities:
    // x x x y z
    // x y y y z
    // x y z z z
    
    if ((mHand[0].mRank == mHand[1].mRank && mHand[0].mRank == mHand[2].mRank) ||
        ((mHand[1].mRank == mHand[2].mRank) && (mHand[1].mRank == mHand[3].mRank)) ||
        (mHand[2].mRank == mHand[3].mRank && mHand[2].mRank == mHand[4].mRank))
    {
        return true;
    }

    return false;
}

// Function: hasTwoPairs
// Purpose: Determines if the hand has two pairs
// Input: None
// Returns: true if there's two pairs
bool PokerHand::hasTwoPairs() const
{
    // There are three possibilities:
    // x x y y z
    // x y y z z
    // x x y z z
    if ((mHand[0].mRank == mHand[1].mRank && mHand[2].mRank == mHand[3].mRank) ||
        ((mHand[1].mRank == mHand[2].mRank) && (mHand[3].mRank == mHand[4].mRank)) ||
        (mHand[0].mRank == mHand[1].mRank && mHand[3].mRank == mHand[4].mRank))
    {
        return true;
    }
    
    return false;
}

// Function: hasPair
// Purpose: Determines if there's a pair
// Input: None
// Returns: true if there's a pair
bool PokerHand::hasPair() const
{
    // There's a pair if any neighbors are equal to each other
    if ((mHand[0].mRank == mHand[1].mRank) || (mHand[1].mRank == mHand[2].mRank) ||
        (mHand[2].mRank == mHand[3].mRank) || (mHand[3].mRank == mHand[4].mRank))
    {
        return true;
    }
    
    return false;
}

// Function: createDeck
// Purpose: Given an empty ITPVector of Cards, inserts a
// standard 52 card deck and shuffles it
// Input: An ITPVector of Cards (by reference)
// Returns: nothing
void createDeck(ITPVector<Card>& deck)
{
    
    // Just in case, a full deck is passed in if deck.size() was already constructed and not equal to 0.
    if (deck.size() != 0)
    {
        deck = ITPVector<Card>(52);
    }
    //going from suit clubs to suit spades
    for (unsigned suit = Suit::CLUBS; suit <= Suit::SPADES; suit++)
    {
        //going from rank 2 to rank 14
        for (unsigned rank = 2; rank <= 14; rank++)
        {
            //pushing back the card
            deck.push_back(Card(rank, static_cast<Suit>(suit)));
        }
    }

    // Shuffle the deck
    // LEAVE THIS HERE!
    std::sort(&deck[0], &deck[0] + deck.size());
    std::random_shuffle(&deck[0], &deck[0] + deck.size());
    
}

// Function: << operator for Card
// Purpose: Outputs the name and suit of the card
// Input: ostream and card
// Returns: ostream, with card data output to it
std::ostream& operator<<(std::ostream& os, const Card& card)
{
    // TODO: Fix this
    string rank;
    switch (card.mRank)
    {
        //corresponding highcard to its rank
        case 11:
            rank = "Jack";
            break;

        case 12:
            rank = "Queen";
            break;

        case 13:
            rank = "King";
            break;

        case 14:
            rank = "Ace";
            break;

        default:
            rank = to_string(card.mRank);
            break;
    }

    os << rank << " of ";
    
    string suit;
    switch (card.mSuit)
    {
        case Suit::CLUBS:
            suit = "Clubs";
            break;

        case Suit::DIAMONDS:
            suit = "Diamonds";
            break;

        case Suit::HEARTS:
            suit = "Hearts";
            break;

        case Suit::SPADES:
            suit = "Spades";
            break;
    }

    os << suit << flush;

    return os;
}


// Function: < comparison operator for Card
// Purpose: Compares the value of the left and right card
// Input: Two cards to compare
// Returns: true if left < right
bool operator<(const Card& left, const Card& right)
{
    // If their ranks are the same, compare the suits
    if (left.mRank == right.mRank){
        return (int)left.mSuit < (int)right.mSuit;
    }
    
    return left.mRank < right.mRank;
}

// Function: > comparison operator for Card
// Purpose: Compares the value of the left and right card
// Input: Two cards to compare
// Returns: true if left > right
bool operator>(const Card& left, const Card& right)
{
    // If their ranks are the same, compare the suits
    if (left.mRank == right.mRank) {
        return ((int)left.mSuit > (int)right.mSuit);
    }

    return left.mRank > right.mRank;
}

// Function: << operator
// Purpose: Prints out the hand
std::ostream& operator<<(std::ostream& os, const PokerHand& hand)
{
    //flush out stuff afterwards
    os << hand.mHand << flush;
    
    return os;
}
