#include"class.h"

map<string, string> login_info; // Login ������ ID�� Password�� map�����̳ʷ� ����.
vector<student_info> SL; // �л� ���� Ŭ������ vector�� ����.

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

void menu() { // ���� ù ȭ��.
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
			Adminlogin(); // ������ �α��� �Լ� ����.
			break;
		case 2:
			Studentlogin(); // �л� �α��� �Լ� ����.
			break;
		case 3:
			cout << "Exit the program." << endl;
			exit(0); // ���α׷� ����.
			break;
		default:
			cout << "Invalid input. Please enter it again. : ";
			// �߸��� �Է� ����.
			break;
		}
	}
}

void adminMenu() { // ������ �޴� �Լ�
	int choice = 0;
	int d_choice = 0;
	while (choice != 5) {
		cout << "\n- Logged in as Admin -" << endl;
		cout << "1. Add Students" << endl;      //�л����� �Է�, ID, ����� �Է�
		cout << "2. Delete Students" << endl;   //�л����� vector���� �����
		cout << "3. View Table" << endl;      //�л����� ���� ǥ��
		cout << "4. Main Menu" << endl;
		cout << "5. Exit" << endl;

		cout << "\n Enter menu : ";

		cin >> choice;
		switch (choice) {
		case 1:
			while(true) { // �����ؼ� �л� ���� �Է� �����ϵ��� �ݺ�.
				student_info temp; // �⺻�����ڷ� �ӽ��л����� Ŭ����. 
				string name, department, password;
				int studentid;
				int checker = 0;

				cout << "�̸� ��� exit�� �Է��� ��� ����." << endl;
				cout << "\n�̸� �Է� >> ";
				cin >> name;
				if (name == "exit") {
					break; // �̸� ��� exit�� �Է��� ��� �ݺ� ����.
				}
				cout << "�й� �Է� >> ";
				cin >> studentid;
				cout << "�а� �Է� ( 1:EE | 2:IRE | 3:CS | 4:CE | �̿� ���� : �����Է� ) >> ";
				cin >> d_choice; // �⺻ ������ 4���� ������ �ܴ̿� ���� �Է� �޴´�.
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
					cout << "�а� ���� �Է��ϱ� >> ";
					cin >> department;
					break;
				}
				for (map<string, string>::iterator it = login_info.begin(); it != login_info.end(); it++) {
					if (it->first == name) { //�α��� ������ ��� map�� ó������ ���� �Է��� �̸��� ���� �̸��� ã�´�.
						password = it->second;
						checker++;
						//���� �Է��� �̸��� map�� ���� ��� Login.txt ���Ͽ� ��� ��й�ȣ�� �����Ѵ�.
					}
				}
				if (checker == 0) {
					cout << "��й�ȣ �Է� >> ";
					cin >> password;
					//���� �Է��� �̸��� Login.txt ���Ͽ� ���� ��� ��й�ȣ�� �Է¹޾� �����Ѵ�.
				}
				temp.SetInfo(name, studentid, department, password); // �Է¹��� ������ �ӽ� Ŭ������ ������ �ٲ��ִ� �Լ� ȣ��.
				login_info.insert({ name,password }); // �̸��� ��й�ȣ�� �α��� ������ ��� map�� ����.
				temp.Setgrade(); // ������ �Է¹޾� ���� ���� �� ������ �����ϴ� �Լ� ȣ��.
				temp.SaveInfo(); // �Է¹��� ������ ���Ͽ� ������ִ� �Լ� ȣ��.
				SL.push_back(temp); // ���Ϳ� Ŭ������ �ִ´�.
			}
			break;
		case 2:
			erase(); // �л� ������ �����ִ� �Լ� ȣ��.
			break;
		case 3:
			ShowAllInfo(); //  ��� �л��� ��� ������ ǥ���ϴ� �Լ� ȣ��.
			break;
		case 4:
			cout << endl;
			menu(); // ù ȭ������ ���ư���.
			break;
		case 5:
			cout << "Exit the program." << endl;
			exit(0); // ���α׷��� �����Ѵ�.
			break;
		default:
			cout << "/nInvalid input. Please enter it again. : ";
			 // ����ó��. �ٽ� �Է¹޴´�.
			break;
		}
	}

}

void studentMenu() { // �л� �޴� �Լ�.
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
			ShowMyInfo(); // �ڽ��� ��� ������ ǥ�����ִ� �Լ� ȣ��.
			break;
		case 2:
			menu(); // ù ȭ������ ���ư���.
			break;
		case 3:
			cout << "Exit the program." << endl;
			exit(0); // ���α׷��� �����Ѵ�.
			break;
		default:
			cout << "Invalid input. Please enter it again. : ";
			break; // ����ó��. �ٽ� �Է¹޴´�.
		}
	}
}

