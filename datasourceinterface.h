#pragma once
#include <iostream>
#include<string>
#include<vector>
#include"validation.h"
#include"client.h"
#include"employee.h"
#include"admin.h"
using namespace std;
class datasourceinterface
{
public:
	virtual void addclient(vector<Client> c) = 0;
	virtual void addemployee(vector<Employee> e) = 0;
	virtual void addadmin(vector<Admin> a) = 0;
	virtual vector<Client> getallclients() = 0;
	virtual vector<Employee> getallemployees() = 0;
	virtual vector<Admin> getalladmins() = 0;
	virtual void removeallclients() = 0;
	virtual void removeallemployees() = 0;
	virtual void removealladmins() = 0;
};

