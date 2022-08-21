//cs1300 Fall 2021
// Author: Benjamin Kohav & Charlotte Gorgemans
// Recitation: 116 - Alex Ray & 111 Tiffany Phan
// Project 3 -- monopolyDriver.cpp

//import libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>
#include <fstream>
#include "Game.h"

using namespace std;

/*
This function takes in a string with different phrases/numbers separated by a character, i.e. , or /
Paramaters: string text, char separator, string arr (to string a potential splitted string), size of the array (int)
Returns: the number pieces that the input "text" was split into (default is int).
*/

int split(string text, char separator, string arr[], int size)
{
    //variables initialized
    //numpieces that the original string is in. Initialized to one becuase there is originally one string. 
    int numPieces = 1;
    
    //starter keeps track of the current position within the string text.
    int starter = 0;
    
    //keeps track of where in the string array the function is. 
    int arrayCount = 0;
    
    //edge case if statement, if the original string is an empty string, in which case it returns 0.
    if(text == "")
    {
        return 0;
    }

    else
    {
        //for loop that lasts the length of string text
        for(unsigned int i = 0; i < text.length(); i++)
        {
            //if statement that checks if text[i] is equal to the delimiter, in which the string is split. 
            if(text[i] == separator)
            {
                //num pieces is increased becuase the string would theoretically be split now if the delimiter was found
                numPieces++;
                
                //if statement that checks if the new number of pieces would be longer than the string arr can store
                if(numPieces > size)
                {
                    arr[arrayCount] = text.substr(starter, i - starter);
                    return -1;
                    break;
                }
                //new string array is set to the substring that precedes the delimiter. 
                arr[arrayCount] = text.substr(starter, i - starter);
                arr[arrayCount+1] = text.substr((i+1),(text.length()-1-i));
                
                arrayCount++;
                starter =(i +1);
            }
        }
       
        //if the original string was never split, numPieces remains 1 and the arr[0] is set to the original string. 
        if(numPieces == 1)
        {
            arr[0] = text;
            return 1;
        }    
    }
    
    //numPieces is returned to the function call. 
    return numPieces;
}

/*
This function will fill an array of Properties objects.
Parameters: string filename, Object array[] props
Returns: nothing (void)
*/

void readProperties(string fileName, Properties props[30])
{
    int propertiesCount = 0;
    
    //ifstream declaration and open file
    ifstream myFile;
    
    myFile.open(fileName);

    //string propName, int cst, int mortgage, int loc, int rnt, int numHouse
    //location,name,cost,rent,mortgage,houseCost,numHouses

    //checks if file opened
    if(myFile.is_open())
    {
        string line = "";
        string temparr[7];
        Properties tempProp = Properties();
        
        //while loop that runs through each line of the text file and adds songs to the object array if there is space
        while(getline(myFile, line))
        {
            if(line.length() == 0)
            {
                continue;
            }
            //call split function
            split(line, ',', temparr, 7);
            
            //new object created
            props[propertiesCount] = Properties(stoi(temparr[0]), temparr[1], stoi(temparr[2]),stoi(temparr[3]),stoi(temparr[4]),stoi(temparr[5]),stoi(temparr[6]));
           
            propertiesCount++;
        }
    }

    //otherwise, print that the file wasn't opened correctly 
    else
    {
        cout << "file didn't open" << endl;
    }
}

/*
This function is the diceRoll function, using a rand() functions to generate 2 random numbers (between 1 and 6), simulating user's roll of two die.
Note: function must check if user rolls doubles 3 times in a row (if so, send player to jail)
Parameters: none (as this function will create the int values for dice roll on its own)
Return: void (since there are two dice values that need to be communicated to user, we use cout statements and pass by reference method to keep track of the values from both rolls)
*/

int diceRoll()
{
    //variable keeping track of the number of times doubles is rolled
    int doubles_counter = 0;

    //declare and initialize dice roll variables (will hold the value obtained from random number generators)
    int dice_roll1 = 0;
    int dice_roll2 = 0;

    //generate a random value between 1 and 6
    dice_roll1 = rand() % 6 + 1;
    dice_roll2 = rand() % 6 + 1;

    //checks and runs when number obtained from both dice rolls is the same.
    if (dice_roll1 == dice_roll2)
    { 
        while (dice_roll1 == dice_roll2)
        {
            //increment doubles counter 
            doubles_counter++;

            //if user rolled doubles 3 times, they are sent to jail.
            if (doubles_counter == 3)
            {
                cout << "You have rolled doubles 3 times - go to jail" << endl;
                cout << "Value of rolls: " << dice_roll1 << endl;
            }

            //if user rolls doubles less than 3 times, they can proceed with playing with the game normally (after rolling the dice again).
            if (doubles_counter < 3)
            {
                cout << "You have rolled doubles!" << endl;
                cout << "Value of rolls: " << dice_roll1 << ", " << dice_roll2 << endl;

                //roll dice again (avoids an infinite loop) and maintains game integrity
                dice_roll1 = rand() % 6 + 1;
                dice_roll2 = rand() % 6 + 1;
            } 
        }
    }

    //otherwise, print the value of the 1st and 2nd dice rolls
    else 
    {
        cout << "Value of 1st roll: " << dice_roll1 << endl;
        cout << "Value of 2nd roll: " << dice_roll2 << endl;
    }

    //create a variable holding the value of the two dice added together
    int final_roll = dice_roll1 + dice_roll2;

    //return final_roll.
    return final_roll;
}

