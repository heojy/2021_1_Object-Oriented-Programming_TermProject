#ifndef FRACTION_H
#define FRACTION_H

class CFraction {
	int x, y;
public:
	CFraction(int a=1, int b=1);
	void Print();
	CFraction operator + (CFraction op2);
	friend CFraction operator * (int op1, CFraction op2);
	bool operator < (CFraction op2);
};

#endif