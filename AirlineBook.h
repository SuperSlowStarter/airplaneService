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
	int find(const string& name); // 예약자 이름으로 좌석 위치 찾기

public:
	AirlineBook(string name, int nSchedules, string scheduleTime []);
	void run();
	void modify(); // 예약 수정 기능
};

#endif