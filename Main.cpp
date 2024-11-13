#include <string>
#include "AirlineBook.h"
using namespace std;

int main() {
    string scheduleTime[] = { "07시", "12시", "17시" };
    AirlineBook* p = new AirlineBook("한성항공", 3, scheduleTime);
    p->run();

    delete p;
    return 0;
}
