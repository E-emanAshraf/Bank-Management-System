#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "client.h"
#include "employee.h"
#include "admin.h"

using namespace std;

class FileHelper {
public:
    // Write a vector of clients to a file (using text format instead of binary)
    static void writeClientsToFile(const vector<Client>& clients, const string& filename) {
        ofstream outfile(filename);
        if (!outfile) {
            return;
        }

        for (auto client : clients) {
            outfile << client.get_name() <<" "<<client.get_id()<< " " << client.get_password() <<" "<<client.getBalance()<< endl;
        }

        outfile.close();
    }

    // Read all clients from a file and return them as a vector (text file format)
    static vector<Client> readClientsFromFile(const string& filename) {
        vector<Client> clients;
        ifstream infile(filename);
        if (!infile) {
            return clients;
        }

        string name, pass;
        int id;
        double balance;
        while (infile >> name >> id >> pass>>balance) {
            Client client;
            client.set_name(name);
            client.set_password(pass);
            client.set_id(id);
            client.setBalance(balance);
            clients.push_back(client);
        }

        infile.close();
        return clients;
    }

    // Write a vector of employees to a file (using text format instead of binary)
    static void writeEmployeesToFile(const vector<Employee>& employees, const string& filename) {
        ofstream outfile(filename);
        if (!outfile) {
            return;
        }

        for (auto employee : employees) {
            outfile << employee.get_name() << " " <<employee.get_id()<<" "<< employee.get_password() <<" "<<employee.getSalary()<< endl;
        }

        outfile.close();
    }

    // Read all employees from a file and return them as a vector (text file format)
    static vector<Employee> readEmployeesFromFile(const string& filename) {
        vector<Employee> employees;
        ifstream infile(filename);
        if (!infile) {
            return employees;
        }

        string name, pass;
        int id;
        double salary;
        while (infile >> name >> id >> pass >> salary) {
            Employee employee;
            employee.set_name(name);
            employee.set_id(id);
            employee.setSalary(salary);
            employee.set_password(pass);
            employees.push_back(employee);
        }

        infile.close();
        return employees;
    }

    // Write admin data to a file (using text format instead of binary)
    static void writeAdminToFile(Admin& admin, const string& filename) {
        ofstream outfile(filename);
        if (!outfile) {
            return;
        }

        outfile << admin.get_name() << " "<<admin.get_id()<<" " << admin.get_password() <<" "<<admin.getSalary() << endl;

        outfile.close();
    }

    //id for each person
    static void writeIDToFile(int id, const string& filename) {
        ofstream outfile(filename);
        if (!outfile) {
            return;
        }

        outfile << id;

        outfile.close();
    }
    //read id from file
    static long long readIDFromFile(const string& filename) {
        int id=0;
        ifstream infile(filename);
        if (!infile) {
            return id;
        }

        infile >>id ;
        infile.close();
        return id;
    }


    // Read admin data from a file (text format)
    static Admin readAdminFromFile(const string& filename) {
        Admin admin;
        ifstream infile(filename);
        if (!infile) {
            return admin;
        }

        string name, pass;
        int id;
        double salary;
        infile >> name >>id>> pass>>salary;
        admin.set_name(name);
        admin.set_password(pass);
        admin.set_id(id);
        admin.setSalary(salary);
        infile.close();
        return admin;
    }

    // Clear a file by opening it in truncation mode
    static void clearFile(const std::string& filename) {
        ofstream outfile(filename, ios::trunc);
        if (!outfile) {
            return;
        }

        // File is now cleared (empty)
        outfile.close();
    }
};
