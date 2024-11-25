#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <vector>
#include "Seat.h"
using namespace std;

class Schedule{
	string time; // 스케쥴 타임
	vector<Seat> seat;
public:
	Schedule();
	bool book(const User& user);
	bool cancel(int no, const string& name);
	void view();
	void setTime(string time);

	// modify 구현에 필요한 함수들
	string getSeatUserName(int seatNo) const; // 좌석 번호로 예약자 이름 가져오기
	bool isSeatAvailable(int seatNo) const;  // 좌석이 비어있는지 확인
	void updateSeatName(int seatNo, const string& newName); // 좌석 이름 수정
	void moveSeat(int oldSeatNo, int newSeatNo); // 같은 스케줄 내에서 좌석 이동
	void moveUserFrom(Schedule& from, int oldSeatNo, int newSeatNo = -1); // 다른 스케줄로 사용자 이동
};

#endif