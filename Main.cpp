// 이 프로젝트는 사용자의 입력 오류를 모두 걸러내도록 작성된 온전한 버전입니다 

#include <string>
using namespace std;

#include "AirlineBook.h"

int main(){
	string sheduleTime[] = {"07시", "12시", "17시"};
	AirlineBook *p = new AirlineBook("한성항공", 3, sheduleTime);
	p->run();
	
	delete p;
}