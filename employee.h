#pragma once
#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<cmath>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<Windows.h>
#include"person.h"
#include"validation.h"
#include"colors.h"
#include"client.h"
using namespace std;
class Employee : public Person {
protected:
    double salary;
    vector<Client> clients;

public:
    Employee() : salary(0.0) {}

    Employee(string n, int i, string p, double s) : Person(n, p, i) {
        if (Validation::checksalary(s)) {
            salary = s;
        }
        else {
            colors::colortext();
            salary = 0;
            cout << "Invalid Salary!\n";
            colors::aftercheck();
        }
    }

    void setSalary(double s) {
        if (Validation::checksalary(s)) {
            salary = s;
        }
        else {
            colors::colortext();
            salary = 0;
            cout << "Invalid Salary!\n";
            colors::aftercheck();
        }
    }

    double getSalary() { return salary; }

    void display() {
        cout << "Employee Information:\n";
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Password: " << password << endl;
        cout << "Salary: " << salary <<'$'<< endl;
        cout << "\n*********************\n" << endl;
    }
};
