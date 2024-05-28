// ITP 365 Fall 2021
// HW04 – Poker Hands
// Name: Brian Xu
// Email: brianjxu@usc.edu
// Platform: Mac

#include <iostream>
#include <ctime>

#include "ITPVector.hpp"
#include "Cards.h"
#include "Play.h"

int main(int argc, const char* argv[])
{
    //constructing the time
    srand((time(nullptr)));
    //calling playPoker function, which runs everything basically
    playPoker(std::cin, std::cout, time(nullptr));
    
    
    return 0;
}
