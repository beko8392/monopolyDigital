# monopolyDigital
This is an independent project from CU Boulder's CSCI 1300 "Starting Computing" course, in collaboration with Charlotte Gorgemans. It is a command line-based digital version of the board game "Monopoly", with most features of the games (e.g. Cards, Bankruptcy, Property Ownership) included. 


Project 3 - CSCI 1300 
Instructions.txt
Benjamin Kohav
Charlotte Gorgemans 

<img width="428" alt="Screen Shot 2022-08-20 at 10 37 09 PM" src="https://user-images.githubusercontent.com/97623467/185775718-8f87c40f-25a5-408e-9eb2-71b48c712d2a.png">


I N S T R U C T I O N S

Welcome to our Monopoly Game! To compile, please follow the instructions below. We hope that you enjoy playing Monopoly!

1. Open a terminal tab, using toolbar above VS Code (Terminal -> New Terminal)
2. Check that the terminal run command is in the correct folder. 
3. If terminal command is not in the correct folder, input the following command:
    cd folderName
4. Compile monopolyDriver.cpp file and run the executable file by using the command below:
    g++ -std=c++11 Map.cpp Game.cpp Player.cpp Bank.cpp monopolyDriver.cpp Properties.cpp  && ./a.out
5. When the file has compiled and the game is in session, terminal will prompt user to input information and interact with 
   the game (i.e. input player name, player character, etc.). Please make sure to interact with the terminal and input 
   corresponding information. Enjoy! 
   
----------------
ABOUT THIS PROJECT 
----------------
This project is a digital version of the Monopoly game. Users, at least 3 and up to 6, interact with the terminal to play Monopoly.
----------------
HOW TO COMPILE AND RUN
----------------
Compile and Run: g++ -std=c++11 Map.cpp Game.cpp Player.cpp Bank.cpp monopolyDriver.cpp Properties.cpp && ./a.out

----------------
DEPENDENCIES
----------------
Bank.h, Bank.cpp, Game.h, Game.cpp, Map.h, Map.cpp, Player.h, Player.cpp, Properties.h, Properties.cpp, newProperty.txt, playerPosition.txt, monopolyDriver.cpp
must all be in the same directory in order to compile correctly.