void login_set() { 
	//Login.txt���Ͽ� ����� ������ map���� ������ �� �ְԲ� ����.
	string name, password;
	ifstream fin("Login.txt");

	if (!fin) { // ������ �� �� ���� ��� ����ó��.
		cout << "������ �� �� �����ϴ�." << endl;
	}
	while (!fin.eof()) {
		fin >> name >> password;
		login_info.insert(make_pair(name, password));
		//������ ���� ����� ���� �̸��� ��й�ȣ�� ¦���� map�� ����.
	}
	ofstream fout("Login.txt",ios::app);
	fout << endl;
	fout.close();
}

void Adminlogin() {
	cout << "\nID �Է� >> ";
	cin >> ID;
	cout << "Password �Է� >> ";
	cin >> PASSWORD;

	if (login_info.find(ID) == login_info.end()) {
		cout << "ID�� ã�� �� �����ϴ�." << endl;
		menu();
		// Login.txt�� �������� �ʴ� ID�� ��� ù ȭ�� ��ȯ.
	}
	else if (ID != "Admin") {
		cout << "ID�� Ʋ�Ƚ��ϴ�." << endl;
		menu();
		// Login.txt�� ���������� ������ ID�� �ƴ� ��� ù ȭ�� ��ȯ.
	}
	else if (login_info[ID] != PASSWORD) {
		cout << "Password�� Ʋ�Ƚ��ϴ�." << endl;
		menu();
		// Login.txt�� �����ϴ� ������ ID�� ������ ��й�ȣ�� Ʋ�� ��� ù ȭ�� ��ȯ.
	}
	else {
		adminMenu(); //��� ��ġ�ϸ� ������ �޴� �Լ� ����.
	}
		
}

void Studentlogin() {
	cout << "\nID �Է� >> ";
	cin >> ID;
	cout << "Password �Է� >> ";
	cin >> PASSWORD;

	if (login_info.find(ID) == login_info.end()) {
		cout << "\nID�� ã�� �� �����ϴ�." << endl;
		menu();
		// Login.txt�� �������� �ʴ� ID�� ��� ù ȭ�� ��ȯ.
	}
	else if (ID == "Admin") {
		cout << "\n������ ���̵�� �α��� �� �� �����ϴ�." << endl;
		menu();
		// Login.txt�� ���������� ������ ID�� �Է��� ��� ù ȭ�� ��ȯ.
	}
	else if (login_info[ID] != PASSWORD) {
		cout << "\nPassword�� Ʋ�Ƚ��ϴ�." << endl;
		menu();
		// Login.txt�� �����ϴ� ������ ID�� ������ ��й�ȣ�� Ʋ�� ��� ù ȭ�� ��ȯ.
	}
	else
		studentMenu();// ��� ��ġ�ϴ� ��� �л� �޴� �Լ� ����.
}

void erase() { // �л� ������ �����ִ� �Լ�.
	string name;
	int checker = 0;
	cout << "������ �л��� �̸� �Է� : ";
	cin >> name;

	for (int i = 0; i < SL.size(); i++) {
		if (SL[i].Name == name) {
			SL.erase(SL.begin() + i);
			login_info.erase(name);
			checker++;
			// �Է¹��� �̸��� ���� �л� ���� Ŭ������ ���Ϳ��� �����ϰ�, 
			// �α��������� ���� map������ ����.
			// ���� ������ ����� �α��� �� �� ���� ��.
		}	
	}
	if (checker == 0) {
		cout << "�ش� �̸��� ���� �л� ����." << endl;
		adminMenu(); 
		// �߸��� �̸��� �Է��� ��� ������ �޴� �Լ��� �ǵ��ư�.
	}
}
		

void ShowAllInfo() { // ��� �л��� ��� ������ ǥ���ϴ� �Լ�.

	for (vector<student_info>::iterator itr = SL.begin(); itr != SL.end(); itr++) {
		cout << "\nName : " << itr->Name << "\nStudent ID : " << itr->StudentID << "\nDepartment : " << itr->Department << endl;
		cout << "�������� �� ���� : " << endl;
		itr->ShowInfo();
		//������ ó������ ���� Ŭ���� ���� �ϳ��ϳ����� ��� ������ ���.
	}
}

void ShowMyInfo() {// �ڽ��� ��� ������ ǥ�����ִ� �Լ�.
	for (vector<student_info>::iterator itr = SL.begin(); itr != SL.end(); itr++) {
		if (itr->Name == ID) {
			cout << "\nName : " << itr->Name << "\nStudent ID : " << itr->StudentID << "\nDepartment : " << itr->Department << endl;
			cout << "�������� �� ���� : " << endl;
			itr->ShowInfo();
			// ������ ó������ ���� �ڽ��� �̸��� ���� Ŭ������ ã��, ��� ������ ���.
		}
	}
}	