#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include "Seat.h"
using namespace std;

class Schedule{
	string time; // 스케쥴 타임
	Seat* seat;
public:
	Schedule();
	~Schedule();
	bool book(const User& user);
	bool cancel(int no, const string& name);
	void view();
	void setTime(string time);
};

#endif