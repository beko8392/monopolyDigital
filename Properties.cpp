//cs1300 Fall 2021
// Author: Benjamin Kohav & Charlotte Gorgemans
// Recitation: 116 - Alex Ray & 001 Tiffany Phan
// Project 3 -- properties.cpp

#include "Properties.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std; 

    //default constructor
    Properties::Properties()
    {
        propertyName = "";
        cost = 0;
        mortgageVal = 0;
        location = 0;
        rent = 0;
        numHouses = 0;   
        houseCost = 0; 
        isOwned = 0;   
    }

    //parameterized constructor
    Properties::Properties(int loc, string propName, int cst, int rnt,int mortgage, int houseCst, int numHouse)
    {
        propertyName = propName;
        cost = cst;
        mortgageVal = mortgage;
        location = loc;
        rent = rnt;
        numHouses = numHouse; 
        houseCost = houseCst;
        isOwned = 0;         
    }

    //getters
    //returns propertyName
    string Properties::getPropertyName()
    {
        return propertyName;
    }

    //returns cost
    int Properties::getPropertyCost()
    {
        return cost;
    }

    //returns mortgageVal
    int Properties::getMortgageValue()
    {
        return mortgageVal;
    }

    //returns location
    int Properties::getLocation()
    {
        return location;
    }

    //returns rent
    int Properties::getRent()
    {
        return rent;
    }

    //returns numHouses
    int Properties::getNumHouses()
    {
        return numHouses;
    }

    //returns isOwned
    bool Properties::Owner()
    {
        return isOwned;
    }

    //setters
    //sets propertyName to n
    void Properties::setPropertyName(string n)
    {
        propertyName = n;
    }

    //sets mortgageVal to m
    void Properties::setMortgage(int m)
    {
        mortgageVal = m;
    }

    //sets cost to c
    void Properties::setPropertyCost(int c)
    {
        cost = c;
    }

    //sets rent to r
    void Properties::setRent(int r)
    {
        rent = r;
    }

    //sets location to l
    void Properties::setLocation(int l)
    {
        location = l;
    }

    //sets numHouses to h
    void Properties::setNumHouses(int h)
    {
        numHouses = h;
    }

    //increments numHouses by 1
    void Properties::addHouse()
    {
        numHouses++;
        cost += houseCost;
        int tempIncrease = 0.1 * cost;
        rent += tempIncrease;
    }

    //sets isOwned to 1 (true)
    void Properties::newOwner()
    {
        isOwned = 1;
    }

