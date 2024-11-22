#ifndef AIRLINEBOOK_H
#define AIRLINEBOOK_H

#include <string>
using namespace std;

class Schedule;

class AirlineBook{
	string name;
	int nSchedules; // 스케쥴 개수
	Schedule *sche; // 스케쥴 배열

	void book();
	void cancel();
	void view();
	void view(int s);
	void modify();

public:
	AirlineBook(string name, int nSchedules, string scheduleTime []);
	~AirlineBook();
	void run();
};

#endif