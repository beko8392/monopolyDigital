//cs1300 Fall 2021
// Author: Benjamin Kohav & Charlotte Gorgemans
// Recitation: 116 - Alex Ray & 111 Tiffany Phan
// Project 3 -- Map.h

#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <iostream>
#include <ctype.h>
#include <vector>

using namespace std;

class Map
{
    //private variables, necessary for class and entire program to compile correctly.
    private:
    string mapData[11][11];
    string originalMapData[11][11];
    int propertyLocations[40][3];
    int playerLocations[6][3] = {0};

    public:
    //default constructor
    Map();
    //parameterized constructor
    Map(int numPlayers);

    //other functions (including getters)
    void toJail(int currentPlayer);
    int executeMove(int currentPlayer,int diceRoll);
    void displayMap(int numPlayers);
    int getPlayerLocation(int currentPlayer);
    int getPlayersAt(int p);
    void removePlayer(int numPlayers, int p);
};

#endif