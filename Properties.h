//cs1300 Fall 2021
// Author: Benjamin Kohav & Charlotte Gorgemans
// Recitation: 116 - Alex Ray & 001 Tiffany Phan
// Project 3 -- properties.h

#ifndef PROPERTIES_H // preprocessor directives
#define PROPERTIES_H

#include <string>
#include <iostream>

using namespace std;

class Properties
{
    public: 
    //default constructor
    Properties();

    //parameterized constructor
    Properties(int loc, string propName, int cst, int rnt,int mortgage, int houseCst, int numHouse);

    //getters (detailed explanations are in the comments within properties.cpp)
    string getPropertyName();
    int getPropertyCost();
    int getMortgageValue();
    int getLocation();
    int getRent();
    int getNumHouses();
    bool Owner();

    //setters (detailed explanations are in the comments within properties.cpp)
    void setPropertyName(string n);
    void setMortgage(int m);
    void setPropertyCost(int c);
    void setRent(int r);
    void setLocation(int l);
    void setNumHouses(int h);
    void addHouse();
    void newOwner();

    //private, inaccessible areas of Property class.
    private:
    string propertyName;
    int cost;
    int mortgageVal;
    int location;
    int rent;
    int numHouses;
    int houseCost;
    bool isOwned;
};

#endif