#include<iostream>
#include<fstream>
#include<algorithm>

#include "vector.h"

using namespace std;

int main()
{
	int menu, index, data;
	vector v;

	while (true)
	{
		cout << ">> �޴� - �߰�(1), ����(2), ����(3), ���(4), ��������(5), ����(0) : ";
		cin >> menu;

		if (menu == 1)
		{
			cout << "��, ��ġ(?��° ��) : ";
			cin >> data >> index;
			v.add(data, index);
		}

		else if (menu == 2)
		{
			cout << "��ġ : ";
			cin >> index;
			v.remove(index);
		}

		else if (menu == 3)
		{
			v.salt();
		}

		else if (menu == 4)
		{
			v.print();
		}

		else if (menu == 5)
		{
			v.saveFile();
		}

		else if (menu == 0)
		{
			break;
		}
	}
}