#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "employee.h"
using namespace std;

class Admin : public Employee {
public:
    Admin() {}

    Admin(string admin_name, int admin_id, string admin_password, double admin_salary)
        : Employee(admin_name, admin_id, admin_password, admin_salary) {
    }

    void display() {
        cout << "Admin Information:\n";
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Password: " << password << endl;
        cout << "Salary: " << salary <<'$'<< endl;
        cout << "\n*********************\n" << endl;
    }
};