/*
This function is the chanceCards function - a 2D array of good and bad chance cards. The function will call a random number generator -> 1-50 leads to "good" chance card array; 51-100 leads to "bad" chance card array.
Parameters: 2D array of chance cards
Return: N/A (void function)
*/

int readChanceCards(Game g1, int currentPlayer)
{
    //declare and initialize variable that will hold the value obtained from random number generator
    int rand_num = rand() % 51 + 1;

    //Chance array, first 25 chance cards are positive (i.e. add money to player's account), last 25 cards are negative (i.e. withdraw money from a player's account)
    
    //declare and initialize the chance array (contains all of the chance cards)
    string arrayChance[50][2]= {{"Life insurance matures. Collect $100", "100"},
    {"Bank error in your favor. Collect $200.", "200"},
    {"You have won second prize in a beauty contest. Collect $10.", "10"},
    {"XMAS fund matures. Collect $100.", "100"},
    {"Income tax refund. Collect $25.", "25"},
    {"You inherit $100.", "100"},
    {"From sale of stock you get $45.", "45"},
    {"Your building and loan matures. Collect $250.", "250"},
    {"Bank pays you dividend of $25.", "25"},
    {"Bank pays you dividend of $50.", "50"},
    {"Life insurance matures. Collect $100", "100"},
    {"Bank error in your favor. Collect $200.", "200"},
    {"You have won second prize in a beauty contest. Collect $10.", "10"},
    {"XMAS fund matures. Collect $100.", "100"},
    {"Income tax refund. Collect $25.", "25"},
    {"You inherit $100.", "100"},
    {"From sale of stock you get $45.", "45"},
    {"Your building and loan matures. Collect $250.", "250"},
    {"Bank pays you dividend of $25.", "25"},
    {"Bank pays you dividend of $50.", "50"},
    {"You won a debate against your opponent. Collect $45.", "45"},
    {"Electric car is a success! Collect $60.", "60"},
    {"Bank error in your favor. Collect $75.", "75"},
    {"You won first place at a beauty competition. Collect $55.", "55"},
    {"You inherit $350.", "350"},
    {"Doctors fee. Pay $50.", "50"},
    {"Pay school tax of $150.", "150"},
    {"Pay hospital $100.", "100"},
    {"Pay poor tax of $15.", "15"},
    {"Gambling debts due. Pay $35.", "35"},
    {"You are assessed for street repairs. Pay $10.", "10"},
    {"Bank error against your favor. Pay $200.", "200"},
    {"It's time to to buy house insurance. Pay $150.", "150"},
    {"You lost a bet. Pay $50.", "50"},
    {"Pay your mother's medical bills. $100 is due.", "100"},
    {"Pay for health insurance. $250 is due.", "250"},
    {"Your house has been broken into. Pay $50 for a new alarm system.", "50"},
    {"Pay a luxury tax of $150.", "150"},
    {"Pay a poor tax of $15.", "15"},
    {"Your stock has failed. Pay $45.", "45"},
    {"Pay the transportation tax. $100 is due.", "100"},
    {"Doctors fee. Pay $40.", "40"},
    {"Pay hospital $100.", "100"},
    {"Stock market crashes. Pay $300.", "300"},
    {"You lost your inheritance. Pay $250.", "250"}};
    
    //convert the value from string to integer
    int value = stoi(arrayChance[rand_num][1]);
   
    //if the random number generated is less than 25, then there is a good chance card for the user
    if (rand_num < 25)
    {
        // g1.depositFrom(currentPlayer,value);
        //print the chance card and that the money has been deposited into the respective player's bank account
        cout << arrayChance[rand_num][0] << endl;
        cout << "$" << value << " has been deposited to player's bank account." << endl;
    }
    //otherwise indicates that the player has not received a good chance card, they must pay a monetary penalty
    else
    {
        // g1.withdrawFrom(currentPlayer,value);
        cout << arrayChance[rand_num][0] << endl;
        cout << "$" << value << " has been removed from player's bank account." << endl;
        value = value*-1;
    }
    return value;
}

