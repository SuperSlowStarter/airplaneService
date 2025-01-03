#pragma once

#include <iostream>
#include <string>
using namespace std;

class User {
	string name;
	int seatNumber;
	int reserveTime;
public:
	void setSeatNumber(int inputNumber);
	void setReserveTime(int inputTime);
	void setName(string inputName);

	string getUserName() const;
	int getSeatNumber() const;
	int getReserveTime() const;
};