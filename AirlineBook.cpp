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
		int menu = Console::getMainMenu(5); // 메인 메뉴 입력. 4는 메뉴 개수
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
                break;
			case 5:
				cout << "예약 시스템을 종료합니다.\n"<<endl;
				return;
			default:
				cout << "잘못입력하였습니다.\n"<<endl;
		}
		cout << endl;
	}}

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

int AirlineBook::find(const string& name) {
    for (size_t i = 0; i < sche.size(); ++i) {
        for (int seatNo = 1; seatNo <= 8; ++seatNo) {
            if (sche[i].getSeatUserName(seatNo) == name) {
                return i * 10 + seatNo; // 위치를 시간대와 좌석번호로 반환
            }
        }
    }
    return -1; // 찾지 못함
}

void AirlineBook::modify() {
    string name = Console::getName();
    int location = find(name);
    if (location == -1) {
        Console::print("해당 이름의 예약자를 찾을 수 없습니다.\n");
        return;
    }

    int scheduleIndex = location / 10; // 시간대
    int seatNo = location % 10;       // 좌석 번호

    Console::print("어떻게 수정하시겠습니까?\n1. 이름을 수정\n2. 좌석을 수정\n3. 시간대를 수정\n4. 시간대와 좌석을 수정\n>> ");
    int choice;
    cin >> choice;

    switch (choice) {
    case 1: {
        string newName = Console::getName();
        sche[scheduleIndex].updateSeatName(seatNo, newName);
        Console::print("이름이 수정되었습니다.\n");
        break;
    }
    case 2: {
        int newSeatNo = Console::getSeatNo();
        if (sche[scheduleIndex].isSeatAvailable(newSeatNo)) {
            sche[scheduleIndex].moveSeat(seatNo, newSeatNo);
            Console::print("좌석이 수정되었습니다.\n");
        }
        else {
            Console::print("해당 좌석은 이미 예약되어 있습니다.\n");
        }
        break;
    }
    case 3: {
        // 이동할 시간대를 선택
        int newScheduleIndex = Console::getScheduleMenu(sche.size()) - 1;

        // 동일 좌석 번호를 유지한 채로 시간대 변경
        if (newScheduleIndex != scheduleIndex) { // 동일 시간대로 이동하지 않도록 확인
            if (sche[newScheduleIndex].isSeatAvailable(seatNo)) { // 새 시간대의 동일 좌석이 비어 있는지 확인
                // 새 시간대로 사용자 이동
                sche[newScheduleIndex].moveUserFrom(sche[scheduleIndex], seatNo, seatNo);
                Console::print("시간대가 성공적으로 수정되었습니다.\n");
            }
            else {
                Console::print("해당 시간대의 동일 좌석이 이미 예약되어 있습니다.\n");
            }
        }
        else {
            Console::print("현재 시간대와 동일한 시간대를 선택할 수 없습니다.\n");
        }
        break;
    }
    case 4: {
        int newScheduleIndex = Console::getScheduleMenu(sche.size()) - 1;
        int newSeatNo = Console::getSeatNo();
        if (sche[newScheduleIndex].isSeatAvailable(newSeatNo)) {
            sche[newScheduleIndex].moveUserFrom(sche[scheduleIndex], seatNo, newSeatNo);
            Console::print("시간대와 좌석이 수정되었습니다.\n");
        }
        else {
            Console::print("해당 시간대 또는 좌석이 이미 예약되어 있습니다.\n");
        }
        break;
    }
    default:
        Console::print("잘못된 입력입니다.\n");
    }
}