/*
This function is the isPropOwner function, a function that determines whether or not the user owns a property.
Parameters: boardLocation (integer), playerProps (a vector of type int)
Return: bool (true or 1 if user owns property, 0 or false if user does not own property)
*/

bool isPropOwner(int boardLocation, vector<int> playerProps)
{
    //declare and initialize the owner variable to 0 or false
    bool owner = 0;

    //for loop iterates through all of the components of the playerProps vector and finds whether or not the user owns a property
    for(int i = 0; i < playerProps.size(); i++)
    {
        if(playerProps[i] == boardLocation)
        {
            //if the user owns the property, set owner equal to 1.
            owner = 1;
        }
    }

    //return value of owner variable to main function
    return owner;
}


/*
This function is the orderOfPlayers() function, which SORTS the players in the round in order of bank balances and ADDS this information to a file
Parameters: fileName (string), the game object, the number of players in the round (numPlayers)
Return: no return value (void)
*/
void orderOfPlayers(string fileName,Game g1, int numPlayers)
{
    //create the arrays that store the values of players and their banks
    int originalSort[numPlayers][2];
    int sortedPlayers[numPlayers][2];

    //initialize the originalSort
    for(int i = 0; i < numPlayers; i++)
    {
        originalSort[i][0] = i;
        originalSort[i][1] = g1.getPlayer(i).getplayerBank().getBalance();
    }

    //have temporary variables to use as we loop through the original sort and find the maximums
    int tempMax;
    int tempMaxIndex;
    int rowAt = 0;
    for(int k = 0; k < numPlayers; k++)
    {
        tempMax = 0;
        for(int j = 0; j < numPlayers; j++)
        {
            if(originalSort[j][1] > tempMax)
            {
                tempMax = originalSort[j][1];
                tempMaxIndex = originalSort[j][0];
            }
            if(j == numPlayers - 1)
            {
                sortedPlayers[rowAt][1] = tempMax;
                sortedPlayers[rowAt][0] = tempMaxIndex;
                originalSort[tempMaxIndex][1] = 0;
                rowAt++;
            }
        }
        //print out the new "top" score as we find the order of players. 
        cout << k + 1 << " " << g1.getPlayer(sortedPlayers[k][0]).getName() << " $" << sortedPlayers[k][1] << endl;
    }

    //ofstream declarations
    ofstream outFile;

    outFile.open(fileName);

    //outfile that prints out in specific order the information about each players. 
    for(int x = 0; x < numPlayers; x++)
    {
        outFile << x + 1 << " " << g1.getPlayer(sortedPlayers[x][0]).getName() << " $" << sortedPlayers[x][1] << endl;
    }

}

