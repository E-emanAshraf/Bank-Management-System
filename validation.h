#pragma once
#include <iostream>
#include<string>
#include<Windows.h>
using namespace std;
class Validation {
public:
	//checkname
	static bool checkname(string input_name) {
		bool flag = 0;
		if (input_name.size() >= 5 && input_name.size() <= 20) {
			for (int i = 0;i < input_name.size();i++) {
				if ((input_name[i] >= 'a' && input_name[i] <= 'z') || ((input_name[i] >= 'A' && input_name[i] <= 'Z'))) {
					continue;
				}
				else {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1 || input_name.size() < 5 || input_name.size() > 20) {
			return 0;
		}
		else {
			return 1;
		}
	}
	//checkpassword
	static bool checkpassword(string input_password) {
		if (input_password.size() < 8 || input_password.size() > 20) {
			return 0;
		}
		else {
			return 1;
		}
	}
	//chackbalane
	static bool checkbalance(double input_balance) {
		if (input_balance < 1500) {
			return 0;
		}
		else {
			return 1;
		}
	}
	//checksalary
	static bool checksalary(double input_salary) {
		if (input_salary < 5000) {
			return 0;
		}
		else {
			return 1;
		}
	}
};

