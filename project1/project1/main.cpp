//
//  main.cpp
//  project1
//
//  Created by Michael Kelnar on 10/6/20.
//  Copyright © 2020 Michael Kelnar. All rights reserved.
//

#include <iostream>
#include <string>
#include <random>
#include <ctime>

//constant variables
int space = 5;

int main()
{
//    (Intro)
//    (Ask for choice)
//      if (choice 1)
//        - user enters key they want to be encrypted
//        - valid input (function)
//        - if invalid, display error message
//        - if valid, convert to uppercase function
//        - ask for plaintext
//        - ask for # of spaces
//        - execute other functions
//        - output final encryted text
//      if (choice 2)
//        - random key function
//        - ask for plaintext
//        - ask for # of spaces
//        - execute functions
//        - output final encrypted text
    
}

bool isValid(std::string input)
{
//    - only supposed to contain letters
//        - isalpha() function we could use on strings
//    - check for same letters in consecutive order
//    - check for length (26 max)
    
    
    return false;
}

std::string convertToUpperCase(std::string input)
{
//  - use toupper()
    transform(input.begin(), input.end(), input.begin(), ::toupper);
    return input;
}

std::string encryption(std::string input)
{
//  - each letter in key corresponds to a letter in the alphabet
//  - each letter in plaintext corresponds to each letter in key
//      ex. ZHSRWOTEVXQPIABGYUCLFNJMDK
//          ||||||||||||....
//          ABCDEFGHIJKLMNOPQRSTUVWXYZ
//          plaintext: THE Time Traveler
//          THE Time Traveler
//          ||| |||| ||||||||
//          LEW LVIW ....
//   - I think it is easier to encrypt it first then do the spacing later
    std::string output;
    
    //code
    
    return output;
}

std::string spacing(std::string finalMessage, int space)
{
//  - now split final message into the specified spaces
    std:: string output;
    
    //code
    
    return output;
}

//The following is a generateRandomKey() function that you may use in Project 1
//Note: you will likely need to #include <random> and #include <ctime>


//generates an uppercase MASC key by shuffling the English alphabet
std::string generateRandomKey()
{
    std::string randomKey{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    std::random_device rnd;
    const auto seed = rnd.entropy() ? rnd() : time(nullptr);
    std::mt19937_64 eng(static_cast<std::mt19937_64::result_type>(seed));

    std::cout << "\nGenerating random key..." << std::endl;
    shuffle(randomKey.begin(), randomKey.end(), eng);

    return randomKey;
}
