#include <iostream>
using namespace std;
#include "Schedule.h"

Schedule::Schedule(){
	seat = new Seat[8]; // 8개의 좌석
	time = ""; // 초기화
}

Schedule::~Schedule(){
	if(seat)
		delete [] seat;
}

void Schedule::setTime(string time) { // 스케쥴 시간 설정
	this->time = time;
}

void Schedule::view(){
	cout << time << ":\t";
	for(int i=0; i<8; i++)
		seat[i].view();
	cout << endl;
}

bool Schedule::book(const User& user){
	int no = user.getSeatNumber();
	if (no >= 1 && no <= 8)
		return seat[no - 1].book(user); // 좌석 예약 시도
	return false;
}

//bool Schedule::cancel(int no, string name){
//	if(no >= 1 && no <= 8) { // 좌석 범위 확인
//		return seat[no-1].cancel(name);
//	}
//	else
//		return false;
//}

bool Schedule::cancel(int no, const string& name) {
	if (no >= 1 && no <= 8) // 좌석 범위 확인
		return seat[no - 1].cancel(name); // 좌석 취소 시도
	return false;
}