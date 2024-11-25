#ifndef CONSOLE_H
#define CONSOLE_H

#include<string>
using namespace std;

class Console{
	static int getInt(string in);
public:
	static int getMainMenu(int nMenus);
	static int getScheduleMenu(size_t nSchedules); //벡터 사용에 의해 nSchedule -> sche.size()가 됨에 따라 size_t를 받는다
	static string getName();
	static int getSeatNo();
	static void print(string);	
};

#endif