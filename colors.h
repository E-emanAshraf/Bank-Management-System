#pragma once
#include <iostream>
#include<string>
#include<vector>
#include<Windows.h>
using namespace std;
class colors
{
public:
	static void colortext() {
		HANDLE errorcolor = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(errorcolor, 4);
	}
	static void aftercheck() {
		HANDLE Menu = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(Menu, 11);
	}
	//14   8    
	static void perple() {
		HANDLE show_client = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(show_client, 13);
	}
};

