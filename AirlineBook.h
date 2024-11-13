#ifndef AIRLINEBOOK_H
#define AIRLINEBOOK_H

#include <string>
#include "User.h"
using namespace std;

class Schedule;

class AirlineBook {
    string name;
    int nSchedules;
    Schedule* sche;
    User* users[100];  // 최대 100명의 유저 정보를 저장하는 배열
    int userCount;     // 현재 예약된 유저 수

    void book();
    void cancel();
    void view();
    void view(int s);
    void modify();

public:
    AirlineBook(string name, int nSchedules, string scheduleTime[]);
    ~AirlineBook();
    void run();
};

#endif
