#include <iostream>
using namespace std;

#include "Seat.h"

Seat::Seat(){
	user.setName("");
}

// 예약
bool Seat::book(const User& newUser){
	if(isBooked()) // 예약된 좌석이라면 오류
		return false;
	else {
		this->user = newUser;
		return true;
	}
}

// 예약 확인
bool Seat::isBooked() const {
	/*if(name.size()==0)
		return false;
	else
		return true;*/

	return !user.getUserName().empty(); //user 클래스 기반으로
}

// 예약 취소
bool Seat::cancel(const string& name){
	if(user.getUserName() == name) { // 취소하는 이름이 동일하면
		user.setName(""); // 이름 삭제
		user.setReserveTime(NULL);
		user.setSeatNumber(NULL);
		return true; // 취소 성공
	}
	else
		return false; // 취소 실패
}

// 예약자 이름 출력
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