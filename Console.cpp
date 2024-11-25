#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "Console.h"

int Console::getMainMenu(int nMenus){
	while(true) {
		
		Console::print("============================\n");
		Console::print("   메인 메뉴\n");
		Console::print("============================\n");
		Console::print("1. 예약\n");
		Console::print("2. 취소\n");
		Console::print("3. 예약 보기\n");
		Console::print("4. 예약 수정하기\n");
		Console::print("5. 종료\n");
		Console::print("============================");
		Console::print(">> ");
		string in;
		cin >> in;
		if(in.size() > 1)
			continue; 
		int menu = getInt(in); // 0을 리턴하는 경우, 사용자 입력 오류임
		if(menu >= 1 && menu <= nMenus) // 메뉴 범위 체크
			return menu;
	}
}

int Console::getScheduleMenu(size_t nSchedules){
	while(true) {
		system("cls");
		Console::print("============================\n");
		Console::print("   시간대 선택\n");
		Console::print("============================\n");
		Console::print("1. 07시\n");
		Console::print("2. 12시\n");
		Console::print("3. 17시\n");
		Console::print("============================\n");
		Console::print(">> ");
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
	system("cls");
	Console::print("============================\n");
	Console::print("   이름 입력\n");
	Console::print("============================\n");
	Console::print(">> ");
	string name;
	cin >> name;
	return name;
}

int Console::getSeatNo(){
	while(true) {
		system("cls");
		Console::print("============================\n");
		Console::print("   좌석 번호 입력\n");
		Console::print("============================\n");
		Console::print(">> ");
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
