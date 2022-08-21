//cs1300 Fall 2021
// Author: Benjamin Kohav & Charlotte Gorgemans
// Recitation: 116 - Alex Ray & 111 Tiffany Phan
// Project 3 -- Map.cpp

#include "Map.h"
#include <stdio.h>

//default constructor: initializes each of the values in the mapData and propertyLocations 2D arrays.
Map::Map()
{
    mapData[0][0] = "20";
    mapData[0][1] = "21";
    mapData[0][2] = "22";
    mapData[0][3] = "23";
    mapData[0][4] = "24";
    mapData[0][5] = "25";
    mapData[0][6] = "26";
    mapData[0][7] = "27";
    mapData[0][8] = "28";
    mapData[0][9] = "29";
    mapData[0][10] = "30";

    mapData[1][10] = "31";
    mapData[2][10] = "32";
    mapData[3][10] = "33";
    mapData[4][10] = "34";
    mapData[5][10] = "35";
    mapData[6][10] = "36";
    mapData[7][10] = "37";
    mapData[8][10] = "38";
    mapData[9][10] = "39";

    mapData[1][0] = "19";
    mapData[2][0] = "18";
    mapData[3][0] = "17";
    mapData[4][0] = "16";
    mapData[5][0] = "15";
    mapData[6][0] = "14";
    mapData[7][0] = "13";
    mapData[8][0] = "12";
    mapData[9][0] = "11";

    mapData[10][0] = "10";
    mapData[10][1] = "09";
    mapData[10][2] = "08";
    mapData[10][3] = "07";
    mapData[10][4] = "06";
    mapData[10][5] = "05";
    mapData[10][6] = "04";
    mapData[10][7] = "03";
    mapData[10][8] = "02";
    mapData[10][9] = "01";
    mapData[10][10] = "00";

    propertyLocations[0][1] = 10;
    propertyLocations[1][1] = 9;
    propertyLocations[2][1] = 8;
    propertyLocations[3][1] = 7;
    propertyLocations[4][1] = 6;
    propertyLocations[5][1] = 5;
    propertyLocations[6][1] = 4;
    propertyLocations[7][1] = 3;
    propertyLocations[8][1] = 2;
    propertyLocations[9][1] = 1;
    propertyLocations[10][1] = 0;
    propertyLocations[11][1] = 0;
    propertyLocations[12][1] = 0;
    propertyLocations[13][1] = 0;
    propertyLocations[14][1] = 0;
    propertyLocations[15][1] = 0;
    propertyLocations[16][1] = 0;
    propertyLocations[17][1] = 0;
    propertyLocations[18][1] = 0;
    propertyLocations[19][1] = 0;
    propertyLocations[20][1] = 0;
    propertyLocations[21][1] = 1;
    propertyLocations[22][1] = 2;
    propertyLocations[23][1] = 3;
    propertyLocations[24][1] = 4;
    propertyLocations[25][1] = 5;
    propertyLocations[26][1] = 6;
    propertyLocations[27][1] = 7;
    propertyLocations[28][1] = 8;
    propertyLocations[29][1] = 9;
    propertyLocations[30][1] = 10;
    propertyLocations[31][1] = 10;
    propertyLocations[32][1] = 10;
    propertyLocations[33][1] = 10;
    propertyLocations[34][1] = 10;
    propertyLocations[35][1] = 10;
    propertyLocations[36][1] = 10;
    propertyLocations[37][1] = 10;
    propertyLocations[38][1] = 10;
    propertyLocations[39][1] = 10;

    propertyLocations[0][0] = 10;
    propertyLocations[1][0] = 10;
    propertyLocations[2][0] = 10;
    propertyLocations[3][0] = 10;
    propertyLocations[4][0] = 10;
    propertyLocations[5][0] = 10;
    propertyLocations[6][0] = 10;
    propertyLocations[7][0] = 10;
    propertyLocations[8][0] = 10;
    propertyLocations[9][0] = 10;
    propertyLocations[10][0] = 10;
    propertyLocations[11][0] = 9;
    propertyLocations[12][0] = 8;
    propertyLocations[13][0] = 7;
    propertyLocations[14][0] = 6;
    propertyLocations[15][0] = 5;
    propertyLocations[16][0] = 4;
    propertyLocations[17][0] = 3;
    propertyLocations[18][0] = 2;
    propertyLocations[19][0] = 1;
    propertyLocations[20][0] = 0;
    propertyLocations[21][0] = 0;
    propertyLocations[22][0] = 0;
    propertyLocations[23][0] = 0;
    propertyLocations[24][0] = 0;
    propertyLocations[25][0] = 0;
    propertyLocations[26][0] = 0;
    propertyLocations[27][0] = 0;
    propertyLocations[28][0] = 0;
    propertyLocations[29][0] = 0;
    propertyLocations[30][0] = 0;
    propertyLocations[31][0] = 1;
    propertyLocations[32][0] = 2;
    propertyLocations[33][0] = 3;
    propertyLocations[34][0] = 4;
    propertyLocations[35][0] = 5;
    propertyLocations[36][0] = 6;
    propertyLocations[37][0] = 7;
    propertyLocations[38][0] = 8;
    propertyLocations[39][0] = 9;

    for(int k = 0; k < 40; k++)
    {
        propertyLocations[k][2] = 0;
    }

    for(int i = 1; i < 10; i++)
    {
        for(int k = 1; k < 10; k++)
        {
            mapData[i][k] = "  ";
        }
    }

    for(int j = 0; j < 6; j++)
    {
        playerLocations[j][0] = 0;
        playerLocations[j][1] = 10;
        playerLocations[j][2] = 10;
    }

    propertyLocations[0][2] = 6;
}

