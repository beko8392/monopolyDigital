//cs1300 Fall 2021
// Author: Benjamin Kohav & Charlotte Gorgemans
// Recitation: 116 - Alex Ray & 111 Tiffany Phan
// Project 3 -- Bank.cpp

#include "Bank.h"
#include <string>
#include <iostream>
#include <cmath>


    //default constructor
    Bank::Bank()
    { 
        //set each player's balance to be 1500.
        balance = 1500;
    }
    
    //parameterized constructor - no need for a parameterized constructor as the default is the original amount that each player has to start anyone

    //getter -> get the balance
    double Bank::getBalance()
    {
        return balance;
    }

    //setters -> withdraw, deposit, passGo, and payTaxes functions
    void Bank::withdraw(double w)
    {
        //update balance variable.
        balance = balance - w;
    }

    void Bank::deposit(double d)
    {
        //update balance variable.
        balance = balance + d;
    }

    void Bank::passGo()
    {
        //update balance.
        balance+=200;
    }

    void Bank::payTaxes()
    {
        //declare and initialize the tax variable.
        double tax = balance * 0.10;
        
        //update balance variable.
        balance = balance - tax;
    }