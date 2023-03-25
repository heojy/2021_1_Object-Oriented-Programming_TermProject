#include "Fraction.h"
#include <iostream>
using namespace std;

int main() {
	CFraction F1(3, 4);
	F1.Print();
	CFraction F2(3);
	F2.Print();
	CFraction F3 = F1 + F2;
	F3.Print();
	int k = 2;
	CFraction F4 = k * F1;
	F4.Print();

	if (F3 < F4)
		cout << "F3 less than F4" << endl;
	else
		cout << "F4 less than F3" << endl;
	return 0;

}