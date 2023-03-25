#include "ArrayF.h"

CArrayF::CArrayF(int s) {
	arraySize = s;
	aptr = new double[s];

	for (int i = 0; i < arraySize+1; i++) {
		aptr[i] = i;
	}
}

int CArrayF::size() {
	return arraySize;
}

void CArrayF::push_back(double data) {
	arraySize += 1;
	aptr[arraySize-1] = data;
}

void CArrayF::setData(int index, double data) {
	if (index >= arraySize)
		cout << ">> [Error] : Index out of range. " << endl;
	else
		aptr[index] = data;
}

void CArrayF::Print() {
	cout << "Data: ";
	for (int i = 0; i < arraySize; i++) {
		cout << aptr[i] << ' ';
	}
	cout << endl;
}

CArrayF::~CArrayF() {
}