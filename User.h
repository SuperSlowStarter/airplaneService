#pragma once
#include <string>
using namespace std;

class User{
	int seatNumber;
	int timeDate;
	string userName;
public:
	User();
	int getSeatNumber();
	int getTimeDate();
	void setSeatNumber(int userSeatNumber);
	void setTimeDate(int userTimeDate);
	void modify();

	string getUserName();
	void setUserName(string inputUserName);

};
