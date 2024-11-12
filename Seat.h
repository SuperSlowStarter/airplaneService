#ifndef SEAT_H
#define SEAT_H

#include <string>
using namespace std;

class Seat{
	string name;
public:
	Seat();
	bool book(string name);
	bool isBooked();
	bool cancel(string name);
	void view();
};

#endif