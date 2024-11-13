#include "AirlineBook.h"
#include "Console.h"
#include "Schedule.h"
#include <iostream>
using namespace std;

AirlineBook::AirlineBook(string name, int nSchedules, string scheduleTime[]) {
    this->name = name;
    this->nSchedules = nSchedules;
    sche = new Schedule[nSchedules];
    for (int i = 0; i < nSchedules; i++)
        sche[i].setTime(scheduleTime[i]);
    userCount = 0;
}

AirlineBook::~AirlineBook() {
    if (sche) delete[] sche;
    for (int i = 0; i < userCount; i++) delete users[i];
}

void AirlineBook::run() {
    cout << "***** " << name << "에 오신 것을 환영합니다 *****" << endl << endl;
    while (true) {
        int menu = Console::getMainMenu(5); // 수정된 메뉴
        switch (menu) {
        case 1: book(); break;
        case 2: cancel(); break;
        case 3: view(); break;
        case 4: modify(); break;
        case 5:
            cout << "예약 시스템을 종료합니다.\n" << endl;
            return;
        default: cout << "잘못된 입력입니다.\n" << endl;
        }
        cout << endl;
    }
}

void AirlineBook::book() {
    string userName;
    int seatNo, airTime;

    userName = Console::getName(); // 유저 이름 입력
    view();                        // 예약 상태 보여줌

    airTime = Console::getScheduleMenu(nSchedules); // 시간 선택
    if (!sche[airTime - 1].hasAvailableSeats()) {   // 좌석이 없으면 종료
        Console::print("해당 시간에 남은 좌석이 없습니다.\n");
        return;
    }

    seatNo = Console::getSeatNo();                   // 좌석 번호 선택
    while (!sche[airTime - 1].book(seatNo, userName)) {
        Console::print("이미 예약된 좌석입니다. 다른 좌석을 선택하세요.\n");
        seatNo = Console::getSeatNo();
    }

    users[userCount++] = new User(userName, airTime, seatNo); // User 인스턴스 생성
    Console::print("예매가 완료되었습니다.\n");
}

void AirlineBook::cancel() {
    string userName = Console::getName();
    int seatNo = Console::getSeatNo();

    bool found = false;
    for (int i = 0; i < userCount; i++) {
        if (users[i] && users[i]->getUserName() == userName && users[i]->getSeatNumber() == seatNo) {
            sche[users[i]->getAirTime() - 1].cancel(seatNo, userName);
            delete users[i];
            users[i] = nullptr;
            found = true;
            Console::print("예약이 취소되었습니다.\n");
            break;
        }
    }
    if (!found) Console::print("취소할 예약을 찾지 못했습니다.\n");
}

void AirlineBook::modify() {
    string userName = Console::getName();
    for (int i = 0; i < userCount; i++) {
        if (users[i] && users[i]->getUserName() == userName) {
            users[i]->modify();
            return;
        }
    }
    Console::print("수정할 예약을 찾지 못했습니다.\n");
}

