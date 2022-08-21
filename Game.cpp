//cs1300 Fall 2021
// Author: Benjamin Kohav & Charlotte Gorgemans
// Recitation: 116 - Alex Ray & 111 Tiffany Phan
// Project 3 -- Game.cpp

#include <string>
#include <iostream>
#include "Game.h"

using namespace std;

    //default constructor
    Game::Game()
    {
        for(int i = 0; i < 6; i++)
        {
            plyrs[i] = Player();
        }
    }

    //parameterized constructor
    Game::Game(Player players[6], Properties prpts[30], Map m)
    {
        for(int i = 0; i < 6; i++)
        {
            plyrs[i] = players[i];
        }
        // props = prpts;
        for(int i = 0; i < 28; i++)
        {
            props[i] = prpts[i];
        }
        newMap = m;
    }

    //getters 

    //getPlayer takes parameter int p and returns plyrs array at p
    Player Game::getPlayer(int p)
    {
        return plyrs[p];
    }

    //getMap returns newMap
    Map Game::getMap()
    {
        return newMap;
    }

    //getProperty returns props array at int l
    Properties Game::getProperty(int l)
    {
        return props[l];
    }

    //removePlayer takes numPlayers and p, removing the specific player from the map.
    void Game::removePlayer(int numPlayers,int p)
    {
        for(int i = p; i < numPlayers; i++)
        {
            plyrs[i] = plyrs[i+1];
        }
        newMap.removePlayer(numPlayers, p);
    }

    //findPropOwner takes numPlayers and l, iterating through all of the properties, finds the owner and returns whether or not there is an owner of the property
    int Game::findPropOwner(int numPlayers, int l)
    {
        int ownerIs;
        for(int i = 0; i < numPlayers; i++)
        {
            for(int k = 0; k < plyrs[i].getPlayerProps().size(); k++)
            {
                if(plyrs[i].getPlayerProps()[k] == l)
                {
                    ownerIs = i;
                    break;
                }
            }
        }
        return ownerIs;
    }

    //movePlayer takes currentPlayer and diceRoll, updating and returning the updated position of the player
    int Game::movePlayer(int currentPlayer, int diceRoll)
    {
        int newPosition;

        newPosition = newMap.executeMove(currentPlayer,diceRoll);

        return newPosition;
    }

    //withdrawFrom takes the currentPlayer and the amount, withdrawing x amount of money from a player's account
    void Game::withdrawFrom(int currentPlayer, int amount)
    {
        plyrs[currentPlayer].withdrawTo(amount);
    }

    //depositFrom takes currentPlayer and amount, depositing x amount of money into a player's account
    void Game::depositFrom(int currentPlayer, int amount)
    {
        plyrs[currentPlayer].depositTo(amount);
    }

    //playerPassGo takes current player and adds 200$ to the account of each player once they pass go
    void Game::playerPassGo(int currentPlayer)
    {
        plyrs[currentPlayer].passPlayerGo();
    }

    //pays taxes from one player to another
    void Game::playerTaxes(int currentPlayer)
    {
        plyrs[currentPlayer].payTaxesTo();
    }

    //sends a player to jail, updates the player's status as they are in jail.
    void Game::sendToJail(int currentPlayer)
    {
        newMap.toJail(currentPlayer);
        plyrs[currentPlayer].isInJail();
    }

    //takes currentPlayer and l, adding a property to a player's current portfolio
    void Game::addPropertyTo(int currentPlayer, int l)
    {
        plyrs[currentPlayer].addProperty(l);
    }

    //updates and makes sure that the player is the new owner of the property
    void Game::addOwnerTo(int l)
    {
        props[l].newOwner();
    }

    //gets the name of a property given the number on the map class that the player is residing at
    string Game::getPropertyNameAt(int location)
    {
        string propName = props[location].getPropertyName();
        return propName;
    }

    //removes a player from jail, allows player to continue playing the game normally
    void Game::takeOutOfJail(int p)
    {
        plyrs[p].outOfJail();
    }

    //removes a property from one of the player object's property vectors. 
    void Game::removePropertyFrom(int currentPlayer, int location)
    {
        plyrs[currentPlayer].removeProperty(location);
    }

