#include <iostream>
using namespace std;
#include "Schedule.h"

Schedule::Schedule() : seat(8) {
	time = "";
}

void Schedule::setTime(string time) { // 스케쥴 시간 설정
	this->time = time;
}

void Schedule::view(){
	cout << time << ":\t";
	for (auto& s : seat) {
		s.view();
	}
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

string Schedule::getSeatUserName(int seatNo) const {
    if (seatNo >= 1 && seatNo <= 8) {
        return seat[seatNo - 1].getUserName();
    }
    return "";
}

bool Schedule::isSeatAvailable(int seatNo) const {
    if (seatNo >= 1 && seatNo <= 8) {
        return !seat[seatNo - 1].isBooked();
    }
    return false;
}

void Schedule::updateSeatName(int seatNo, const string& newName) {
    if (seatNo >= 1 && seatNo <= 8) {
        seat[seatNo - 1].setUserName(newName);
    }
}

void Schedule::moveSeat(int oldSeatNo, int newSeatNo) {
    if (oldSeatNo >= 1 && oldSeatNo <= 8 && newSeatNo >= 1 && newSeatNo <= 8) {
        User movingUser = seat[oldSeatNo - 1].getUser();
        seat[oldSeatNo - 1].cancel(movingUser.getUserName());
        seat[newSeatNo - 1].book(movingUser);
    }
}

void Schedule::moveUserFrom(Schedule& from, int oldSeatNo, int newSeatNo) {
    User movingUser = from.seat[oldSeatNo - 1].getUser();
    from.seat[oldSeatNo - 1].cancel(movingUser.getUserName());
    seat[newSeatNo - 1].book(movingUser);
}