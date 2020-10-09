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
using namespace std;

string generateRandomKey();
bool isValid(string);
string key;
int spaces;
string normalAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

std::string convertToUpperCase(std::string input)
{
//  - use toupper()
    transform(input.begin(), input.end(), input.begin(), ::toupper);
    return input;
}

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

bool isValid(string input) {

    // checking for max length
    if (input.length() > 26) {
        cout << "Incorrect key length. Must be 26 characters." << endl;
    }
    else {

        for (int i{ 0 }; i < input.size(); i++) {

            // checking for non-alphabetic characters
            if (!isalpha(input.at(i))) {
                cout << "Error: invalid character in key." << endl;
                break;
            }

            // checking for same consecutive letters
            if (input.at(i) == input.at(i + 1)) {
                cout << "Error: letters in key must be used only once." << endl;
                break;
            }
        }

    }
    return false;
}

string encryption(string input, string key)
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
    string output;
    
    for(int i = 0; i < input.length(); i++)
    {
        long temp = normalAlphabet.find(input.at(i));
        output += key[temp];
    }
    return output;
}

string spacing(string finalMessage, int spaces)
{
    string output;
    
    for(int i = 0; i < finalMessage.length(); i++)
    {
        if(i % spaces == 0)
        {
            output += " ";
        }else
        {
            output += finalMessage.at(i);
        }
    }
    
    return output;
}


int main() {

    int choice;
    string plaintext;
    string encryptedText;
    
    cout << "Testing Monoalphabetic Substitution Cipher (MASC) program:" << endl;
    cout << endl;
    cout << "Please make a selection:" << endl;
    cout << "(1) Type in a key" << endl;
    cout << "(2) Have a key generated for you" << endl;
    cout << endl;

    // asking user for their choice
    cout << "Choice: ";
    cin >> choice;
    cin.ignore();
    cout << endl;

    if (choice == 1) {
        
        cout << "Enter a key to be used for encryption and decryption. Include each letter of alphabet, none repeated:" << endl;
        getline(cin, key);
        isValid(key);
        transform(key.begin(), key.end(), key.begin(), ::toupper);
        cout << "Key is now: " << key << endl;
        cout << endl;

        cout << "Enter the plaintext: ";
        getline(cin, plaintext);
        cout << endl;

        cout << "We will now disguise the original spacing." << endl;
        cout << "How many letters should appear in each grouping? " << '\n' << "(press Enter for default spacing of 5, negative entry leaves original spacing" << endl;
        cout << "Spacing: ";
        cin >> spaces;
        cout << endl;
        plaintext = convertToUpperCase(plaintext);
        // call encryption() function here
        encryptedText = encryption(plaintext, key);
        // call spacing() function here
        encryptedText = spacing(encryptedText, spaces);
        cout << "Ciphertext is: " + encryptedText << endl;
    }
    else if (choice == 2) {
        key = generateRandomKey();
        cout << "Key is now: " << key << endl;
        cout << endl;
        cout << "Enter the plaintext: ";
        getline(cin, plaintext);
        cout << endl;

        cout << "We will now disguise the original spacing." << endl;
        cout << "How many letters should appear in each grouping? " << '\n' << "(press Enter for default spacing of 5, negative entry leaves original spacing" << endl;
        cout << "Spacing: ";
        cin >> spaces;
        cout << endl;
        plaintext = convertToUpperCase(plaintext);
        // call encryption() function here
        encryptedText = encryption(plaintext, key);
        // call spacing() function here
        encryptedText = spacing(encryptedText, spaces);
        cout << "Ciphertext is: " + encryptedText << endl;
    }

}


