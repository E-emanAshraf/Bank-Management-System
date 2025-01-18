#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<cmath>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<Windows.h>
#include<fstream>
#include"validation.h"
#include"person.h"
#include"we_bank.h"
#include"client.h"
#include"employee.h"
#include"admin.h"
#include"input.h"
using namespace std;
//input
int main()
{
	webank::loadingbar();
	webank::menu();
	Input::input();
}
