#include"class.h"

map<string, string> login_info; // Login 파일의 ID와 Password를 map컨테이너로 저장.
vector<student_info> SL; // 학생 정보 클래스를 vector로 관리.

void adminMenu();
void studentMenu();
void Adminlogin();
void Studentlogin();
void exit(int status);
void erase();
void ShowAllInfo();
void ShowMyInfo(); 

string ID;
string PASSWORD;

void menu() { // 실행 첫 화면.
	int choice = 0;

	cout << "\nAvailiable Login operations:" << endl;
	cout << "1. Admin Login" << endl;
	cout << "2. Student Login" << endl;
	cout << "3. Exit" << endl;
	cout << "\n\nEnter menu : ";

	while (choice != 3) {

		cin >> choice;

		switch (choice) {
		case 1:
			Adminlogin(); // 관리자 로그인 함수 실행.
			break;
		case 2:
			Studentlogin(); // 학생 로그인 함수 실행.
			break;
		case 3:
			cout << "Exit the program." << endl;
			exit(0); // 프로그램 종료.
			break;
		default:
			cout << "Invalid input. Please enter it again. : ";
			// 잘못된 입력 방지.
			break;
		}
	}
}

void adminMenu() { // 관리자 메뉴 함수
	int choice = 0;
	int d_choice = 0;
	while (choice != 5) {
		cout << "\n- Logged in as Admin -" << endl;
		cout << "1. Add Students" << endl;      //학생정보 입력, ID, 비번도 입력
		cout << "2. Delete Students" << endl;   //학생정보 vector에서 지우기
		cout << "3. View Table" << endl;      //학생정보 전부 표시
		cout << "4. Main Menu" << endl;
		cout << "5. Exit" << endl;

		cout << "\n Enter menu : ";

		cin >> choice;
		switch (choice) {
		case 1:
			while(true) { // 연속해서 학생 정보 입력 가능하도록 반복.
				student_info temp; // 기본생성자로 임시학생정보 클래스. 
				string name, department, password;
				int studentid;
				int checker = 0;

				cout << "이름 대신 exit을 입력할 경우 종료." << endl;
				cout << "\n이름 입력 >> ";
				cin >> name;
				if (name == "exit") {
					break; // 이름 대신 exit을 입력할 경우 반복 종료.
				}
				cout << "학번 입력 >> ";
				cin >> studentid;
				cout << "학과 입력 ( 1:EE | 2:IRE | 3:CS | 4:CE | 이외 숫자 : 직접입력 ) >> ";
				cin >> d_choice; // 기본 설정된 4가지 선택지 이외는 직접 입력 받는다.
				switch (d_choice) {
				case 1:
					department = "EE";
					break;
				case 2:
					department = "IRE";
					break;
				case 3:
					department = "CS";
					break;
				case 4:
					department = "CE";
					break;
				default:
					cout << "학과 직접 입력하기 >> ";
					cin >> department;
					break;
				}
				for (map<string, string>::iterator it = login_info.begin(); it != login_info.end(); it++) {
					if (it->first == name) { //로그인 정보가 담긴 map의 처음부터 돌며 입력한 이름과 같은 이름을 찾는다.
						password = it->second;
						checker++;
						//만약 입력한 이름이 map에 있을 경우 Login.txt 파일에 담긴 비밀번호로 설정한다.
					}
				}
				if (checker == 0) {
					cout << "비밀번호 입력 >> ";
					cin >> password;
					//만약 입력한 이름이 Login.txt 파일에 없을 경우 비밀번호를 입력받아 설정한다.
				}
				temp.SetInfo(name, studentid, department, password); // 입력받은 정보로 임시 클래스의 정보를 바꿔주는 함수 호출.
				login_info.insert({ name,password }); // 이름과 비밀번호를 로그인 정보가 담긴 map에 저장.
				temp.Setgrade(); // 정보를 입력받아 수강 과목 및 성적을 저장하는 함수 호출.
				temp.SaveInfo(); // 입력받은 정보를 파일에 출력해주는 함수 호출.
				SL.push_back(temp); // 벡터에 클래스를 넣는다.
			}
			break;
		case 2:
			erase(); // 학생 정보를 지워주는 함수 호출.
			break;
		case 3:
			ShowAllInfo(); //  모든 학생의 모든 정보를 표시하는 함수 호출.
			break;
		case 4:
			cout << endl;
			menu(); // 첫 화면으로 돌아간다.
			break;
		case 5:
			cout << "Exit the program." << endl;
			exit(0); // 프로그램을 종료한다.
			break;
		default:
			cout << "/nInvalid input. Please enter it again. : ";
			 // 예외처리. 다시 입력받는다.
			break;
		}
	}

}

