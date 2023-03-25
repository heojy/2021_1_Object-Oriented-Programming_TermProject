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
		cout << ">> 메뉴 - 추가(1), 삭제(2), 정렬(3), 출력(4), 파일저장(5), 종료(0) : ";
		cin >> menu;

		if (menu == 1)
		{
			cout << "값, 위치(?번째 앞) : ";
			cin >> data >> index;
			v.add(data, index);
		}

		else if (menu == 2)
		{
			cout << "위치 : ";
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