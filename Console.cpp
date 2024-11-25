#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#include "Console.h"

int Console::getMainMenu(int nMenus){
	while(true) {
		cout << "예약:1, 취소:2, 보기:3, 끝내기:4>> " ;
		string in;
		cin >> in;
		if(in.size() > 1)
			continue; // 0을 리턴하는 경우, 사용자 입력 오류. 다시 입력
		int menu = getInt(in); // 0을 리턴하는 경우, 사용자 입력 오류임
		if(menu >= 1 && menu <= nMenus) // 메뉴 범위 체크
			return menu;
	}
}

int Console::getScheduleMenu(size_t nSchedules){
	while(true) {
		cout << "07시:1, 12시:2, 17시:3>> " ;
		string in;
		cin >> in;
		if(in.size() > 1)
			continue; // 0을 리턴하는 경우, 사용자 입력 오류. 다시 입력
		int menu = getInt(in); // 0을 리턴하는 경우, 사용자 입력 오류임
		if(menu >= 1 && menu <= nSchedules) // 스케쥴의 범위 체크 3보다 작아야함
			return menu;
	}
}

string Console::getName(){
	cout << "이름 입력>> ";
	string name;
	cin >> name;
	return name;
}

int Console::getSeatNo(){
	while(true) {
		cout << "좌석 번호>> " ;
		string in;
		cin >> in;
		int n = getInt(in); // 0을 리턴하는 경우, 사용자 입력 오류임
		if(n != 0)
			return n;
	}
}

void Console::print(string msg) {
	cout << msg;
}

int Console::getInt(string in) {
	return atoi(in.data()); // atoi()가 0을 리턴하면, 입력에 오류가 있었음
}