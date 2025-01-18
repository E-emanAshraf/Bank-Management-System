#pragma once
#include <iostream>
#include<string>
#include<Windows.h>
using namespace std;
class webank
{
public:
	static void loadingbar() {
		HANDLE barcolor = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(barcolor, 11.9);
		int ascii = 219;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tloading....\n\n\t\t\t\t\t\t";
		for (int i = 0;i < 25;i++) {
			cout << (char)ascii;
			Sleep(150);
		}
		system("cls");
	}
	//apperance of the opening screan
	static void menu() {
		system("color 37");
		cout << "\n\n\n\n\n\n\n";
		cout << "                      ##       ##   #######   ##       #######   ########   ####    ####   #######" << "\n";
		cout << "                      ##   #   ##   ##        ##       ##        ##    ##   ##  #  #  ##   ##     " << "\n";
		cout << "                      ##  ###  ##   #######   ##       ##        ##    ##   ##   ##   ##   #######" << "\n";
		cout << "                      ## ## ## ##   ##        ##       ##        ##    ##   ##        ##   ##     " << "\n";
		cout << "                      ###     ###   #######   ######   #######   ########   ##        ##   #######" << "\n";
		cout << "\n\n\n\n";
		cout << "                          @@       @@   @@@@@@@   #######   ########   ####     ##   ##   ##" << "\n";
		cout << "                          @@   @   @@   @@        ##    ##  ##    ##   ## ##    ##   ##  ##" << "\n";
		cout << "                          @@  @@@  @@   @@@@@@@   #######   ########   ##  ##   ##   ## #" << "\n";
		cout << "                          @@ @@ @@ @@   @@        ##    ##  ##    ##   ##   ##  ##   ##  ##" << "\n";
		cout << "                          @@@     @@@   @@@@@@@   #######   ##    ##   ##    ####    ##   ##" << "\n";
		Sleep(2000);
		system("cls");
		system("color F");
	}
};



