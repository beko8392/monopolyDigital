//cs1300 Fall 2021
// Author: Benjamin Kohav & Charlotte Gorgemans
// Recitation: 116 - Alex Ray & 111 Tiffany Phan
// Project 3 -- Game.h


#ifndef GAME_H // preprocessor directives
#define GAME_H

#include <string>
#include <iostream>
#include "Bank.h"
#include "Properties.h"
#include "Map.h"
#include "Player.h"
#include <vector>

using namespace std;

class Game
{
    public: 
    //default constructor
    Game();

    //parameterized constructor
    Game(Player players[6], Properties prpts[30], Map m);

    //getters
    Player getPlayer(int p);
    Map getMap();
    Properties getProperty(int l);
    int movePlayer(int currentPlayer, int diceRoll);

    //other functions
    void removePlayer(int numPlayers, int p);
    int findPropOwner(int numPlayers, int l);
    void withdrawFrom(int currentPlayer, int amount);
    void depositFrom(int currentPlayer, int amount);
    void playerPassGo(int currentPlayer);
    void playerTaxes(int currentPlayer);
    void sendToJail(int currentPlayer);
    void addPropertyTo(int currentPlayer, int l);
    void addOwnerTo(int l);
    string getPropertyNameAt(int location);
    void takeOutOfJail(int p);
    void removePropertyFrom(int currentPlayer, int location);

    //private, inaccessible areas of Property class.
    private:
    Player plyrs[6];
    Map newMap = Map();
    Properties props[30];
    //map class object
};

#endif