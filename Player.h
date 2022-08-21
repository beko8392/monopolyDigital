//cs1300 Fall 2021
// Author: Benjamin Kohav & Charlotte Gorgemans
// Recitation: 116 - Alex Ray & 001 Tiffany Phan
// Project 3 -- Player.h


#ifndef PLAYER_H // preprocessor directives
#define PLAYER_H

#include <string>
#include <iostream>
#include <vector>
#include "Bank.h"
#include "Properties.h"

using namespace std;

class Player
{
    public: 
    //default constructor
    Player();

    //parameterized constructor
    Player(string pName);
    Player(string pName, Bank pBank, vector<int> pProperty);

    //getters -> all play a crucial role in ensuring that driver function operates correctly and that class compiles without error
    string getName();
    Bank getplayerBank();
    bool getJail();
    void isInJail();
    void outOfJail();
    char getPlayerChar();
    void addProperty(int l);
    vector<int> getPlayerProps();

    void withdrawTo(int a);
    void depositTo(int a);
    void payTaxesTo();
    void passPlayerGo();
    void removeProperty(int l);

    //private, inaccessible areas of Property class.
    private:
    string playerName;
    Bank playerBank;
    vector<int> playerPrprties;
    bool inJail;
    char playerChar;
};

#endif