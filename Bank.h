//cs1300 Fall 2021
// Author: Benjamin Kohav & Charlotte Gorgemans
// Recitation: 116 - Alex Ray & 111 Tiffany Phan
// Project 3 -- BANK.h


#ifndef BANK_H // preprocessor directives
#define BANK_H

#include <string>
#include <iostream>

using namespace std;

class Bank
{
    public: 
    //constructor (default) -> no need for a parameterized constructor as every player is given the same original balance to begin with
    Bank();

    //getters
    double getBalance();

    //setters -> withdraw, deposit, passGo, payTaxes
    void withdraw(double w);
    void deposit(double d);
    void passGo();
    void payTaxes();

    //private, inaccessible areas of Property class.
    //balance is the only variable in the private class
    private:
    double balance;
};

#endif