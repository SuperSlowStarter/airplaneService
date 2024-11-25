#include <iostream>
#include <string>
using namespace std;

#include "AirlineBook.h"
#include "Schedule.h"
#include "Console.h"
#include "User.h"

AirlineBook::AirlineBook(string name, int nSchedules, string scheduleTime[]) : name(name) { //������ �ʱ�ȭ ����Ʈ
	sche.resize(nSchedules); // ���� ũ�� ����
	for (int i = 0; i < nSchedules; i++) {
		sche[i].setTime(scheduleTime[i]);
	}
}

// �Ҹ��� ���� ������� ���� delete �ʿ� ����
//AirlineBook::~AirlineBook(){
//	if(sche) 
//		delete [] sche;
//}

// ���� �ý����� �����ϴ� �Լ�
void AirlineBook::run(){
	cout << "***** " << name << "�� ���Ű��� ȯ���մϴ�" << " *****" << endl;
	cout << endl;

	while(true){
		int menu = Console::getMainMenu(4); // ���� �޴� �Է�. 4�� �޴� ����
		switch(menu){
			case 1:
				book(); // ����
				break; 
			case 2:
				cancel(); // ����
				break; 
			case 3:
				view(); // ���� ����
				break; 
			case 4:
				cout << "���� �ý����� �����մϴ�.\n"<<endl;
				return;
			default:
				cout << "�߸��Է��Ͽ����ϴ�.\n"<<endl;
		}
		cout << endl;
	}
}

// �������� �����Ѵ�. ������ ����
//void AirlineBook::book(){
//	int s;
//	string bookName;
//	int seatNo;
//	view();
//	s = Console::getScheduleMenu(nSchedules); // ����ڰ� ������ �ð��� �Է� �޴´�. nSchedule = 3
//	//view(s); // ������ s�� ���� ��Ȳ�� ����Ѵ�. ��� - ���� �����̸� ���� �����ִ� ��� ������ǥ �����ִ°� ���� �ʾ�?
//	seatNo = Console::getSeatNo(); // �¼� ��ȣ�� �Է¹޴´�.
//	bookName = Console::getName(); // �������� �̸��� �Է¹޴´�.
//
//	 // �ش� ������ ����
//	bool ret = sche[s-1].book(seatNo, bookName); //AirlineBookŬ������ sche�� ���� ������ ����Ʈ
//	if(!ret)
//		Console::print("�¼� ��ȣ�� �߸��Ǿ��ų� ����� �¼��Դϴ�.\n");
//	else {
//		Console::print("����Ǿ����ϴ�.\n");
//	}
//}

void AirlineBook::book() {
	view(); // ������ ����
	int s = Console::getScheduleMenu(sche.size()); // ������ ����
	int seatNo = Console::getSeatNo(); // �¼� ��ȣ �Է�
	string bookName = Console::getName(); // ������ �̸� �Է�

	User newUser;
	newUser.setName(bookName);
	newUser.setSeatNumber(seatNo);
	newUser.setReserveTime(s);

	if (sche[s - 1].book(newUser)) { // ���� ��û
		Console::print("����Ǿ����ϴ�.\n");
	}
	else {
		Console::print("���� ����: �̹� ����� �¼��̰ų� �߸��� �Է��Դϴ�.\n");
	}
}


// �������� ����Ѵ�. ������ ���
//void AirlineBook::cancel(){
//	int s;
//	string bookName;
//	int seatNo;
//
//	s = Console::getScheduleMenu(nSchedules); // ����ڰ� ������ �������� �Է� �޴´�.
//	view(s); // ������ s�� ���� ��Ȳ�� ����Ѵ�.
//	seatNo = Console::getSeatNo(); // �¼� ��ȣ�� �Է¹޴´�.
//	bookName = Console::getName(); // �������� �̸��� �Է¹޴´�.
//
//	// �ش� ������ ���
//	bool ret = sche[s-1].cancel(seatNo, bookName); 
//
//	if(!ret)
//		Console::print("�¼� ��ȣ�� �������� �̸��� Ʋ�� ��Ұ� �����Ͽ����ϴ�.\n");
//	else {
//		Console::print("������ ��ҵǾ����ϴ�.\n");
//	}
//}

void AirlineBook::cancel() {
	int s = Console::getScheduleMenu(sche.size()); // ������ ����
	view(s); // ������ ����
	int seatNo = Console::getSeatNo(); // �¼� ��ȣ �Է�
	string bookName = Console::getName(); // ������ �̸� �Է�

	if (sche[s - 1].cancel(seatNo, bookName)) { // ��� ��û
		Console::print("������ ��ҵǾ����ϴ�.\n");
	}
	else {
		Console::print("��� ����: �߸��� �̸� �Ǵ� �¼� ��ȣ�Դϴ�.\n");
	}
}

// ���� ��� �������� ���� ��Ȳ�� ����Ѵ�.
void AirlineBook::view(){
	for(int i=0;i<3;i++){
		sche[i].view();
	}
}

// ������ s�� �¼� ���� ��Ȳ�� ����Ѵ�. s�� 1,2,3
void AirlineBook::view(int s){
	sche[s-1].view(); //�迭�� �ε����� 0���� ����
}

void AirlineBook::modify() {
	
};

