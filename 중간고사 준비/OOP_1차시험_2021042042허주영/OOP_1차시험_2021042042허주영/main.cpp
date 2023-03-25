#include "ArrayF.h"

int main(void) {
	CArrayF table1(10);
	CArrayF table2(15);

	table1.Print();
	table2.Print();

	cout << "Table1 size : " << table1.size() << endl;
	cout << "Table2 size : " << table2.size() << endl;

	table1.push_back(12.3);
	table1.setData(12, 18.7);
	table1.setData(3, 18.7);
	table2.push_back(22.5);

	table1.Print();
	table2.Print();

	cout << "Table1 size : " << table1.size() << endl;
	cout << "Table2 size : " << table2.size() << endl;

	return 0;
}