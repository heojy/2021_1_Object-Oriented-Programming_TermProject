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
	//학생 정보 구성 요소들. 수강 과목 및 성적은 map 컨테이너로 관리.
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
	} // 기본생성된 클래스의 정보를 입력받은 정보로 바꿔주는 함수.

	void Setgrade() {//정보를 입력받아 수강 과목 및 성적을 저장하는 함수
		string subject, grade;
		cout << "\n과목 이름 대신 exit을 입력할 경우 종료." << endl;
		while (true) { // 연속적인 입력을 위해 반복.
			cout << "수강한 과목 이름 : "; // 단, 과목 이름에 띄어쓰기 포함이 불가능하다.
			cin >> subject; 
			if (subject == "exit")
				break; // 과목 이름 대신 exit 입력시 반복 종료
			cout << "성적 : ";
			cin >> grade;
			if (!cin) { // 잘못된 형태로 입력할 경우
				cout << "잘못 된 입력." << endl;
				cin.clear();
				cin.ignore(1000, '/n');
				continue; // 입력버퍼를 지우고 다시 입력받음.
			}
			Subject_Grade.insert({ subject, grade }); //입력받은 과목과 성적을 짝지어 map에 저장
		}
		cout << endl;
	} 
	
	void SaveInfo() { // 입력받은 정보를 파일에 출력해주는 함수.
		ofstream fout;
		fout.open("Student_Info.txt",ios::app); 
		//덧붙여 쓸 것이므로 ios::app으로 파일 열기. 파일이 없는 경우 생성한다.
		
		if (!fout.is_open()) {
			cout << "파일 열기 오류" << endl;
		}// 오류 예외처리.
		fout << "\nName : " << Name << "\nStudent ID : " << StudentID << "\nDepartment : " << Department << endl;
		fout << "수강과목 및 성적 : " << endl;
		for (map<string,string>::iterator it = Subject_Grade.begin(); it != Subject_Grade.end(); it++) {
			fout << "\t" << it->first << " : " << it->second << endl;
		}// 입력받은 학생정보를 Student_Info.txt에 출력.
		fout.close();

		fout.open("Login.txt", ios::app);
		if (!fout.is_open()) {
			cout << "파일 열기 오류" << endl;
		}
		fout <<  Name << " " << Password << endl;
		// 관리자 메뉴 - 학생 생성으로 입력받은 이름 및 비밀번호를 Login.txt에 출력.
		fout.close();

	}

	void ShowInfo() {
		for (map<string, string>::iterator it = Subject_Grade.begin(); it != Subject_Grade.end(); it++) {
			cout << "\t" << it->first << " : " << it->second << endl;
			//과목과 성적을 담은 map을 처음부터 돌면서 과목과 성적 표시.
		}
	}

	friend void ShowAllInfo();
	friend void ShowMyInfo();
	friend void erase(); //private 멤버 변수에 접근해야하는 함수들에게 friend 선언.
};


#endif