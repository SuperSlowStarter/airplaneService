// �� ������Ʈ�� ������� �Է� ������ ��� �ɷ������� �ۼ��� ������ �����Դϴ� 
#include <string>
using namespace std;

#include "AirlineBook.h"
#include "User.h"

int main(){
	string sheduleTime[] = {"07��", "12��", "17��"};
	AirlineBook *p = new AirlineBook("�Ѽ��װ�", 3, sheduleTime);
	
	p->run();
	
	delete p;
}

// editted from labtop 2