//------> MAIN FUNCTION <-----
int main()
{
    //initialize the random seed (needed for diceRoll and random number generator functionality of the program)
    srand(time(NULL));
    
    //prior to starting the game, read the properties from the properties txt file
    //read Properties file (call the readProperties function)
    string fileName = "newProperty.txt";
    Properties props[30];
    readProperties(fileName, props);

    //declare the actualProperties array
    int actualProperties[40];

    //initialize each of the individual components of the actualProperties array
    actualProperties[0] = 0;
    actualProperties[1] = 0;
    actualProperties[2] = 0;
    actualProperties[3] = 1;
    actualProperties[4] = 0;
    actualProperties[5] = 2;
    actualProperties[6] = 3;
    actualProperties[7] = 0;
    actualProperties[8] = 4;
    actualProperties[9] = 5;
    actualProperties[10] = 0;
    actualProperties[11] = 6;
    actualProperties[12] = 7;
    actualProperties[13] = 8;
    actualProperties[14] = 9;
    actualProperties[15] = 10;
    actualProperties[16] = 11;
    actualProperties[17] = 0;
    actualProperties[18] = 12;
    actualProperties[19] = 13;
    actualProperties[20] = 0;
    actualProperties[21] = 14;
    actualProperties[22] = 0;
    actualProperties[23] = 15;
    actualProperties[24] = 16;
    actualProperties[25] = 17;
    actualProperties[26] = 18;
    actualProperties[27] = 19;
    actualProperties[28] = 20;
    actualProperties[29] = 21;
    actualProperties[30] = 0;
    actualProperties[31] = 22;
    actualProperties[32] = 23;
    actualProperties[33] = 0;
    actualProperties[34] = 24;
    actualProperties[35] = 25;
    actualProperties[36] = 0;
    actualProperties[37] = 26;
    actualProperties[38] = 0;
    actualProperties[39] = 27;

    //print to the user that they are entering game of Monopoly
    cout << "Welcome! Now entering M O N O P O L Y !" << endl;

    //ask for and get number of players
    cout << "Enter the number of players." << endl;
    int num_players;
    cin >> num_players;

    //validates user input
    while (num_players < 3 || num_players > 6)
    {
        cout << endl;
        
        //if inputted number of players is less than 3, print the statements below and reprompt for user input
        if (num_players < 3)
        {
            cout << "Invalid amount. There must be at least 3 players. Find a few more friends to play with!" << endl;
            cout << "Re-enter the number of players." << endl;
            cin >> num_players;
        }

        //if inputted number of players is greater than 6, print the statements below and reprompt for user input
        if (num_players > 6)
        {
            cout << "Invalid amount. There must be no more than 6 players. Have your friends start another game - they can play Monopoly when this group is finished!" << endl;
            cout << "Re-enter the number of players." << endl;
            cin >> num_players;
        }
    }

    //declare a map object
    Map newMap = Map(num_players);

    //declare player name variables
    string player_0;
    string player_1;
    string player_2;
    string player_3;
    string player_4;
    string player_5;

    //declare players and playerChar arrays, of type Player and char.
    Player players[6];
    char playerChar[6];

    //make a game object
    Game g1;
    
    //if there are 3 players...
    if (num_players == 3)
    {
        //Player 1: ask for and get name of player 1 and clear a player object for player 1.
        cout << "Enter a name for player 1" << endl;
        cin >> player_0; 
        players[0] = Player(player_0);

        //Player 2: ask for and get name of player 2 and clear a player object for player 2.
        cout << "Enter a name for player 2" << endl;
        cin >> player_1; 
        players[1] = Player(player_1);

        //Player 3: ask for and get name of player 3 and clear a player object for player 3.
        cout << "Enter a name for player 3" << endl;
        cin >> player_2; 
        players[2] = Player(player_2);

        //create game object based on our properties array, our players array, and Map object
        g1 = Game(players,props,newMap);
    }

    //if there are 4 players...
    if (num_players == 4)
    {
        //Player 1: ask for and get name of player 1 and clear a player object for player 1.
        cout << "Enter a name for player 1" << endl;
        cin >> player_0; 
        players[0] = Player(player_0);

        //Player 2: ask for and get name of player 2 and clear a player object for player 2.
        cout << "Enter a name for player 2" << endl;
        cin >> player_1; 
        players[1] = Player(player_1);
        
        //Player 3: ask for and get name of player 3 and clear a player object for player 3.
        cout << "Enter a name for player 3" << endl;
        cin >> player_2; 
        players[2] = Player(player_2);

        //Player 4: ask for and get name of player 4 and clear a player object for player 4.
        cout << "Enter a name for player 4" << endl;
        cin >> player_3; 
        players[3] = Player(player_3);

        //create game object based on our properties array, our players array, and Map object
        g1 = Game(players,props,newMap);
    }

    //if there are 5 players...
    if (num_players == 5)
    {
        //Player 1: ask for and get name of player 1 and clear a player object for player 1.
        cout << "Enter a name for player 1" << endl;
        cin >> player_0; 
        players[0] = Player(player_0);

        //Player 2: ask for and get name of player 2 and clear a player object for player 2.
        cout << "Enter a name for player 2" << endl;
        cin >> player_1; 
        players[1] = Player(player_1);

        //Player 3: ask for and get name of player 3 and clear a player object for player 3.
        cout << "Enter a name for player 3" << endl;
        cin >> player_2; 
        players[2] = Player(player_2);

        //Player 4: ask for and get name of player 4 and clear a player object for player 4.
        cout << "Enter a name for player 4" << endl;
        cin >> player_3; 
        players[3] = Player(player_3);

        //Player 5: ask for and get name of player 5 and clear a player object for player 5.
        cout << "Enter a name for player 5" << endl;
        cin >> player_4; 
        players[4] = Player(player_4);

        //create game object based on our properties array, our players array, and Map object
        g1 = Game(players,props,newMap);
    }

    //if there are 6 players...
    if (num_players == 6)
    {
        //Player 1: ask for and get name of player 1 and clear a player object for player 1.
        cout << "Enter a name for player 1" << endl;
        cin >> player_0; 
        players[0] = Player(player_0);

        //Player 2: ask for and get name of player 2 and clear a player object for player 2.
        cout << "Enter a name for player 2" << endl;
        cin >> player_1; 
        players[1] = Player(player_1);

        //Player 3: ask for and get name of player 3 and clear a player object for player 3.
        cout << "Enter a name for player 3" << endl;
        cin >> player_2; 
        players[2] = Player(player_2);

        //Player 4: ask for and get name of player 4 and clear a player object for player 4.
        cout << "Enter a name for player 4" << endl;
        cin >> player_3; 
        players[3] = Player(player_3);
        
        //Player 5: ask for and get name of player 5 and clear a player object for player 5.
        cout << "Enter a name for player 5" << endl;
        cin >> player_4; 
        players[4] = Player(player_4);

        //Player 6: ask for and get name of player 6 and clear a player object for player 6.
        cout << "Enter a name for player 6" << endl;
        cin >> player_5; 
        players[5] = Player(player_5);

        //create game object based on our properties array, our players array, and Map object
        g1 = Game(players,props,newMap); 
    }

    //declare and initialize variables needed to keep track of the rounds, and to run the game correctly
    int originalNumPlayers = num_players;
    char game_status = 'C';
    int currentPlayer = 0;
    int mapPosition;
    char property_buy;
    int propertyOwner;
    string fileName2 = "playerPosition.txt";
    int chanceValue;

    //all the variables being used in the game.
    int jail_action;
    char purchase_input;
    int amount = 0; 
    char sell_property;
    int property_action;

    //print a statement prior to while loop, informing user that the game is starting
    cout << "Now beginning Monopoly! It's now the first player's turn." << endl;
    g1.getMap().displayMap(num_players);

    //print a map key
    cout << "Map Key: " << endl;
    cout << "If there is one player on a map position, that position shows as red." << endl;
    cout << "If there are two players on a map position, that position shows as green." << endl;
    cout << "If there are three players on a map position, that position shows as blue." << endl;
    cout << "If there are four players on a map position, that position shows as magenta." << endl;
    cout << "If there are five players on a map position, that position shows as cyan." << endl;
    cout << "If there are six players on a map position, that position shows as yellow." << endl;


    //GAME LOOP
    //this while loop runs the game
    while (num_players != 1 && game_status != 'q' && game_status != 'Q')
    {
        cout << endl;

        // if (person is in jail) would be represented by some bool value
        //if statement acts if the person is in jail
        if(g1.getPlayer(currentPlayer).getJail() == 1)
        {
            cout << endl;
            //print menu of actions user can take if in jail
            cout << "You are currently in jail. You can take 1 of 2 actions:" << endl;
            cout << "1. Pay the $50 fine to be released from jail." << endl;
            cout << "2. Take no action. You will remain in jail until you take one of the actions stated above." << endl;

            //prompt user to input an integer indicating which action they would like to take
            cout << "Which action would you like to take?" << endl;
            cout << "Input '1' for action 1, '2' for action 2." << endl;

            //get user input
            cin >> jail_action;

            //checks for invalid input: prints that the input is invalid, asks for and gets new user input. Repeat while loop until user inputs a valid integer.
            while (jail_action != 1 && jail_action != 2)
            {
                cout << endl;
                cout << "Invalid input. Try again." << endl;

                cout << "Which action would you like to take?" << endl; 
                cout << "Input 1 or 2" << endl;
                        
                cin >> jail_action;
            }

            //if the user chooses to pay the penalty, release player from jail and print a statement informing the user of this action
            if(jail_action == 1)
            {
                g1.withdrawFrom(currentPlayer,50);
                g1.takeOutOfJail(currentPlayer);
                cout << "You're out of jail! Try not to come back :)" << endl;
            }
        }


        //print a statement with the player's name, indicating to players who is playing.
        cout << "It's " << g1.getPlayer(currentPlayer).getName() << "'s turn! Rolling Dice..." << endl;

        //call the dice roll function and store the roll obtained in a temporary variable named dice_temp
        int dice_temp = diceRoll();
        
        //print the roll
        cout << "Your roll is " << dice_temp << endl;
        
        //print statement indicating that the player is being moved x steps
        cout << "Moving " << g1.getPlayer(currentPlayer).getName() << " " << dice_temp << " steps..." << endl;
        cout << endl;

        //execute move, call the map class
        // mapPosition = g1.getMap().executeMove(currentPlayer,dice_temp); //ADD player number
        mapPosition = g1.movePlayer(currentPlayer, dice_temp);
        g1.getMap().displayMap(num_players);
        cout << endl;

        //**Please, note some special locations in our version:**
            // - 0, go
            // - 2, chance
            // - 4, tax
            // - 10, Jail
            // - 17, chance
            // - 20 free parking
            // - 22, chance
            // - 30, go to jail
            // - 33, chance
            // - 36, chance
            // - 38, income tax

        // check if person is in chance card location, free parking or jail, have the if statements below be nested
        if(mapPosition == 10 || mapPosition == 0 || mapPosition == 2 || mapPosition == 4 || mapPosition == 17 || mapPosition == 20 || mapPosition == 22 || mapPosition == 30 || mapPosition == 33 || mapPosition == 36 || mapPosition == 38 || mapPosition ==7)
        {
            //print that the user has printed on one of the special positions detailed above
            cout << "You have landed on a special position!" << endl;
           
            //if the user lands on a chance card spot... 
            if(mapPosition == 2 || mapPosition == 17 || mapPosition == 22 || mapPosition == 33 || mapPosition == 36 || mapPosition == 7) 
            {
                //print an empty line and then call the chance card function
                cout << endl;
                chanceValue = readChanceCards(g1, currentPlayer);
                g1.depositFrom(currentPlayer,chanceValue);

                //print out the player's balance. Update the player's balance.
                cout << "Your new balance is $" << g1.getPlayer(currentPlayer).getplayerBank().getBalance() << endl;
            }

            //print that the user has landed on the visiting jail position. The user is safe at this point.
            if(mapPosition == 10)
            {
                cout << "You are visiting Jail! Stay out of trouble. No penalties or advantages have been occurred. Enjoy your time off!" << endl;
            }

            //print that the user has landed in the free parking spot. The user is safe and receives no penalties or advantages.
            if (mapPosition == 20)
            {
                cout << endl;
                cout << "You are in free parking. No penalties or advantages have been occurred. Enjoy your time off!" << endl;
            }

            //the user has landed on the go to jail spot. Print that the user has landed on jail and update player's status to be in jail.
            if (mapPosition == 30)
            {
                cout << endl;
                cout << "You have landed on the 'Go to Jail' spot. You are now in Jail." << endl;
                cout << "To get out of jail, you must 1. roll doubles OR 2. Pay a $50 fee." << endl;
                cout << "You are eligible to perform one of the actions above on your next turn." << endl;

                //send the user to jail
                g1.sendToJail(currentPlayer);
            }

            //user has passed go. add $200 to player's bank account and print a statement to the player indicating that they have passed go.
            if (mapPosition == 0)
            {
                cout << endl;
                cout << "You have passed Go! A $200 bonus has been added to your bank account." << endl;

                g1.playerPassGo(currentPlayer);
            }
         
            //player has landed on a spot that asks for a tax. print this to user and update bank account after the 10% deduction has been made.
            if (mapPosition == 4 || mapPosition == 38)
            {
                cout << "You are on a tax position! A 10 percent deduction has been taken to your bank account." << endl;

                g1.playerTaxes(currentPlayer);
                cout << "Your new balance is $" << g1.getPlayer(currentPlayer).getplayerBank().getBalance() << endl;
            }
        }
        
        //otherwise the user has landed on a normal property
        else
        {   
            //print the property that user has landed on
            cout << "You have landed on: " << g1.getPropertyNameAt(actualProperties[mapPosition]) << endl;

            //check if the house is owned
            if ((g1.getProperty(actualProperties[mapPosition]).Owner() == 1)&&(isPropOwner(actualProperties[mapPosition], g1.getPlayer(currentPlayer).getPlayerProps())==1))//and current Player is owner
            {
                //print the menu of options the user can take if they own the property
                cout << endl;
                cout << "You own this property. You have 2 actions you can take: " << endl;
                cout << "1. Add a hotel" << endl;
                cout << "2. Keep property, do nothing." << endl;

                //get the action that the user wishes to take
                cin >> property_action;

                //validate user input
                while (property_action != 1 && property_action != 2)
                {
                    cout << endl;
                    cout << "Invalid input. Try again." << endl;

                    cout << "You own this property. You have 2 actions you can take: " << endl;
                    cout << "1. Add a hotel" << endl;
                    cout << "2. Keep property, do nothing." << endl;            
                    cin >> property_action;                            
                }

                //if user selects first option, print statement below and add a house. Additionally, change the cost and rent of the property.
                if(property_action == 1)
                {
                    cout << "Adding Hotel to " << g1.getPropertyNameAt(actualProperties[mapPosition]) << " and adjusting property value and rent..." << endl;
                    g1.getProperty(mapPosition).addHouse();
                    cout << "New Cost: $" << g1.getProperty(actualProperties[mapPosition]).getPropertyCost() << endl; 
                    cout << "New Rent: $" << g1.getProperty(actualProperties[mapPosition]).getRent() << endl;
                }

                //if user inputs second option, user has decided to keep their property and do nothing at this time.
                if(property_action == 2)
                {
                    cout << "You have chosen to keep your property. No further actions will be taken at this time." << endl;
                }

                //update property action variable to 0. (to update for the next time this if statement runs)
                property_action = 0;
            }

            //if we checked the current players properties and they did not have it, then check the others, until the owner is found, and set int owner equal to that player number. 
            if ((g1.getProperty(actualProperties[mapPosition]).Owner() == 1)&&(isPropOwner(actualProperties[mapPosition], g1.getPlayer(currentPlayer).getPlayerProps())==0)) //and NOT in current players properties. 
            {
                //print that the user has landed on someone else's property
                cout << endl;
                cout << "You have landed on a property that is owned by another player in the game." << endl;
                cout << "You must pay rent." << endl;
                
                //get the rent for that property and print it.
                amount = g1.getProperty(actualProperties[mapPosition]).getRent();
                cout << "Withdrawing $" << amount << " from your bank account..." << endl;
                
                //withdraw and deposit the corresponding amounts
                g1.withdrawFrom(currentPlayer,amount);
                cout << "Your new balance is $" << g1.getPlayer(currentPlayer).getplayerBank().getBalance() << endl;
                cout << endl;
            
                //deposit value of rent into owner's account. Update account accordingly.
                propertyOwner = g1.findPropOwner(num_players, actualProperties[mapPosition]);

                g1.depositFrom(propertyOwner,amount);
                
                //ask user if they want to purchase the owner's property
                cout << "Ask to purchase this property from owner?" << endl; 
                cout << "Input 'Y' for yes and 'N' for no." << endl;

                //get user input
                cin >> purchase_input;

                //validate user input, reprint options and reprompt for user input
                while (purchase_input != 'Y' && purchase_input != 'y' && purchase_input != 'N' && purchase_input != 'n')
                {
                    cout << endl;
                    cout << "Invalid input. Try again." << endl;
                    
                    cout << "Ask to purchase this property from owner?" << endl; 
                    cout << "Input 'Y' for yes and 'N' for no." << endl;
                    cin >> purchase_input;
                }

                //if user inputs Y or y, print the menu below.
                if (purchase_input == 'Y' || purchase_input == 'y')
                {
                    cout << endl;
                    cout << "Pass computer to player." << endl;
                    cout << "Player would like to purchase your property. Would you like to sell your property?" << endl;
                    cout << "If you agree to selling your property, input 'Y'. If you would like to keep your property, input 'N'." << endl;
                    
                    //get user input
                    cin >> sell_property;
                    
                    //validate user input, reprint menu and reprompt for user input
                    while (sell_property != 'y' && sell_property != 'Y' && sell_property != 'n' && sell_property != 'N')
                    {
                        cout << endl;
                        cout << "Invalid input. Try again." << endl;
                        cout << "Would you like to sell this property?" << endl; 
                        cout << "Input 'Y/y' for yes and 'N/n' for no." << endl;
                        
                        cin >> sell_property;
                    }

                    //if user inputs y or Y, print the statements below
                    if (sell_property == 'y' || sell_property == 'Y')
                    {
                        //call the sell property function CHECK THIS!!!!!!
                        //remove property from owner's properties. 
                        //remove the property from original owner's property vector.
                        g1.removePropertyFrom(propertyOwner,mapPosition);
                        //add property to current player's properties. 
                        g1.addPropertyTo(currentPlayer,actualProperties[mapPosition]);


                        cout << endl;
                        cout << "You have chosen to sell your property." << endl;
                        cout << "Property has been sold." << endl;
                    }

                    //otherwise, the user does not want to sell their property. Keep everything as normal.
                    else 
                    {
                        cout << endl;
                        cout << "You have chosen to not sell your property. No further actions will be taken at this time." << endl;
                    }
                }

                //otherwise, the player does not want to purchase the property, print statement below and continue game.
                else 
                {
                    cout << "You do not want to purchase this player's property. Rent has been paid to the player, and no further actions will be taken at this time." << endl;
                }
            }

            //if the property is not owned by anyone...
            if (g1.getProperty(actualProperties[mapPosition]).Owner() == 0)
            {
                //print an empty line and that the property is not owned by anyone. Print this menu of options.
                cout << endl;
                cout << "This property is not owned by anyone. Would you like to purchase this property?" << endl;
                cout << "The property cost is $" << g1.getProperty(actualProperties[mapPosition]).getPropertyCost() << endl;
                cout << "Input 'Y' if you would like to buy this property. Input 'N' if you do not wish to buy this property." << endl;

                //get user input.
                cin >> property_buy;

                //check for valid user input, print statements below and reprompt user input
                while (property_buy != 'y' && property_buy != 'Y' && property_buy != 'n' && property_buy != 'N')
                {
                    cout << endl;
                    cout << "Invalid input. Try again." << endl;
                    
                    cout << "Would you like to purchase this property?" << endl; 
                    cout << "Input 'Y' for yes and 'N' for no." << endl;
                    cin >> property_buy;
                } 

                //if user wants to purchase the property...
                if (property_buy == 'y' || property_buy == 'Y')
                {
                    //if they want to buy it, but don't have the correct amount of money, print that they don't have enough money
                    if(g1.getPlayer(currentPlayer).getplayerBank().getBalance() < g1.getProperty(actualProperties[mapPosition]).getPropertyCost())
                    {
                        cout << endl;
                        cout << "You do not have enough money to purchase this property. Maybe next round!" << endl;
                    }

                    //otherwise, user has enough money to purchase the property
                    else
                    {
                        cout << endl;
                        
                        //purchase the property
                        cout << "You have opted to purchase this property." << endl;
                        cout << "This property costs $" << g1.getProperty(actualProperties[mapPosition]).getPropertyCost() << endl;
                        cout << g1.getProperty(actualProperties[mapPosition]).getPropertyCost() << "$ amount will be withdrawn from your bank account." << endl;
                        
                        //withdraw the money, set the owner bool to 1, and add the location to the player's property vector
                        g1.withdrawFrom(currentPlayer,g1.getProperty(actualProperties[mapPosition]).getPropertyCost());
                        
                        //deposit money into seller's account and print their new balance.
                        cout << g1.getPlayer(currentPlayer).getName() << "'s new Balance is $" << g1.getPlayer(currentPlayer).getplayerBank().getBalance() << endl;
                        
                        //remove the property from original owner's property vector.
                        g1.addPropertyTo(currentPlayer,actualProperties[mapPosition]);
                        
                        //add the property to the owner's list of properties
                        g1.addOwnerTo(actualProperties[mapPosition]);
                        cout << "Congratulations! You have officially purchased this property." << endl;
                    }
                }

                //otherwise, user does not wish to sell the property
                else 
                {
                    cout << endl;
                    cout << "You have opted to not purchase this property. No further actions will be taken at this time." << endl;
                }
            }
        }

        //check player balance: if player has a balance that is less than or equal to 0...
        if(g1.getPlayer(currentPlayer).getplayerBank().getBalance() <= 0)
        {
            //print menu below.
            cout << endl;
            cout << "Oh no! You have gone bankrupt - your bank account indicates that you have $0 or debts due." << endl;
            cout << "You have lost the game, and will be taken out of the game." << endl;
            //remove player object
            //remove player from array of players (keep order of the rest of players)
            g1.removePlayer(num_players, currentPlayer);
            
            //remove player's character from array char.
            for(int i = currentPlayer; i < num_players; i++)
            {
                playerChar[i] = playerChar[i+1];
            }            
            
            //remove player's information from the map player information.
            originalNumPlayers--;
            num_players--;
        }

        //Call the sorting function

        //print that the current player's turn is over. Ask if players want to continue playing.
        cout << endl;
        cout << g1.getPlayer(currentPlayer).getName() << "'s turn is now over. Continue playing?" << endl;
        cout << "If you'd like to continue playing, input 'c'. If you would like to quit playing this Monopoly game, input 'q'." << endl;
        
        //get user input
        cin >> game_status;

        //validate user input
        while (game_status != 'c' && game_status != 'q')
        {
            cout << endl;
            cout << "Invalid input. Try Again." << endl;
            cout << "Would you like to continue playing?" << endl; 
            cout << "Input 'c' to continue or 'q' to stop playing" << endl;
                            
            cin >> game_status;
        }

        //if user inputs q, quit playing monopoly game.
        if (game_status == 'q')
        {
            cout << endl;
            cout << "You have opted to quit playing Monopoly. " << endl;
            cout << "Final Player Standings : " << endl;
            orderOfPlayers(fileName2, g1, num_players);            
            break;
        }

        //otherwise, print that the user will continue playing the monopoly
        else 
        {
            cout << "You have opted to continue playing Monopoly. Pass the computer to the next player." << endl;
        }


        if(currentPlayer == num_players-1)//num_players. 
        {
            //sorting function. 
            cout << "End of Round! Player Standings: " << endl;
            orderOfPlayers(fileName2,g1, num_players);            
            currentPlayer = 0;
        }
        
        //otherwise, increment currentPlayer variable
        else
        {
            currentPlayer++;
        }
    }
    
    return 0;
}