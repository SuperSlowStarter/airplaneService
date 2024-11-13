#include "User.h"
#include <iostream>
using namespace std;

User::User() : airTime(0), seatNumber(0), userName("") {}

User::User(string name, int time, int seat) {
    userName = name;
    airTime = time;
    seatNumber = seat;
}

void User::setAirTime(int time) { airTime = time; }
int User::getAirTime() { return airTime; }
void User::setSeatNumber(int seat) { seatNumber = seat; }
int User::getSeatNumber() { return seatNumber; }
void User::setUserName(string name) { userName = name; }
string User::getUserName() { return userName; }

void User::modify() {
    int choice;
    cout << "1. 시간만 변경\n2. 좌석만 변경\n3. 시간과 좌석 모두 변경\n4. 이름 변경\n";
    cout << "메뉴를 선택하세요: ";
    cin >> choice;

    int newTime = airTime;  // 기존 값을 기본값으로 설정
    int newSeat = seatNumber;
    string newName = userName;

    switch (choice) {
    case 1:
        cout << "새로운 시간을 입력하세요: ";
        cin >> newTime;
        setAirTime(newTime);
        break;
    case 2:
        cout << "새로운 좌석 번호를 입력하세요: ";
        cin >> newSeat;
        setSeatNumber(newSeat);
        break;
    case 3:
        cout << "새로운 시간을 입력하세요: ";
        cin >> newTime;
        setAirTime(newTime);
        cout << "새로운 좌석 번호를 입력하세요: ";
        cin >> newSeat;
        setSeatNumber(newSeat);
        break;
    case 4:
        cout << "새로운 이름을 입력하세요: ";
        cin >> newName;
        setUserName(newName);
        break;
    default:
        cout << "잘못된 선택입니다.\n";
        break;
    }
}
