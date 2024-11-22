#include <iostream>
#include <string>
#include "User.h"
using namespace std;


void User::setSeatNumber(int inputNumber) {
	this->seatNumber = inputNumber;
}
void User::setReserveTime(int inputTime) {
	this->reserveTime = inputTime;
}
void User::setName(string inputName) {
	this->name = inputName;
}

string User::getUserName() {
	return this->name;
}
int User::getSeatNumber() {
	return this->seatNumber;
}
int User::getReserveTime() {
	return this->reserveTime;
}