//parameterized constructor -> initializes values
Map::Map(int numPlayers)
{
    mapData[0][0] = "20";
    mapData[0][1] = "21";
    mapData[0][2] = "22";
    mapData[0][3] = "23";
    mapData[0][4] = "24";
    mapData[0][5] = "25";
    mapData[0][6] = "26";
    mapData[0][7] = "27";
    mapData[0][8] = "28";
    mapData[0][9] = "29";
    mapData[0][10] = "30";

    mapData[1][10] = "31";
    mapData[2][10] = "32";
    mapData[3][10] = "33";
    mapData[4][10] = "34";
    mapData[5][10] = "35";
    mapData[6][10] = "36";
    mapData[7][10] = "37";
    mapData[8][10] = "38";
    mapData[9][10] = "39";

    mapData[1][0] = "19";
    mapData[2][0] = "18";
    mapData[3][0] = "17";
    mapData[4][0] = "16";
    mapData[5][0] = "15";
    mapData[6][0] = "14";
    mapData[7][0] = "13";
    mapData[8][0] = "12";
    mapData[9][0] = "11";

    mapData[10][0] = "10";
    mapData[10][1] = "09";
    mapData[10][2] = "08";
    mapData[10][3] = "07";
    mapData[10][4] = "06";
    mapData[10][5] = "05";
    mapData[10][6] = "04";
    mapData[10][7] = "03";
    mapData[10][8] = "02";
    mapData[10][9] = "01";
    mapData[10][10] = "00";

    propertyLocations[0][1] = 10;
    propertyLocations[1][1] = 9;
    propertyLocations[2][1] = 8;
    propertyLocations[3][1] = 7;
    propertyLocations[4][1] = 6;
    propertyLocations[5][1] = 5;
    propertyLocations[6][1] = 4;
    propertyLocations[7][1] = 3;
    propertyLocations[8][1] = 2;
    propertyLocations[9][1] = 1;
    propertyLocations[10][1] = 0;
    propertyLocations[11][1] = 0;
    propertyLocations[12][1] = 0;
    propertyLocations[13][1] = 0;
    propertyLocations[14][1] = 0;
    propertyLocations[15][1] = 0;
    propertyLocations[16][1] = 0;
    propertyLocations[17][1] = 0;
    propertyLocations[18][1] = 0;
    propertyLocations[19][1] = 0;
    propertyLocations[20][1] = 0;
    propertyLocations[21][1] = 1;
    propertyLocations[22][1] = 2;
    propertyLocations[23][1] = 3;
    propertyLocations[24][1] = 4;
    propertyLocations[25][1] = 5;
    propertyLocations[26][1] = 6;
    propertyLocations[27][1] = 7;
    propertyLocations[28][1] = 8;
    propertyLocations[29][1] = 9;
    propertyLocations[30][1] = 10;
    propertyLocations[31][1] = 10;
    propertyLocations[32][1] = 10;
    propertyLocations[33][1] = 10;
    propertyLocations[34][1] = 10;
    propertyLocations[35][1] = 10;
    propertyLocations[36][1] = 10;
    propertyLocations[37][1] = 10;
    propertyLocations[38][1] = 10;
    propertyLocations[39][1] = 10;


    propertyLocations[0][0] = 10;
    propertyLocations[1][0] = 10;
    propertyLocations[2][0] = 10;
    propertyLocations[3][0] = 10;
    propertyLocations[4][0] = 10;
    propertyLocations[5][0] = 10;
    propertyLocations[6][0] = 10;
    propertyLocations[7][0] = 10;
    propertyLocations[8][0] = 10;
    propertyLocations[9][0] = 10;
    propertyLocations[10][0] = 10;
    propertyLocations[11][0] = 9;
    propertyLocations[12][0] = 8;
    propertyLocations[13][0] = 7;
    propertyLocations[14][0] = 6;
    propertyLocations[15][0] = 5;
    propertyLocations[16][0] = 4;
    propertyLocations[17][0] = 3;
    propertyLocations[18][0] = 2;
    propertyLocations[19][0] = 1;
    propertyLocations[20][0] = 0;
    propertyLocations[21][0] = 0;
    propertyLocations[22][0] = 0;
    propertyLocations[23][0] = 0;
    propertyLocations[24][0] = 0;
    propertyLocations[25][0] = 0;
    propertyLocations[26][0] = 0;
    propertyLocations[27][0] = 0;
    propertyLocations[28][0] = 0;
    propertyLocations[29][0] = 0;
    propertyLocations[30][0] = 0;
    propertyLocations[31][0] = 1;
    propertyLocations[32][0] = 2;
    propertyLocations[33][0] = 3;
    propertyLocations[34][0] = 4;
    propertyLocations[35][0] = 5;
    propertyLocations[36][0] = 6;
    propertyLocations[37][0] = 7;
    propertyLocations[38][0] = 8;
    propertyLocations[39][0] = 9;

    for(int k = 0; k < 40; k++)
    {
        propertyLocations[k][2] = 0;
    }

    for(int i = 1; i < 10; i++)
    {
        for(int k = 1; k < 10; k++)
        {
            mapData[i][k] = "  ";
        }
    }

    for(int j = 0; j < numPlayers; j++)
    {
        playerLocations[j][0] = 0;
        playerLocations[j][1] = 10;
        playerLocations[j][2] = 10;
    }

    propertyLocations[0][2] = numPlayers;

}

