#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <vector>
#include "Seat.h"
using namespace std;

class Schedule{
	string time; // ������ Ÿ��
	vector<Seat> seat;
public:
	Schedule();
	bool book(const User& user);
	bool cancel(int no, const string& name);
	void view();
	void setTime(string time);

	// modify ������ �ʿ��� �Լ���
	string getSeatUserName(int seatNo) const; // �¼� ��ȣ�� ������ �̸� ��������
	bool isSeatAvailable(int seatNo) const;  // �¼��� ����ִ��� Ȯ��
	void updateSeatName(int seatNo, const string& newName); // �¼� �̸� ����
	void moveSeat(int oldSeatNo, int newSeatNo); // ���� ������ ������ �¼� �̵�
	void moveUserFrom(Schedule& from, int oldSeatNo, int newSeatNo = -1); // �ٸ� �����ٷ� ����� �̵�
};

#endif