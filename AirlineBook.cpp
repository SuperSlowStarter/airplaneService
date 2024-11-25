#include <iostream>
#include <string>
using namespace std;

#include "AirlineBook.h"
#include "Schedule.h"
#include "Console.h"
#include "User.h"

AirlineBook::AirlineBook(string name, int nSchedules, string scheduleTime[]) : name(name) { //생성자 초기화 리스트
	sche.resize(nSchedules); // 벡터 크기 설정
	for (int i = 0; i < nSchedules; i++) {
		sche[i].setTime(scheduleTime[i]);
	}
}

// 소멸자 벡터 사용으로 인해 delete 필요 없음
//AirlineBook::~AirlineBook(){
//	if(sche) 
//		delete [] sche;
//}

// 예약 시스템을 시작하는 함수
void AirlineBook::run(){
	cout << "***** " << name << "에 오신것을 환영합니다" << " *****" << endl;
	cout << endl;

	while(true){
		int menu = Console::getMainMenu(4); // 메인 메뉴 입력. 4는 메뉴 개수
		switch(menu){
			case 1:
				book(); // 예약
				break; 
			case 2:
				cancel(); // 예약
				break; 
			case 3:
				view(); // 예약 보기
				break; 
			case 4:
				modify();
				return;
			case 5:
				cout << "예약 시스템을 종료합니다.\n"<<endl;
				return;
			default:
				cout << "잘못입력하였습니다.\n"<<endl;
		}
		cout << endl;
	}
}

// 스케쥴을 예약한다. 구버전 예약
//void AirlineBook::book(){
//	int s;
//	string bookName;
//	int seatNo;
//	view();
//	s = Console::getScheduleMenu(nSchedules); // 사용자가 선택한 시간을 입력 받는다. nSchedule = 3
//	//view(s); // 스케쥴 s의 예약 상황을 출력한다. 대건 - 최초 예약이면 현재 남아있는 모든 스케줄표 보여주는게 낫지 않아?
//	seatNo = Console::getSeatNo(); // 좌석 번호를 입력받는다.
//	bookName = Console::getName(); // 예약자의 이름을 입력받는다.
//
//	 // 해당 스케쥴 예약
//	bool ret = sche[s-1].book(seatNo, bookName); //AirlineBook클래스의 sche가 메인 스케쥴 리스트
//	if(!ret)
//		Console::print("좌석 번호가 잘못되었거나 예약된 좌석입니다.\n");
//	else {
//		Console::print("예약되었습니다.\n");
//	}
//}

void AirlineBook::book() {
	view(); // 스케줄 보기
	int s = Console::getScheduleMenu(sche.size()); // 스케줄 선택
	int seatNo = Console::getSeatNo(); // 좌석 번호 입력
	string bookName = Console::getName(); // 예약자 이름 입력

	User newUser;
	newUser.setName(bookName);
	newUser.setSeatNumber(seatNo);
	newUser.setReserveTime(s);

	if (sche[s - 1].book(newUser)) { // 예약 요청
		Console::print("예약되었습니다.\n");
	}
	else {
		Console::print("예약 실패: 이미 예약된 좌석이거나 잘못된 입력입니다.\n");
	}
}


// 스케쥴을 취소한다. 구버전 취소
//void AirlineBook::cancel(){
//	int s;
//	string bookName;
//	int seatNo;
//
//	s = Console::getScheduleMenu(nSchedules); // 사용자가 선택한 스케쥴을 입력 받는다.
//	view(s); // 스케쥴 s의 예약 상황을 출력한다.
//	seatNo = Console::getSeatNo(); // 좌석 번호를 입력받는다.
//	bookName = Console::getName(); // 예약자의 이름을 입력받는다.
//
//	// 해당 스케쥴 취소
//	bool ret = sche[s-1].cancel(seatNo, bookName); 
//
//	if(!ret)
//		Console::print("좌석 번호나 예약자의 이름이 틀려 취소가 실패하였습니다.\n");
//	else {
//		Console::print("예약이 취소되었습니다.\n");
//	}
//}

void AirlineBook::cancel() {
	int s = Console::getScheduleMenu(sche.size()); // 스케줄 선택
	view(s); // 스케줄 보기
	int seatNo = Console::getSeatNo(); // 좌석 번호 입력
	string bookName = Console::getName(); // 예약자 이름 입력

	if (sche[s - 1].cancel(seatNo, bookName)) { // 취소 요청
		Console::print("예약이 취소되었습니다.\n");
	}
	else {
		Console::print("취소 실패: 잘못된 이름 또는 좌석 번호입니다.\n");
	}
}

