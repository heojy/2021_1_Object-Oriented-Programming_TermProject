#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>
#include<algorithm>
#include<fstream>

class vector
{
private:
	int size = 0;
	int* list = new int[size];
public:
	void add(int data, int index);
	void remove(int index);
	void salt();
	void print();
	void saveFile();
	~vector();
};

#endif // !VECTOR_H