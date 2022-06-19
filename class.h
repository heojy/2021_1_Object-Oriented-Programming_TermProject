#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class student_info {
	int StudentID;
	map <string, string> Subject_Grade;
	string Department;
	string Password;
	string Name;
	//�л� ���� ���� ��ҵ�. ���� ���� �� ������ map �����̳ʷ� ����.
public:
	student_info() {
		StudentID = 0;
		Name = " ";
		Department = " ";
	}

	void SetInfo(string name, int studentid, string department, string password) {
		Name = name;
		StudentID = studentid;
		Department = department;
		Password = password;
	} // �⺻������ Ŭ������ ������ �Է¹��� ������ �ٲ��ִ� �Լ�.

	void Setgrade() {//������ �Է¹޾� ���� ���� �� ������ �����ϴ� �Լ�
		string subject, grade;
		cout << "\n���� �̸� ��� exit�� �Է��� ��� ����." << endl;
		while (true) { // �������� �Է��� ���� �ݺ�.
			cout << "������ ���� �̸� : "; // ��, ���� �̸��� ���� ������ �Ұ����ϴ�.
			cin >> subject; 
			if (subject == "exit")
				break; // ���� �̸� ��� exit �Է½� �ݺ� ����
			cout << "���� : ";
			cin >> grade;
			if (!cin) { // �߸��� ���·� �Է��� ���
				cout << "�߸� �� �Է�." << endl;
				cin.clear();
				cin.ignore(1000, '/n');
				continue; // �Է¹��۸� ����� �ٽ� �Է¹���.
			}
			Subject_Grade.insert({ subject, grade }); //�Է¹��� ����� ������ ¦���� map�� ����
		}
		cout << endl;
	} 
	
	void SaveInfo() { // �Է¹��� ������ ���Ͽ� ������ִ� �Լ�.
		ofstream fout;
		fout.open("Student_Info.txt",ios::app); 
		//���ٿ� �� ���̹Ƿ� ios::app���� ���� ����. ������ ���� ��� �����Ѵ�.
		
		if (!fout.is_open()) {
			cout << "���� ���� ����" << endl;
		}// ���� ����ó��.
		fout << "\nName : " << Name << "\nStudent ID : " << StudentID << "\nDepartment : " << Department << endl;
		fout << "�������� �� ���� : " << endl;
		for (map<string,string>::iterator it = Subject_Grade.begin(); it != Subject_Grade.end(); it++) {
			fout << "\t" << it->first << " : " << it->second << endl;
		}// �Է¹��� �л������� Student_Info.txt�� ���.
		fout.close();

		fout.open("Login.txt", ios::app);
		if (!fout.is_open()) {
			cout << "���� ���� ����" << endl;
		}
		fout <<  Name << " " << Password << endl;
		// ������ �޴� - �л� �������� �Է¹��� �̸� �� ��й�ȣ�� Login.txt�� ���.
		fout.close();

	}

	void ShowInfo() {
		for (map<string, string>::iterator it = Subject_Grade.begin(); it != Subject_Grade.end(); it++) {
			cout << "\t" << it->first << " : " << it->second << endl;
			//����� ������ ���� map�� ó������ ���鼭 ����� ���� ǥ��.
		}
	}

	friend void ShowAllInfo();
	friend void ShowMyInfo();
	friend void erase(); //private ��� ������ �����ؾ��ϴ� �Լ��鿡�� friend ����.
};


#endif