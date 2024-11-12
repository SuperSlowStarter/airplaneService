#include <iostream>
using namespace std;

#include "Seat.h"

Seat::Seat(){
	name = "";
}

// 예약
bool Seat::book(string name){
	if(isBooked()) // 예약된 좌석이라면 오류
		return false;
	else {
		this->name = name;
		return true;
	}
}

// 예약 확인
bool Seat::isBooked(){
	if(name.size()==0)
		return false;
	else
		return true;
}

// 예약 취소
bool Seat::cancel(string name){
	if(this->name == name) { // 취소하는 이름이 동일하면
		this->name = ""; // 이름 삭제
		return true; // 취소 성공
	}
	else
		return false; // 취소 실패
}

// 예약자 이름 출력
void Seat::view(){
	if(isBooked())
		cout << name << "\t";
	else
		cout << "--" << "\t";
}