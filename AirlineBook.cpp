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
				modify();
				return;
			case 5:
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

int AirlineBook::find(const string& name) {
	for (size_t i = 0; i < sche.size(); ++i) {
		for (int j = 0; j < 8; ++j) { // �¼��� 8���� ����
			if (sche[i].seat[j].getUserName() == name) {
				return i * 8 + j; // �ð��� �ε����� �¼� �ε����� �����Ͽ� ��ȯ
			}
		}
	}
	return -1; // ����ڸ� ã�� �� ���� ���
}

void AirlineBook::modify() {
    cout << "������ �����Ͻðڽ��ϱ�??" << endl;
    string name;
    cin >> name;

    int position = find(name);
    if (position == -1) {
        cout << "�ش� �̸��� ���� ����ڸ� ã�� �� �����ϴ�." << endl;
        return;
    }

    int scheduleIndex = position / 8; // �ð��� �ε���
    int seatIndex = position % 8;    // �¼� �ε���

    cout << "��� �����Ͻðڽ��ϱ�?" << endl;
    cout << "1. �̸��� ����" << endl;
    cout << "2. �¼��� ����" << endl;
    cout << "3. �ð��븦 ����" << endl;
    cout << "4. �ð���� �¼��� ����" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
    case 1: {
        cout << "���ο� �̸��� �Է��ϼ���: ";
        string newName;
        cin >> newName;
        sche[scheduleIndex].seat[seatIndex].setUserName(newName);
        cout << "�̸��� ���������� �����Ǿ����ϴ�." << endl;
        break;
    }
    case 2: {
        cout << "���ο� �¼� ��ȣ�� �Է��ϼ��� (1~8): ";
        int newSeat;
        cin >> newSeat;

        if (newSeat < 1 || newSeat > 8 || sche[scheduleIndex].seat[newSeat - 1].isBooked()) {
            cout << "�ش� �¼��� ��� ���̰ų� �߸��� �Է��Դϴ�." << endl;
        }
        else {
            sche[scheduleIndex].seat[newSeat - 1] = sche[scheduleIndex].seat[seatIndex];
            sche[scheduleIndex].seat[seatIndex].cancel(name);
            cout << "�¼��� ���������� ����Ǿ����ϴ�." << endl;
        }
        break;
    }
    case 3: {
        cout << "���ο� �ð���(1~3)�� �����ϼ���: ";
        int newTime;
        cin >> newTime;

        if (newTime < 1 || newTime > sche.size() || sche[newTime - 1].seat[seatIndex].isBooked()) {
            cout << "�ش� �ð���� ������ �Ұ����ϰų� �߸��� �Է��Դϴ�." << endl;
        }
        else {
            sche[newTime - 1].seat[seatIndex] = sche[scheduleIndex].seat[seatIndex];
            sche[scheduleIndex].seat[seatIndex].cancel(name);
            cout << "�ð��밡 ���������� ����Ǿ����ϴ�." << endl;
        }
        break;
    }
    case 4: {
        cout << "���ο� �ð���(1~3)�� �����ϼ���: ";
        int newTime;
        cin >> newTime;

        cout << "���ο� �¼� ��ȣ�� �Է��ϼ��� (1~8): ";
        int newSeat;
        cin >> newSeat;

        if (newTime < 1 || newTime > sche.size() || newSeat < 1 || newSeat > 8 ||
            sche[newTime - 1].seat[newSeat - 1].isBooked()) {
            cout << "�ش� �ð��볪 �¼��� ������ �Ұ����ϰų� �߸��� �Է��Դϴ�." << endl;
        }
        else {
            sche[newTime - 1].seat[newSeat - 1] = sche[scheduleIndex].seat[seatIndex];
            sche[scheduleIndex].seat[seatIndex].cancel(name);
            cout << "�ð���� �¼��� ���������� ����Ǿ����ϴ�." << endl;
        }
        break;
    }
    default:
        cout << "�߸��� �����Դϴ�." << endl;
    }
}