#ifndef CONSOLE_H
#define CONSOLE_H

#include<string>
using namespace std;

class Console{
	static int getInt(string in);
public:
	static int getMainMenu(int nMenus);
	static int getScheduleMenu(size_t nSchedules); //���� ��뿡 ���� nSchedule -> sche.size()�� �ʿ� ���� size_t�� �޴´�
	static string getName();
	static int getSeatNo();
	static void print(string);	
};

#endif