//executes move, moves the particular player to the desired spot determined by dice roll. Returns their new position.
int Map::executeMove(int currentPlayer,int diceRoll)
{
    // change the original "x" position to the original board game value. 
    // set map data based on the player locations. 
   
    propertyLocations[playerLocations[currentPlayer][0]][2] -= 1;
    
    int originalPosition = playerLocations[currentPlayer][0];
    int newPosition = originalPosition + diceRoll;
  
    if(newPosition > 39)
    {
        //current player passes Go, call their bank class. 
        newPosition = newPosition - 39;
        playerLocations[currentPlayer][1] = propertyLocations[newPosition][0];
        playerLocations[currentPlayer][2] = propertyLocations[newPosition][1];
        propertyLocations[newPosition][2] +=1;
    }
    else
    {
        playerLocations[currentPlayer][0] = newPosition;
        playerLocations[currentPlayer][1] = propertyLocations[newPosition][0];
        playerLocations[currentPlayer][2] = propertyLocations[newPosition][1];
        propertyLocations[newPosition][2] +=1;
    }
    
    return newPosition;
}

//moves player position to the jail spot
void Map::toJail(int currentPlayer)
{
    propertyLocations[30][2] -=1;
    //move current player's coordinates to row 10, column 0.
    
    playerLocations[currentPlayer][0] = 10;
    playerLocations[currentPlayer][1] = 10;
    playerLocations[currentPlayer][2] = 0;
    
    propertyLocations[10][2] +=1;
}

//returns number of players at a certain spot on board
int Map::getPlayersAt(int p)
{
    int numPlayers = 0;

    return numPlayers;
}

//prints map data and changes color if there is a known number of players on the same spot
void Map::displayMap(int numPlayers)
{
    string tempString;
    for(int i = 0; i < 11; i++)
    {
       
        for(int k = 0; k < 11; k++)
        {
            
            if(mapData[i][k] == "  ")
            {
                cout << " " << mapData[i][k];
                continue;
            }
           
            if(propertyLocations[stoi(mapData[i][k])][2] > 0)
            {
                

                if(propertyLocations[stoi(mapData[i][k])][2] == 1)
                {
                    //print red
                    // [0;31m	Red 

                    printf("\033[0;31m");
                    cout << " " << mapData[i][k];
                    printf("\033[0m");
                }
                if(propertyLocations[stoi(mapData[i][k])][2] == 2)
                {
                    //print in green
                    // [0;32m	Green
                    printf("\033[0;32m");

                    cout << " " << mapData[i][k];
                    printf("\033[0m");
                }
                if(propertyLocations[stoi(mapData[i][k])][2] == 3)
                {
                    //print in blue
                    // [0;34m	Blue

                    printf("\033[0;34m");
                    cout << " " << mapData[i][k];
                    printf("\033[0m");
                } 
                if(propertyLocations[stoi(mapData[i][k])][2] == 4)
                {
                    //print in magenta
                    // [0;35m	Magenta
                    
                    printf("\033[0;35m");
                    cout << " " << mapData[i][k];
                    printf("\033[0m");
                }
                if(propertyLocations[stoi(mapData[i][k])][2] == 5)
                {
                    //print in cyan
                    // [0;36m	Cyan

                    printf("\033[1;35m");
                    cout << " " << mapData[i][k];
                    printf("\033[0m");
                }
                if(propertyLocations[stoi(mapData[i][k])][2] == 6)
                {
                    //print in yellow
                    // [0;33m	Yellow

                    printf("\033[0;33m");
                    cout << " " << mapData[i][k];
                    printf("\033[0m");
                }                                      


            }
            else
            {
                cout << " " << mapData[i][k];
            }
            tempString = "";
        }
        cout << endl; 
    }
}

int Map::getPlayerLocation(int currentPlayer)
{
    return playerLocations[currentPlayer][0];
}

void Map::removePlayer(int numPlayers, int p)
{
    //remove their place from the board location
    propertyLocations[playerLocations[p][0]][2] -= 1;
    for(int i = p; i < numPlayers; i++)
    {
        playerLocations[i][0] = playerLocations[i+1][0];
        playerLocations[i][1] = playerLocations[i+1][1];
        playerLocations[i][2] = playerLocations[i+1][2];
    }   
}
