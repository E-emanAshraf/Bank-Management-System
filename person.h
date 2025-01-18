#pragma once
#include <iostream>
#include<string>
#include"validation.h"
#include"colors.h"
using namespace std;
class Person
{
protected:
	string name, password;
	int id;
public:
	//cons
	Person() {}

	Person(string name, string password) {
		if (Validation::checkname(name) == 1) {
			this->name = name;
		}
		else {
			colors::colortext();
			cout << "Invalid Name" << "!\n";
			cout << "Name must be 5 to 20 alphabetic characters" << "\n";
			colors::aftercheck();
		}
		if (Validation::checkpassword(password) == 1) {
			this->password = password;
		}
		else {
			colors::colortext();
			cout << "Invalid Password" << "!\n";
			colors::aftercheck();
		}
	}
	Person(string name, string password, int id) {
		this->id = id;
		if (Validation::checkname(name) == 1) {
			this->name = name;
		}
		else {
			colors::colortext();
			cout << "Invalid Name" << "!\n";
			cout << "Name must be 5 to 20 alphabetic characters" << "\n";
			colors::aftercheck();
		}
		if (Validation::checkpassword(password) == 1) {
			this->password = password;
		}
		else {
			colors::colortext();
			cout << "Invalid Password" << "!\n";
			colors::aftercheck();
		}
	}
	//methods
	void set_id(int id) {
		this->id = id;
	}
	int get_id() {
		return id;
	}
	void set_name(string name) {
		if (Validation::checkname(name) == 1) {
			this->name = name;
		}
		else {
			colors::colortext();
			cout << "Invalid Name" << "!\n";
			cout << "Name must be 5 to 20 alphabetic characters" << "\n";
			colors::aftercheck();
		}
	}
	string get_name() {
		return name;
	}
	void set_password(string password) {
		if (Validation::checkpassword(password) == 1) {
			this->password = password;
		}
		else {
			colors::colortext();
			cout << "Invalid Password" << "!\n";
			colors::aftercheck();
		}
	}
	string get_password() {
		return password;
	}
	~Person() {

	}
};

