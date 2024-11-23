#ifndef SEAT_H
#define SEAT_H

#include <string>
using namespace std;

#include "User.h"

class Seat{
	//string name;
	User user;
public:
	Seat();
	bool book(const User& newUser);
	bool isBooked();
	bool cancel(const string& name);
	void view();
};

#endif