void studentMenu() { // 학생 메뉴 함수.
	int choice = 0;
	while (choice != 3) {
		cout << "\n- Logged in as Student -" << endl;
		cout << "1. View Table" << endl; 
		cout << "2. Main Menu" << endl;
		cout << "3. Exit" << endl;

		cout << "\n Enter menu : ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << endl;
			ShowMyInfo(); // 자신의 모든 정보를 표시해주는 함수 호출.
			break;
		case 2:
			menu(); // 첫 화면으로 돌아간다.
			break;
		case 3:
			cout << "Exit the program." << endl;
			exit(0); // 프로그램을 종료한다.
			break;
		default:
			cout << "Invalid input. Please enter it again. : ";
			break; // 예외처리. 다시 입력받는다.
		}
	}
}

void login_set() { 
	//Login.txt파일에 저장된 정보를 map으로 관리할 수 있게끔 만듦.
	string name, password;
	ifstream fin("Login.txt");

	if (!fin) { // 파일을 열 수 없는 경우 예외처리.
		cout << "파일을 열 수 없습니다." << endl;
	}
	while (!fin.eof()) {
		fin >> name >> password;
		login_info.insert(make_pair(name, password));
		//파일을 열어 띄어쓰기로 나뉜 이름과 비밀번호를 짝지어 map에 저장.
	}
	ofstream fout("Login.txt",ios::app);
	fout << endl;
	fout.close();
}

void Adminlogin() {
	cout << "\nID 입력 >> ";
	cin >> ID;
	cout << "Password 입력 >> ";
	cin >> PASSWORD;

	if (login_info.find(ID) == login_info.end()) {
		cout << "ID를 찾을 수 없습니다." << endl;
		menu();
		// Login.txt에 존재하지 않는 ID인 경우 첫 화면 전환.
	}
	else if (ID != "Admin") {
		cout << "ID가 틀렸습니다." << endl;
		menu();
		// Login.txt에 존재하지만 관리자 ID가 아닌 경우 첫 화면 전환.
	}
	else if (login_info[ID] != PASSWORD) {
		cout << "Password가 틀렸습니다." << endl;
		menu();
		// Login.txt에 존재하는 관리자 ID가 맞지만 비밀번호를 틀린 경우 첫 화면 전환.
	}
	else {
		adminMenu(); //모두 일치하면 관리자 메뉴 함수 실행.
	}
		
}

void Studentlogin() {
	cout << "\nID 입력 >> ";
	cin >> ID;
	cout << "Password 입력 >> ";
	cin >> PASSWORD;

	if (login_info.find(ID) == login_info.end()) {
		cout << "\nID를 찾을 수 없습니다." << endl;
		menu();
		// Login.txt에 존재하지 않는 ID인 경우 첫 화면 전환.
	}
	else if (ID == "Admin") {
		cout << "\n관리자 아이디로 로그인 할 수 없습니다." << endl;
		menu();
		// Login.txt에 존재하지만 관리자 ID를 입력한 경우 첫 화면 전환.
	}
	else if (login_info[ID] != PASSWORD) {
		cout << "\nPassword가 틀렸습니다." << endl;
		menu();
		// Login.txt에 존재하는 관리자 ID가 맞지만 비밀번호를 틀린 경우 첫 화면 전환.
	}
	else
		studentMenu();// 모두 일치하는 경우 학생 메뉴 함수 실행.
}

void erase() { // 학생 정보를 지워주는 함수.
	string name;
	int checker = 0;
	cout << "삭제할 학생의 이름 입력 : ";
	cin >> name;

	for (int i = 0; i < SL.size(); i++) {
		if (SL[i].Name == name) {
			SL.erase(SL.begin() + i);
			login_info.erase(name);
			checker++;
			// 입력받은 이름을 가진 학생 정보 클래스를 벡터에서 삭제하고, 
			// 로그인정보를 담은 map에서도 삭제.
			// 이후 정보가 사라져 로그인 할 수 없게 됌.
		}	
	}
	if (checker == 0) {
		cout << "해당 이름을 가진 학생 없음." << endl;
		adminMenu(); 
		// 잘못된 이름을 입력한 경우 관리자 메뉴 함수로 되돌아감.
	}
}
		

void ShowAllInfo() { // 모든 학생의 모든 정보를 표시하는 함수.

	for (vector<student_info>::iterator itr = SL.begin(); itr != SL.end(); itr++) {
		cout << "\nName : " << itr->Name << "\nStudent ID : " << itr->StudentID << "\nDepartment : " << itr->Department << endl;
		cout << "수강과목 및 성적 : " << endl;
		itr->ShowInfo();
		//벡터의 처음부터 돌며 클래스 원소 하나하나마다 멤버 변수들 출력.
	}
}

void ShowMyInfo() {// 자신의 모든 정보를 표시해주는 함수.
	for (vector<student_info>::iterator itr = SL.begin(); itr != SL.end(); itr++) {
		if (itr->Name == ID) {
			cout << "\nName : " << itr->Name << "\nStudent ID : " << itr->StudentID << "\nDepartment : " << itr->Department << endl;
			cout << "수강과목 및 성적 : " << endl;
			itr->ShowInfo();
			// 벡터의 처음부터 돌며 자신의 이름과 같은 클래스를 찾아, 멤버 변수들 출력.
		}
	}
}	