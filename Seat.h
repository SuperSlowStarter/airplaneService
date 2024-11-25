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

	// modify ������ �ʿ��� �Լ���
	string getUserName() const; // ������ �̸� ��������
	User getUser() const;       // ����� User ��ü ��������
	void setUserName(const string& newName); // ������ �̸� ����
};

#endif