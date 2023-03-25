#include <iostream>
using namespace std;

class CArrayF {
private: 
	double *aptr;
	int arraySize;

public:
	CArrayF(int s);
	int size();
	void push_back(double data);
	void setData(int index, double data);
	void Print();
	~CArrayF();
	
};