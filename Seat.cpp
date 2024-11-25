#include <iostream>
using namespace std;

#include "Seat.h"

Seat::Seat(){
	user.setName("");
}

// ����
bool Seat::book(const User& newUser){
	if(isBooked()) // ����� �¼��̶�� ����
		return false;
	else {
		this->user = newUser;
		return true;
	}
}

// ���� Ȯ��
bool Seat::isBooked() const {
	/*if(name.size()==0)
		return false;
	else
		return true;*/

	return !user.getUserName().empty(); //user Ŭ���� �������
}

// ���� ���
bool Seat::cancel(const string& name){
	if(user.getUserName() == name) { // ����ϴ� �̸��� �����ϸ�
		user.setName(""); // �̸� ����
		user.setReserveTime(NULL);
		user.setSeatNumber(NULL);
		return true; // ��� ����
	}
	else
		return false; // ��� ����
}

// ������ �̸� ���
void Seat::view() {
	if(isBooked())
		cout << user.getUserName() << "\t";
	else
		cout << "--" << "\t";
}

string Seat::getUserName() const {
	return user.getUserName();
}

User Seat::getUser() const {
	return user;
}

void Seat::setUserName(const string& newName) {
	user.setName(newName);
}