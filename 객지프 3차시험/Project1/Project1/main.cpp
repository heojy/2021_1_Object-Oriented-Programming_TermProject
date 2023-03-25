#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void Add(vector<int> &v) {
	int data;
	unsigned int index;
	cout << "값, 위치(?번째 앞) : ";
	cin >> data >> index;

	if (index > v.size()) {
		cout << "추가 불가" << endl;
	}
	else {
		v.insert(v.begin() + index, data);
	}
}

void Remove(vector<int> &v) {
	unsigned int index;
	cout << "위치 : ";
	cin >> index;

	if (index >= v.size()) {
		cout << "삭제 불가" << endl;
	}
	else {
		v.erase(v.begin() + index);
	}
}

void Sort(vector<int> &v) {
	int temp, min;
	for (unsigned int i = 0; i < v.size(); i++) {
		int index = INT_MAX;
		int small = INT_MAX;
		for (unsigned int j = i; j < v.size(); j++) {
			if (v.at(j) < small) {
				small = v.at(j);
				index = j;
			}
		}
		temp = small;
		min = v.at(i);
		v.at(i) = temp;
		v.at(index) = min;
	}
}

void Show(vector<int> &v) {
	for (unsigned int i = 0; i < v.size(); i++) {
		cout << v.at(i) << " ";
	}
	cout << endl;
}

void Save(vector<int> &v) {
	ofstream open("output.txt");
	for (unsigned int i = 0; i < v.size(); i++) {
		open << v.at(i) << " ";
	}
	open.close();
}
int main(void) {
	vector<int> v;
	int menu = -1;

	while (menu != 0) {
		cout << " >> 메뉴 - 추가<1>, 삭제<2>, 정렬<3>, 출력<4>, 파일저장<5>, 종료<0> : ";
		cin >> menu;

		switch (menu){
		case 0:
			v.clear();
			break;
		case 1:
			Add(v);
			break;
		case 2:
			Remove(v);
			break;
		case 3:
			Sort(v);
			break;
		case 4:
			Show(v);
			break;
		case 5:
			Save(v);
			break;
		}
	}
}