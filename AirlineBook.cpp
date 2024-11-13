#include <iostream>
#include "AirlineBook.h"
#include "Schedule.h"
#include "Console.h"
#include "User.h"
using namespace std;

AirlineBook::AirlineBook(string name, int nSchedules, string scheduleTime[]) {
    this->name = name;
    this->nSchedules = nSchedules;
    sche = new Schedule[nSchedules];

    for (int i = 0; i < nSchedules; i++) {
        sche[i].setTime(scheduleTime[i]);
    }
}

AirlineBook::~AirlineBook() {
    if (sche)
        delete[] sche;
}

void AirlineBook::run() {
    cout << "***** " << name << "에 오신 것을 환영합니다 *****" << endl;
    cout << endl;

    while (true) {
        int menu = Console::getMainMenu(5); // 5는 메뉴 개수
        switch (menu) {
        case 1:
            book();
            break;
        case 2:
            cancel();
            break;
        case 3:
            view();
            break;
        case 4:
            modify();
            break;
        case 5:
            cout << "예약 시스템을 종료합니다.\n" << endl;
            return;
        default:
            cout << "잘못 입력하였습니다.\n" << endl;
        }
        cout << endl;
    }
}

void AirlineBook::book() {
    int s = Console::getScheduleMenu(nSchedules);
    view(s);

    User user;
    user.setSeatNumber(Console::getSeatNo());
    user.setUserName(Console::getName());
    user.setTimeDate(s);

    bool ret = sche[s - 1].book(user.getSeatNumber(), user.getUserName());
    if (!ret)
        Console::print("좌석 번호가 잘못되었거나 예약된 좌석입니다.\n");
    else
        Console::print("예약되었습니다.\n");
}

void AirlineBook::cancel() {
    int s = Console::getScheduleMenu(nSchedules);
    view(s);

    User user;
    user.setSeatNumber(Console::getSeatNo());
    user.setUserName(Console::getName());
    user.setTimeDate(s);

    bool ret = sche[s - 1].cancel(user.getSeatNumber(), user.getUserName());
    if (!ret)
        Console::print("좌석 번호나 예약자의 이름이 틀려 취소가 실패하였습니다.\n");
    else
        Console::print("예약이 취소되었습니다.\n");
}

void AirlineBook::modify() {
    User user;
    user.modify();

    int scheduleIndex = user.getTimeDate() - 1;  // 스케줄 인덱스
    bool ret = sche[scheduleIndex].book(user.getSeatNumber(), user.getUserName());

    if (!ret) {
        Console::print("예약 변경에 실패하였습니다.\n");
    }
    else {
        Console::print("예약이 성공적으로 변경되었습니다.\n");
    }
}

void AirlineBook::view() {
    for (int i = 0; i < nSchedules; i++) {
        sche[i].view();
    }
}

void AirlineBook::view(int s) {
    sche[s - 1].view();
}
