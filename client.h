#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "person.h"
#include "validation.h"
#include "colors.h"
#include <fstream>
using namespace std;

class Client : public Person {
private:
    double balance;

public:
    // Constructor
    Client() {
        balance = 0.0;
    }

    Client(string name, string password, double balance) : Person(name, password) {
        if (Validation::checkbalance(balance) == 1) {
            this->balance = balance;
        }
        else {
            colors::colortext();
            this->balance = 0;
            cout << "Invalid Balance" << "!\n";
            colors::aftercheck();
        }
    }

    Client(string name, int id, string password, double balance) : Person(name, password, id) {
        if (Validation::checkbalance(balance) == 1) {
            this->balance = balance;
        }
        else {
            colors::colortext();
            this->balance = 0;
            cout << "Invalid Balance" << "!\n";
            colors::aftercheck();
        }
    }

    // Setters and getters
    void setBalance(double balance) {
        if (Validation::checkbalance(balance) == 1) {
            this->balance = balance;
        }
        else {
            colors::colortext();
            this->balance = 0;
            cout << "Invalid Balance" << "!\n";
            colors::aftercheck();
        }
    }

    double getBalance() {
        return this->balance;
    }

    // Methods for depositing, withdrawing, and transferring money
    void Deposit(double amount) {
        balance += amount;
        cout << "You just deposited: " << amount << endl;
        cout << "Your Balance is: " << balance << endl;
        cout << "\n*********************\n" << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "You just withdrew: " << amount << endl;
            cout << "Your Balance is: " << balance << endl;
        }
        else {
            cout << "Insufficient balance" << endl;
        }
        cout << "\n*********************\n" << endl;
    }

    void TransferTo(double amount, Client& recipient) {
        if (amount <= balance) {
            recipient.balance+=amount;
            balance -= amount;
        }
        else {
            cout << "Amount exceeded" << endl;
            cout << "\n*********************\n" << endl;
        }
    }

    void CheckBalance() {
        cout << "Hello! .... Your Balance is: " << balance << endl;
        cout << "\n*********************\n" << endl;
    }

    void Display() {
        cout << "Client Information:\n";
        cout << "Name is: " << name << endl;
        cout << "ID is: " << id << endl;
        cout << "Password is: " << password << endl;
        cout << "Balance is: " << balance <<'$'<< endl;
        cout << "\n*********************\n" << endl;
    }
};
