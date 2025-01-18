#pragma once
#include <iostream>
#include<string>
#include<vector>
#include<Windows.h>
#include<fstream>
#include"validation.h"
#include"client.h"
#include"employee.h"
#include"admin.h"
#include"datasourceinterface.h"
#define FIE_PATHADMIN "admin/admin.txt"
#define FIE_PATHCLIENT "client/client.txt"
#define FIE_PATHEMPLOYEE "employee/employee.txt"
using namespace std;
class implementdatasource :public datasourceinterface
{
public:
	//addadmin
	static void addadmin(string name, string password, int id, double salary) {
		ofstream myfile;
		myfile.open(FIE_PATHADMIN, ios::out | ios::app);
		myfile << name << "|";
		myfile << password << "|";
		myfile << id << "|";
		myfile << salary << "\n";
		myfile << "===============================" << "\n";
		myfile.close();
	}
	//addclient
	static void addclient(vector<Client>clients) {
		ofstream myfile2;
		myfile2.open(FIE_PATHCLIENT, ios::out | ios::app);
		for (Client c : clients) {
			myfile2 << c.get_name() << "|";
			myfile2 << c.get_password() << "|";
			myfile2 << c.get_id() << "|";
			myfile2 << c.getBalance() << "\n";
			myfile2 << "===============================" << "\n";
		}
		myfile2.close();
	}
	//addemployee
	static void addemployee(vector<Employee>employees) {
		ofstream myfile3;
		myfile3.open(FIE_PATHEMPLOYEE, ios::out | ios::app);
		for (Employee e : employees) {
			myfile3 << e.get_name() << "|";
			myfile3 << e.get_password() << "|";
			myfile3 << e.get_id() << "|";
			myfile3 << e.getSalary() << "\n";
			myfile3 << "===============================" << "\n";
		}
		myfile3.close();
	}
	//getclient
	static vector<Client> getallclients() {
		vector<Client>clienttemp;
		
	}
};