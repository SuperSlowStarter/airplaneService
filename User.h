#pragma once
#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    int airTime;       // 예매 시간
    int seatNumber;    // 좌석 번호
    string userName;   // 유저 이름

public:
    User();  // 기본 생성자
    User(string name, int time, int seat);

    // Getter와 Setter 함수들
    void setAirTime(int time);
    int getAirTime();
    void setSeatNumber(int seat);
    int getSeatNumber();
    void setUserName(string name);
    string getUserName();

    // Modify 함수
    void modify();
};

#endif
