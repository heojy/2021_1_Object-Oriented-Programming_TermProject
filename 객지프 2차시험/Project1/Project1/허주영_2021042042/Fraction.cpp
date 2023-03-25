#include "Fraction.h"
#include <iostream>
using namespace std;

CFraction::CFraction(int a, int b) {
	x = a;
	y = b;
}

void CFraction::Print() {
	cout << x << "/" << y << endl;
}

CFraction CFraction::operator + (CFraction op2) {
	CFraction tmp;
	int t = this->y / op2.y;
	int p = op2.y / this->y;

	if (this->y == op2.y) {
		tmp.x = this->x + op2.x;
		tmp.y = op2.y;
	}

	else if (this->y > op2.y){
		tmp.x = this->x + (op2.x * t);
		tmp.y = this->y;
	}

	else {
		tmp.x = (this->x * p) + op2.x;
		tmp.y = op2.y;
	}
	return tmp;
}

CFraction operator * (int op1, CFraction op2) {
	CFraction tmp;
	tmp.x = op1 * op2.x;
	tmp.y = op2.y;
	return tmp;
}

bool CFraction::operator < (CFraction op2) {
	if ((x / y) < (op2.x / op2.y))
		return true;
	else
		return false;

}