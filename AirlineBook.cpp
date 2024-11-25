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
		int menu = Console::getMainMenu(5); // ���� �޴� �Է�. 4�� �޴� ����
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
				modify();
                break;
			case 5:
				cout << "���� �ý����� �����մϴ�.\n"<<endl;
				return;
			default:
				cout << "�߸��Է��Ͽ����ϴ�.\n"<<endl;
		}
		cout << endl;
	}}

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

int AirlineBook::find(const string& name) {
    for (size_t i = 0; i < sche.size(); ++i) {
        for (int seatNo = 1; seatNo <= 8; ++seatNo) {
            if (sche[i].getSeatUserName(seatNo) == name) {
                return i * 10 + seatNo; // ��ġ�� �ð���� �¼���ȣ�� ��ȯ
            }
        }
    }
    return -1; // ã�� ����
}

void AirlineBook::modify() {
    string name = Console::getName();
    int location = find(name);
    if (location == -1) {
        Console::print("�ش� �̸��� �����ڸ� ã�� �� �����ϴ�.\n");
        return;
    }

    int scheduleIndex = location / 10; // �ð���
    int seatNo = location % 10;       // �¼� ��ȣ

    Console::print("��� �����Ͻðڽ��ϱ�?\n1. �̸��� ����\n2. �¼��� ����\n3. �ð��븦 ����\n4. �ð���� �¼��� ����\n>> ");
    int choice;
    cin >> choice;

    switch (choice) {
    case 1: {
        string newName = Console::getName();
        sche[scheduleIndex].updateSeatName(seatNo, newName);
        Console::print("�̸��� �����Ǿ����ϴ�.\n");
        break;
    }
    case 2: {
        int newSeatNo = Console::getSeatNo();
        if (sche[scheduleIndex].isSeatAvailable(newSeatNo)) {
            sche[scheduleIndex].moveSeat(seatNo, newSeatNo);
            Console::print("�¼��� �����Ǿ����ϴ�.\n");
        }
        else {
            Console::print("�ش� �¼��� �̹� ����Ǿ� �ֽ��ϴ�.\n");
        }
        break;
    }
    case 3: {
        // �̵��� �ð��븦 ����
        int newScheduleIndex = Console::getScheduleMenu(sche.size()) - 1;

        // ���� �¼� ��ȣ�� ������ ä�� �ð��� ����
        if (newScheduleIndex != scheduleIndex) { // ���� �ð���� �̵����� �ʵ��� Ȯ��
            if (sche[newScheduleIndex].isSeatAvailable(seatNo)) { // �� �ð����� ���� �¼��� ��� �ִ��� Ȯ��
                // �� �ð���� ����� �̵�
                sche[newScheduleIndex].moveUserFrom(sche[scheduleIndex], seatNo, seatNo);
                Console::print("�ð��밡 ���������� �����Ǿ����ϴ�.\n");
            }
            else {
                Console::print("�ش� �ð����� ���� �¼��� �̹� ����Ǿ� �ֽ��ϴ�.\n");
            }
        }
        else {
            Console::print("���� �ð���� ������ �ð��븦 ������ �� �����ϴ�.\n");
        }
        break;
    }
    case 4: {
        int newScheduleIndex = Console::getScheduleMenu(sche.size()) - 1;
        int newSeatNo = Console::getSeatNo();
        if (sche[newScheduleIndex].isSeatAvailable(newSeatNo)) {
            sche[newScheduleIndex].moveUserFrom(sche[scheduleIndex], seatNo, newSeatNo);
            Console::print("�ð���� �¼��� �����Ǿ����ϴ�.\n");
        }
        else {
            Console::print("�ش� �ð��� �Ǵ� �¼��� �̹� ����Ǿ� �ֽ��ϴ�.\n");
        }
        break;
    }
    default:
        Console::print("�߸��� �Է��Դϴ�.\n");
    }
}