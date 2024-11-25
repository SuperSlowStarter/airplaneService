#ifndef AIRLINEBOOK_H
#define AIRLINEBOOK_H

#include <vector>
#include <string>
using namespace std;

#include "Schedule.h"

class AirlineBook{
	string name;
	vector<Schedule> sche;

	void book();
	void cancel();
	void view();
	void view(int s);
	int find(const string& name); // ������ �̸����� �¼� ��ġ ã��

public:
	AirlineBook(string name, int nSchedules, string scheduleTime []);
	void run();
	void modify(); // ���� ���� ���
};

#endif