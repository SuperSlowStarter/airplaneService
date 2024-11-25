#pragma once

#include <iostream>
#include <string>
using namespace std;

class User {
	string name;
	int seatNumber = 0;
	int reserveTime = 0;
public:
	void setSeatNumber(int inputNumber);
	void setReserveTime(int inputTime);
	void setName(string inputName);

	string getUserName() const;
	int getSeatNumber() const;
	int getReserveTime() const;
};