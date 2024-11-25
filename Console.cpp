#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "Console.h"

int Console::getMainMenu(int nMenus){
	while(true) {
		
		Console::print("============================\n");
		Console::print("   ���� �޴�\n");
		Console::print("============================\n");
		Console::print("1. ����\n");
		Console::print("2. ���\n");
		Console::print("3. ���� ����\n");
		Console::print("4. ���� �����ϱ�\n");
		Console::print("5. ����\n");
		Console::print("============================");
		Console::print(">> ");
		string in;
		cin >> in;
		if(in.size() > 1)
			continue; 
		int menu = getInt(in); // 0�� �����ϴ� ���, ����� �Է� ������
		if(menu >= 1 && menu <= nMenus) // �޴� ���� üũ
			return menu;
	}
}

int Console::getScheduleMenu(size_t nSchedules){
	while(true) {
		system("cls");
		Console::print("============================\n");
		Console::print("   �ð��� ����\n");
		Console::print("============================\n");
		Console::print("1. 07��\n");
		Console::print("2. 12��\n");
		Console::print("3. 17��\n");
		Console::print("============================\n");
		Console::print(">> ");
		string in;
		cin >> in;
		if(in.size() > 1)
			continue; // 0�� �����ϴ� ���, ����� �Է� ����. �ٽ� �Է�
		int menu = getInt(in); // 0�� �����ϴ� ���, ����� �Է� ������
		if(menu >= 1 && menu <= nSchedules) // �������� ���� üũ 3���� �۾ƾ���
			return menu;
	}
}

string Console::getName(){
	system("cls");
	Console::print("============================\n");
	Console::print("   �̸� �Է�\n");
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
		Console::print("   �¼� ��ȣ �Է�\n");
		Console::print("============================\n");
		Console::print(">> ");
		string in;
		cin >> in;
		int n = getInt(in); // 0�� �����ϴ� ���, ����� �Է� ������
		if(n != 0)
			return n;
	}
}

void Console::print(string msg) {
	cout << msg;
}

int Console::getInt(string in) {
	return atoi(in.data()); // atoi()�� 0�� �����ϸ�, �Է¿� ������ �־���
}
