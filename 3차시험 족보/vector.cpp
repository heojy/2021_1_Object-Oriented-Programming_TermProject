#include "vector.h"
using namespace std;

void renew(int*& oldlist, int oldsize, int newsize)
{
	int* newlist = new int[newsize];
	copy(oldlist, oldlist + oldsize, newlist);
	delete[] oldlist;
	oldlist = newlist;
	newlist = NULL;
}

void vector::add(int data, int index)
{
	try
	{
		if (index > size)
			throw index;
		renew(list, size, ++size);
		for (int i = size - 1; i > index; i--)
			list[i] = list[i - 1];
		list[index] = data;
	}
	catch (int exception)
	{
		cout << "사이즈에 맞는 인덱스를 입력하시오" << endl;
	}
}

void vector::remove(int index)
{
	try
	{
		if (index >= size)
			throw index;
		for (int i = index; i < size; i++)
			list[i] = list[i + 1];
		renew(list, size, --size);
	}
	catch (int exception)
	{
		cout << "사이즈에 맞는 인덱스를 입력하시오" << endl;
	}
}

void vector::salt()
{
	sort(list, list + size);
}

void vector::print()
{
	for (int i = 0; i < size; i++)
		cout << list[i] << ' ';
	cout << endl;
}

void vector::saveFile()
{
	ofstream open("output.txt");
	for (int i = 0; i < size; i++)
		open << list[i] << ' ';
	open.close();
}

vector::~vector()
{
	free(list);
}