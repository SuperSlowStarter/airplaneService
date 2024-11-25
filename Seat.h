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
	bool isBooked() const;
	bool cancel(const string& name);
	void view();

	// modify 구현에 필요한 함수들
	string getUserName() const; // 예약자 이름 가져오기
	User getUser() const;       // 예약된 User 객체 가져오기
	void setUserName(const string& newName); // 예약자 이름 설정
};

#endif