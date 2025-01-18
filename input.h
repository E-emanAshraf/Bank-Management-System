#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <Windows.h>
#include <fstream>
#include "validation.h"
#include "person.h"
#include "client.h"
#include "employee.h"
#include "admin.h"
#include "colors.h"
#include "filehelper.h"
#include "implementdatasource.h"

using namespace std;

class Input
{
public:
    static void input() {
        /************************************************************/
        vector<Client> clients = FileHelper::readClientsFromFile("clients.txt");  // Read all clients
        vector<Employee> employees = FileHelper::readEmployeesFromFile("employees.txt");  // Read all employees
        Admin admin = FileHelper::readAdminFromFile("admin.txt");  // Read all admins
        string name, pass;
        bool found = false;
        int id = 0;
        id = FileHelper::readIDFromFile("id.txt");
        /*FileHelper::clearFile("id.txt");
        FileHelper::clearFile("employees.txt");
        FileHelper::clearFile("clients.txt");
        FileHelper::clearFile("admin.txt");*/
        Client client;
        Employee employee;
        string name1, pass1;
        int id1, position, choice=0, recipient_id,idx1,idx2,idx3;
        double balance = 0, salary = 0, amount;
        colors::aftercheck();
        /***********************************************************/
        cout << "Enter 1 for Admin, 2 for Client, and 3 for Employee\n";
        cout << "1) Admin\n";
        cout << "2) Client\n";
        cout << "3) Employee\n\n";
        cout << "Login as: ";
        cin >> position;
        system("cls");

        // For Admin
        if (position == 1) {
            bool checkc = false;
            while (!checkc) {
                cout << "Enter your password: ";
                cin >> pass1;
                if (pass1 == admin.get_password()) {
                    checkc = 1;
                    break;
                }
                if (!checkc) {
                    colors::colortext();
                    cout << "Invalid Password\n";
                    colors::aftercheck();
                }

            }
            while (choice != 11) {
                cout << "(1) Display my info\n";
                cout << "(2) Update Password\n";
                cout << "(3) Add new client\n";
                cout << "(4) Search for client\n";
                cout << "(5) List all clients\n";
                cout << "(6) Edit client info\n";
                cout << "(7) Add new Employee\n";
                cout << "(8) Search for Employee\n";
                cout << "(9) List all Employees\n";
                cout << "(10) Edit Employee info\n";
                cout << "(11) Logout\n\n";
                cout << "Your choice is: ";
                cin >> choice;
                system("cls");
                switch (choice) {
                case 1:
                    admin.display();  // Display admin's info (assuming there's only one admin)
                    break;
                case 2:
                    while (true) {
                        cout << "Enter your new password: ";
                        cin >> pass1;
                        if (Validation::checkpassword(pass1)) {
                            admin.set_password(pass1);  // Update admin's password
                            break;
                        }
                        colors::colortext();
                        cout << "Invalid Password" << "!\n";
                        colors::aftercheck();
                    }
                    break;
                case 3:
                    // Add new client functionality
                    while (true) {
                        cout << "Enter client name: ";
                        cin >> name;
                        cout << "Enter client password: ";
                        cin >> pass;
                        cout << "Enter client balance: ";
                        cin >> balance;
                        if (Validation::checkname(name) && Validation::checkpassword(pass) && Validation::checkbalance(balance)) {
                            client.set_name(name);
                            client.set_password(pass);
                            id++;
                            client.set_id(id);
                            client.setBalance(balance);
                            clients.push_back(client);
                            break;
                        }
                        if (!Validation::checkname(name)) {
                            colors::colortext();
                            cout << "Invalid Name" << "!\n";
                            cout << "Name must be 5 to 20 alphabetic characters" << "\n";
                            colors::aftercheck();
                        }
                        if (!Validation::checkpassword(pass)) {
                            colors::colortext();
                            cout << "Invalid Password" << "!\n";
                            colors::aftercheck();
                        }
                        if (!Validation::checkbalance(balance)) {
                            colors::colortext();
                            cout << "Invalid Balance" << "!\n";
                            colors::aftercheck();
                        }
                    }
                    break;
                case 4:
                    // Search for client
                    cout << "Enter client password: ";
                    cin >> pass;
                    found = false;
                    for (auto& c : clients) {
                        if (c.get_password() == pass) {
                            c.Display();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        colors::colortext();
                        cout << "Client not found\n";
                        colors::aftercheck();
                    }
                    break;
                case 5:
                    if (clients.empty()) {
                        colors::colortext();
                        cout << "No clients available." << endl;
                        colors::aftercheck();
                    }
                    else {
                        for (auto& c : clients) {
                            c.Display();
                        }
                    }

                    break;
                case 6:
                    // Edit client info
                    cout << "Enter client password to edit: ";
                    cin >> pass;
                    found = false;
                    for (int i = 0;i < clients.size();i++) {
                        if (clients[i].get_password() == pass) {
                            // Edit client info
                            while (true) {
                                cout << "Enter new balance: ";
                                cin >> balance;
                                if (Validation::checkbalance(balance)) {
                                    clients[i].setBalance(balance);
                                    break;
                                }
                                colors::colortext();
                                cout << "Invalid Balance" << "!\n";
                                colors::aftercheck();
                            }
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        colors::colortext();
                        cout << "Client not found\n";
                        colors::aftercheck();
                    }
                    break;
                case 7:
                    // Add new employee functionality
                    while (true) {
                        cout << "Enter employee name: ";
                        cin >> name;
                        cout << "Enter employee password: ";
                        cin >> pass;
                        cout << "Enter employee salary: ";
                        cin >> salary;
                        if (Validation::checkname(name) && Validation::checkpassword(pass) && Validation::checksalary(salary)) {
                            employee.set_name(name);
                            employee.set_password(pass);
                            id++;
                            employee.set_id(id);
                            employee.setSalary(salary);
                            employees.push_back(employee);
                            break;
                        }
                        if (!Validation::checkname(name)) {
                            colors::colortext();
                            cout << "Invalid Name" << "!\n";
                            cout << "Name must be 5 to 20 alphabetic characters" << "\n";
                            colors::aftercheck();
                        }
                        if (!Validation::checkpassword(pass)) {
                            colors::colortext();
                            cout << "Invalid Password" << "!\n";
                            colors::aftercheck();
                        }
                        if (!Validation::checksalary(salary)) {
                            colors::colortext();
                            cout << "Invalid Salary" << "!\n";
                            colors::aftercheck();
                        }
                    }
                    break;
                case 8:
                    // Search for employee
                    cout << "Enter employee password: ";
                    cin >> pass;
                    found = false;
                    for (auto& e : employees) {
                        if (e.get_password() == pass) {
                            e.display();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        colors::colortext();
                        cout << "employee not found\n";
                        colors::aftercheck();
                    }
                    break;
                case 9:
                    // List all employees functionality
                    if (employees.empty()) {
                        colors::colortext();
                        cout << "No employees available." << endl;
                        colors::aftercheck();
                    }
                    else {
                        for (auto& e : employees) {
                            e.display();
                        }
                    }
                    break;
                case 10:
                    // Edit employee info
                    cout << "Enter employee password to edit: ";
                    cin >> pass;
                    found = false;
                    for (int i = 0;i < employees.size();i++) {
                        if (employees[i].get_password() == pass) {
                            // Edit employee info
                            while (true) {
                                cout << "Enter new salary: ";
                                cin >> salary;
                                if (Validation::checksalary(salary)) {
                                    employees[i].setSalary(salary);
                                    break;
                                }
                                colors::colortext();
                                cout << "Invalid Salary" << "!\n";
                                colors::aftercheck();
                            }
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        colors::colortext();
                        cout << "Client not found\n";
                        colors::aftercheck();
                    }
                    break;
                case 11:
                    cout << "Logging out...\n";
                    break;
                default:
                    colors::colortext();
                    cout << "Invalid choice\n";
                    colors::aftercheck();
                    break;
                }
            }
        }
        // For Client
        else if (position == 2) {
            bool checkc = false;
            while (!checkc) {
                cout << "Enter your password: ";
                cin >> pass1;
                for (int i = 0;i < clients.size();i++) {
                    if (clients[i].get_password() == pass1) {
                        checkc = true;
                        idx1 = i;
                        break;
                    }
                }
                if (!checkc) {
                    colors::colortext();
                    cout << "Invalid Password\n";
                    colors::aftercheck();
                }
            }
            while (choice != 7) {
                cout << "(1) Display my info\n";
                cout << "(2) Check balance\n";
                cout << "(3) Update Password\n";
                cout << "(4) Withdraw\n";
                cout << "(5) Deposit\n";
                cout << "(6) Transfer amount\n";
                cout << "(7) Logout\n\n";
                cout << "Your choice is: ";
                cin >> choice;
                system("cls");

                switch (choice) {
                case 1:
                    // Display client info
                    clients[idx1].Display();
                    break;
                case 2:
                    // Check balance
                    clients[idx1].CheckBalance();
                    break;
                case 3:
                    // Update password logic for Client
                    while (true) {
                        cout << "Enter your new password: ";
                        cin >> pass1;
                        if (Validation::checkpassword(pass1)) {
                            clients[idx1].set_password(pass1);
                            break;
                        }
                        else {
                            colors::colortext();
                            cout << "Invalid Password\n";
                            colors::aftercheck();
                        }
                    }
                    break;
                case 4:
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    // Withdraw functionality
                    clients[idx1].withdraw(amount);
                    break;
                case 5:
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    // Deposit functionality
                    clients[idx1].Deposit(amount);
                    break;
                case 6:
                    cout << "Enter amount to transfer: ";
                    cin >> amount;
                    cout << "Enter id of recipient: ";
                    cin >> recipient_id;
                    for (int i = 0;i < clients.size();i++) {
                        if (clients[i].get_id() == recipient_id) {
                            idx2=i;
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        colors::colortext();
                        cout << "Invalid Id\n";
                        colors::aftercheck();
                    }
                    else {
                        // Transfer functionality
                        clients[idx1].TransferTo(amount, clients[idx2]);
                    }
                    break;
                case 7:
                    cout << "Logging out...\n";
                    break;
                default:
                    colors::colortext();
                    cout << "Invalid choice\n";
                    colors::aftercheck();
                    break;
                }
            }
        }
        // For Employee
        else if (position == 3) {
            bool checkc = false;
            while (!checkc) {
                cout << "Enter your password: ";
                cin >> pass1;
                for (int i = 0;i < employees.size();i++) {
                    if (employees[i].get_password() == pass1) {
                        checkc = true;
                        idx3 = i;
                        break;
                    }
                }
                if (!checkc) {
                    colors::colortext();
                    cout << "Invalid Password\n";
                    colors::aftercheck();
                }
            }
            while (choice != 7) {
                cout << "(1) Display my info\n";
                cout << "(2) Update Password\n";
                cout << "(3) Add new client\n";
                cout << "(4) Search for client\n";
                cout << "(5) List all clients\n";
                cout << "(6) Edit client info\n";
                cout << "(7) Logout\n\n";
                cout << "Your choice is: ";
                cin >> choice;
                system("cls");

                switch (choice) {
                case 1:
                    employees[idx3].display();  // Assuming display() shows employee info
                    break;
                case 2:
                    cout << "Enter your new password: ";
                    cin >> pass1;
                    employees[idx3].set_password(pass1); // Update password for Employee
                    break;
                case 3:
                    // Add new client functionality
                    while (true) {
                        cout << "Enter client name: ";
                        cin >> name;
                        cout << "Enter client password: ";
                        cin >> pass;
                        cout << "Enter client balance: ";
                        cin >> balance;
                        if (Validation::checkname(name) && Validation::checkpassword(pass) && Validation::checkbalance(balance)) {
                            client.set_name(name);
                            client.set_password(pass);
                            id++;
                            client.set_id(id);
                            client.setBalance(balance);
                            clients.push_back(client);
                            break;
                        }
                        if (!Validation::checkname(name)) {
                            colors::colortext();
                            cout << "Invalid Name" << "!\n";
                            cout << "Name must be 5 to 20 alphabetic characters" << "\n";
                            colors::aftercheck();
                        }
                        if (!Validation::checkpassword(pass)) {
                            colors::colortext();
                            cout << "Invalid Password" << "!\n";
                            colors::aftercheck();
                        }
                        if (!Validation::checkbalance(balance)) {
                            colors::colortext();
                            cout << "Invalid Balance" << "!\n";
                            colors::aftercheck();
                        }
                    }
                    break;
                case 4:
                    // Search for client
                    cout << "Enter client password: ";
                    cin >> pass;
                    found = false;
                    for (auto& c : clients) {
                        if (c.get_password() == pass) {
                            c.Display();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        colors::colortext();
                        cout << "Client not found\n";
                        colors::aftercheck();
                    }
                    break;
                case 5:
                    if (clients.empty()) {
                        colors::colortext();
                        cout << "No clients available." << endl;
                        colors::aftercheck();
                    }
                    else {
                        for (auto& c : clients) {
                            c.Display();
                        }
                    }

                    break;
                case 6:
                    // Edit client info
                    cout << "Enter client password to edit: ";
                    cin >> pass;
                    found = false;
                    for (int i = 0;i < clients.size();i++) {
                        if (clients[i].get_password() == pass) {
                            // Edit client info
                            while (true) {
                                cout << "Enter new balance: ";
                                cin >> balance;
                                if (Validation::checkbalance(balance)) {
                                    clients[i].setBalance(balance);
                                    break;
                                }
                                colors::colortext();
                                cout << "Invalid Balance" << "!\n";
                                colors::aftercheck();
                            }
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        colors::colortext();
                        cout << "Client not found\n";
                        colors::aftercheck();
                    }
                    break;
                case 7:
                    cout << "Logging out...\n";
                    break;
                default:
                    colors::colortext();
                    cout << "Invalid choice\n";
                    colors::aftercheck();
                    break;
                }
            }
        }
        else {
            colors::colortext();
            cout << "Invalid role selected.\n";
            colors::aftercheck();
        }


        FileHelper::writeClientsToFile(clients, "clients.txt");

        FileHelper::writeEmployeesToFile(employees, "employees.txt");

        FileHelper::writeIDToFile(id, "id.txt");

        FileHelper::writeAdminToFile(admin, "admin.txt");

    }

};
