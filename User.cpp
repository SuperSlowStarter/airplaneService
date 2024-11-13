#include <iostream>
#include <string>
#include "User.h"

using namespace std;

// 기본 생성자 정의
User::User() : seatNumber(0), timeDate(0), userName("") {
    // 초기화가 필요한 경우 추가
}

int User::getSeatNumber() {
	return this->seatNumber;
};

int User::getTimeDate() {
	return this->timeDate;
};

void User::setSeatNumber(int userSeatNumber) {
	this->seatNumber = userSeatNumber;
};

void User::setTimeDate(int userTimeDate) {
	this->timeDate = userTimeDate;
};

string User::getUserName() {
    return this->userName;
};

void User::setUserName(string inputUserName) {
    this->userName = inputUserName;
};

void User::modify() {
    int choice;
    cout << "어떤 것을 수정하시겠습니까?\n";
    cout << "1. 시간만 변경\n";
    cout << "2. 좌석만 변경\n";
    cout << "3. 시간과 좌석 모두 변경\n";
    cout << "4. 이름을 변경\n";
    cout << "선택: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        int newTime;
        cout << "새로운 시간을 입력하세요: ";
        cin >> newTime;
        setTimeDate(newTime);
        cout << "시간이 변경되었습니다.\n";
        break;
    }
    case 2: {
        int newSeat;
        cout << "새로운 좌석 번호를 입력하세요: ";
        cin >> newSeat;
        setSeatNumber(newSeat);
        cout << "좌석이 변경되었습니다.\n";
        break;
    }
    case 3: {
        int newTime, newSeat;
        cout << "새로운 시간을 입력하세요: ";
        cin >> newTime;
        setTimeDate(newTime);
        cout << "새로운 좌석 번호를 입력하세요: ";
        cin >> newSeat;
        setSeatNumber(newSeat);
        cout << "시간과 좌석이 모두 변경되었습니다.\n";
        break;
    }
    case 4: {
        cout << "새로운 이름을 입력하세요: ";
        cin >> userName;
        cout << "이름이 변경되었습니다.\n";
        break;
    }
    default:
        cout << "잘못된 선택입니다. 다시 시도하세요.\n";
    }
}