// 현재 모든 스케쥴의 예약 상황을 출력한다.
void AirlineBook::view(){
	for(int i=0;i<3;i++){
		sche[i].view();
	}
}

// 스케쥴 s의 좌석 예약 상황을 출력한다. s는 1,2,3
void AirlineBook::view(int s){
	sche[s-1].view(); //배열의 인덱스는 0부터 시작
}

void AirlineBook::modify() {
	
};

int AirlineBook::find(const string& name) {
	for (size_t i = 0; i < sche.size(); ++i) {
		for (int j = 0; j < 8; ++j) { // 좌석은 8개로 고정
			if (sche[i].seat[j].getUserName() == name) {
				return i * 8 + j; // 시간대 인덱스와 좌석 인덱스를 결합하여 반환
			}
		}
	}
	return -1; // 사용자를 찾을 수 없는 경우
}

void AirlineBook::modify() {
    cout << "누구를 수정하시겠습니까??" << endl;
    string name;
    cin >> name;

    int position = find(name);
    if (position == -1) {
        cout << "해당 이름을 가진 사용자를 찾을 수 없습니다." << endl;
        return;
    }

    int scheduleIndex = position / 8; // 시간대 인덱스
    int seatIndex = position % 8;    // 좌석 인덱스

    cout << "어떻게 수정하시겠습니까?" << endl;
    cout << "1. 이름을 수정" << endl;
    cout << "2. 좌석을 수정" << endl;
    cout << "3. 시간대를 수정" << endl;
    cout << "4. 시간대와 좌석을 수정" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
    case 1: {
        cout << "새로운 이름을 입력하세요: ";
        string newName;
        cin >> newName;
        sche[scheduleIndex].seat[seatIndex].setUserName(newName);
        cout << "이름이 성공적으로 수정되었습니다." << endl;
        break;
    }
    case 2: {
        cout << "새로운 좌석 번호를 입력하세요 (1~8): ";
        int newSeat;
        cin >> newSeat;

        if (newSeat < 1 || newSeat > 8 || sche[scheduleIndex].seat[newSeat - 1].isBooked()) {
            cout << "해당 좌석은 사용 중이거나 잘못된 입력입니다." << endl;
        }
        else {
            sche[scheduleIndex].seat[newSeat - 1] = sche[scheduleIndex].seat[seatIndex];
            sche[scheduleIndex].seat[seatIndex].cancel(name);
            cout << "좌석이 성공적으로 변경되었습니다." << endl;
        }
        break;
    }
    case 3: {
        cout << "새로운 시간대(1~3)를 선택하세요: ";
        int newTime;
        cin >> newTime;

        if (newTime < 1 || newTime > sche.size() || sche[newTime - 1].seat[seatIndex].isBooked()) {
            cout << "해당 시간대는 예약이 불가능하거나 잘못된 입력입니다." << endl;
        }
        else {
            sche[newTime - 1].seat[seatIndex] = sche[scheduleIndex].seat[seatIndex];
            sche[scheduleIndex].seat[seatIndex].cancel(name);
            cout << "시간대가 성공적으로 변경되었습니다." << endl;
        }
        break;
    }
    case 4: {
        cout << "새로운 시간대(1~3)를 선택하세요: ";
        int newTime;
        cin >> newTime;

        cout << "새로운 좌석 번호를 입력하세요 (1~8): ";
        int newSeat;
        cin >> newSeat;

        if (newTime < 1 || newTime > sche.size() || newSeat < 1 || newSeat > 8 ||
            sche[newTime - 1].seat[newSeat - 1].isBooked()) {
            cout << "해당 시간대나 좌석은 예약이 불가능하거나 잘못된 입력입니다." << endl;
        }
        else {
            sche[newTime - 1].seat[newSeat - 1] = sche[scheduleIndex].seat[seatIndex];
            sche[scheduleIndex].seat[seatIndex].cancel(name);
            cout << "시간대와 좌석이 성공적으로 변경되었습니다." << endl;
        }
        break;
    }
    default:
        cout << "잘못된 선택입니다." << endl;
    }
}