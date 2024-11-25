#include <iostream>
using namespace std;
#include "Schedule.h"

Schedule::Schedule() : seat(8) {
	time = "";
}

void Schedule::setTime(string time) { // ������ �ð� ����
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
		return seat[no - 1].book(user); // �¼� ���� �õ�
	return false;
}

//bool Schedule::cancel(int no, string name){
//	if(no >= 1 && no <= 8) { // �¼� ���� Ȯ��
//		return seat[no-1].cancel(name);
//	}
//	else
//		return false;
//}

bool Schedule::cancel(int no, const string& name) {
	if (no >= 1 && no <= 8) // �¼� ���� Ȯ��
		return seat[no - 1].cancel(name); // �¼� ��� �õ�
	return false;
}