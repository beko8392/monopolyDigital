//cs1300 Fall 2021
// Author: Benjamin Kohav & Charlotte Gorgemans
// Recitation: 116 - Alex Ray & 111 Tiffany Phan
// Project 3 -- Player.cpp

#include <string>
#include <iostream>
#include "Player.h"
#include "Bank.h"
#include "Properties.h"

using namespace std;
    
    //default constructor
    Player::Player()
    {
        playerName = " ";
        playerBank = Bank();
        playerPrprties = vector<int> (0);
        playerChar = 'x';        
    }

    //parameterized constructor -> if only the player name is given
    Player::Player(string pName)
    {
        playerName = pName;
        playerBank = Bank();
        playerPrprties = vector<int> (0); 
        inJail = 0;       
        playerChar = 'x';
    }

    //if all of the private variables are pre-made
    Player::Player(string pName, Bank pBank, vector<int> pProperty)
    {
        playerName = pName;
        playerBank = pBank;
        playerPrprties = pProperty;
        inJail = 0;
        playerChar = 'x';
    }

    //getters
    
    //gets and returns playerName
    string Player::getName()
    {
        return playerName;
    }

    //gets and returns playerBank
    Bank Player::getplayerBank()
    {
        return playerBank;
    }

    //gets and returns inJail -> status of whether or not player is in jail
    bool Player::getJail()
    {
        return inJail;
    }

    //if player is in jail, then inJail will be set to 1 (true)
    void Player::isInJail()
    {
        inJail = 1;
    }

    //if player is released from jail, then inJail is set to 0 (false)
    void Player::outOfJail()
    {
        inJail = 0;
    }
    
    //get the player character
    char Player::getPlayerChar()
    {
        return playerChar;
    }

    //adds a property to a player's properties vector
    void Player::addProperty(int l)
    {
        playerPrprties.push_back(l);
    }

    //returns the properties that a player has
    vector<int> Player::getPlayerProps()
    {
        return playerPrprties;
    }


    //withdraw a number of dollars from a player's bank account
    void Player::withdrawTo(int a)
    {
        playerBank.withdraw(a);
    }

    //deposit a number of dollars to a player
    void Player::depositTo(int a)
    {
        playerBank.deposit(a);
    }

    //pay taxes to a player
    void Player::payTaxesTo()
    {
        playerBank.payTaxes();
    }

    //player passes go
    void Player::passPlayerGo()
    {
        playerBank.passGo();
    }

    //removes a particular property from a players property vector.
    void Player::removeProperty(int l)
    {
        for(int i = 0; i < playerPrprties.size(); i ++)
        {
            if(playerPrprties[i] == l)
            {
                playerPrprties.erase(playerPrprties.begin() + i);
                break;
            }
        }
    }
