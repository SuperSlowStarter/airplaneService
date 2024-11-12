#ifndef CONSOLE_H
#define CONSOLE_H

#include<string>
using namespace std;

class Console{
	static int getInt(string in);
public:
	static int getMainMenu(int nMenus);
	static int getScheduleMenu(int nSchedules);
	static string getName();
	static int getSeatNo();
	static void print(string);	
};

#endif