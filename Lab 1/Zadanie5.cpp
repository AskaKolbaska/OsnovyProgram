#include "Zadanie4.h"
#include "Zadanie5.h"

// ������ ��������� � ������ ��������
vector<Student> ReadStudentsFromFile_Obj() {

	string data[8]; // ������ ��� ������ �� ������ (����� �������, �������, ���, ��������, ���� ��������, ������� ���������)
	string str; // ������ �� �����
	int numberStr = 0; // ���������� ����� � �����

	vector<Student> students; // ������ �� ����������

	ifstream out("students.txt");

	if (out.is_open()) {
		// ������� ���-�� ����� � �����
		while (getline(out, str)) {
			numberStr++;
		}

		out.clear();
		out.seekg(0);

		// ���� ������ �� ����� � ������ �� ����������
		while (getline(out, str)) {
			stringstream ss(str); // �������� ���������� ������ �� ���������� ������
			string word; // ���������� ��� "�����" �� ������

			int i = 0;

			// ������� ������� ������ �� ������
			while (ss >> word) {
				data[i] = word;
				i++;
			}

			// ���������� ��� ��������
			Student exampleStud(data[1], data[2], data[3], stoi(data[4]), stoi(data[5]), stoi(data[6]), stoi(data[0]), stoi(data[7]));

			// ���������� �������� � ������ students
			students.push_back(exampleStud);
		}
	}
	else {
		cout << "������ �������� �����!" << endl;
	}
	out.close();
	return students;
}

// ������ ��������� � ������ ����������
vector<Student*> ReadStudentsFromFile_Points() {

	string data[8]; // ������ ��� ������ �� ������ (����� �������, �������, ���, ��������, ���� ��������, ������� ���������)
	string str; // ������ �� �����
	int numberStr = 0; // ���������� ����� � �����

	vector<Student*> students; // ������ � ����������� �� ���������

	ifstream out("students.txt");

	if (out.is_open()) {
		// ������� ���-�� ����� � �����
		while (getline(out, str)) {
			numberStr++;
		}

		out.clear();
		out.seekg(0);

		// ���� ������ �� ����� � ������ � �����������
		while (getline(out, str)) {
			stringstream ss(str); // �������� ���������� ������ �� ���������� ������
			string word; // ���������� ��� "�����" �� ������

			int i = 0;

			// ������� ������� ������ �� ������
			while (ss >> word) {
				data[i] = word;
				i++;
			}

			// ���������� ��� ��������� �� ��������
			Student* exampleStudent = new Student(data[1], data[2], data[3], stoi(data[4]), stoi(data[5]), stoi(data[6]), stoi(data[0]), stoi(data[7]));
			// Student exampleStud(data[1], data[2], data[3], stoi(data[4]), stoi(data[5]), stoi(data[6]), stoi(data[0]), stoi(data[7]));

			// ���������� �������� � ������ students
			students.push_back(exampleStudent);
		}
	}
	else {
		cout << "������ �������� �����!" << endl;
	}
	out.close();
	return students;
}

// �������� ��������� �������� �������
Student* CreateStudentByHands_Point() {
	// ������ ��� �����
	string surname, name, fatherName;
	int numberCreditBook;
	bool scholarship;
	tm birthday;

	cout << "������� ������� ��������: ";
	cin.clear();
	cin >> surname;
	cout << "������� ��� ��������: ";
	cin.clear();
	cin >> name;
	cout << "������� �������� ��������: ";
	cin.clear();
	cin >> fatherName;
	cout << "������� ���� �������� ��������: " << endl;
	cout << "����: ";
	cin.clear();
	cin >> birthday.tm_mday;
	cout << "�����: ";
	cin.clear();
	cin >> birthday.tm_mon;
	cout << "���: ";
	cin.clear();
	cin >> birthday.tm_year;
	cout << "������� ����� �������� ������ ��������: ";
	cin.clear();
	cin >> numberCreditBook;
	cout << "������ �� ������� �� ���������? ������� 1, ���� ��, � 0, ���� ���: ";
	cin.clear();
	cin >> scholarship;

	Student* student = new Student(surname, name, fatherName, birthday.tm_mday, birthday.tm_mon, birthday.tm_year,
		numberCreditBook, scholarship);
	return student;
}

// �������� ������� �������� ���������
vector<Student> CreateArrayStudents_Obj() {
	int otvet = 0, numberCreditBook = 0;
	string newSurname, newFatherName;
	bool luckySession;

	vector<Student> students;

	// ���� ����� ���������
	do
	{
		cout << "������� ���������� ��������? ������� 1, ���� ��: ";
		cin >> otvet;
		cin.clear();

		if (otvet == 1)
		{
			cout << "������� ����� �������� ������: ";
			cin >> numberCreditBook;
		}

		// �������� �������
		Student exampleStudent(numberCreditBook);

		if (otvet != 1)
		{
			exampleStudent = CreateStudentByHands(); // ���� ������ �������� � ����������
		}
		exampleStudent.ShowInf();

		// �������� ��� ��������� ��������� ���������
		do
		{
			cout << "������� ���������� ������ � ����� �������? ������� 1, ���� ��: ";
			cin >> otvet;
			cin.clear();

			if (otvet != 1) {
				break;
			}

			cout << "�������� �������� ��� ���������:" << endl <<
				"(1) C���� �������;" << endl <<
				"(2) C���� ��������;" << endl <<
				"(3) ��������� ���������;" << endl <<
				"(0) ��������� ������ �� ���������: ";
			cin >> otvet;
			cin.clear();
			system("cls");

			switch (otvet)
			{
			case 0:
				break;
				// ����� �������
			case 1:
				cout << "������� ����� ������� ��������: ";
				cin.clear();
				cin >> newSurname;
				system("cls");
				exampleStudent.ChangeSurname(newSurname);
				break;
				// ����� ��������
			case 2:
				cout << "������� ����� �������� ��������: ";
				cin.clear();
				cin >> newFatherName;
				system("cls");
				exampleStudent.ChangeFatherName(newFatherName);
				break;
				// ��������� ���������
			case 3:
				cout << "������� ����� �����, ���� ������� ������ ������ �� ���������, ��� 0, ���� ������� ������� ��� ���������: ";
				cin.clear();
				cin >> luckySession;
				system("cls");
				exampleStudent.ChangeScholarship(luckySession);
				break;
				// ���������� ������
			default:
				cout << "� �� ���� ������ ������, ������� ��, ��� � ����� ������!" << endl;
				break;
			}
		} while (otvet == 1);

		students.push_back(exampleStudent);

		cout << "��������� ���� ���������? ������� 1, ���� ��: ";
		cin >> otvet;
		cin.clear();
	} while (otvet != 1);

	return students;
}

// �������� ������� ���������� �� ���������
vector<Student*> CreateArrayStudents_Points() {
	int otvet = 1, numberCreditBook = 0;
	string newSurname, newFatherName;
	bool luckySession;

	//vector<Student> objStudents; // ������ ��������
	vector<Student*> pointStudents; // ������ ����������

	// ���� ����� ���������
	do
	{
		cout << "������� ���������� ��������? ������� 1, ���� ��: ";
		cin >> otvet;
		cin.clear();

		if (otvet == 1)
		{
			cout << "������� ����� �������� ������: ";
			cin >> numberCreditBook;
		}

		// �������� �������
		Student* exampleStudent = new Student(numberCreditBook);
		//Student* pointStudent = &exampleStudent;

		if (otvet != 1)
		{
			exampleStudent = CreateStudentByHands_Point(); // ���� ������ �������� � ����������
		}
		exampleStudent->ShowInf();

		// �������� ��� ��������� ��������� ���������
		do
		{
			cout << "������� ���������� ������ � ����� �������? ������� 1, ���� ��: ";
			cin >> otvet;
			cin.clear();

			if (otvet != 1) {
				break;
			}

			cout << "�������� �������� ��� ���������:" << endl <<
				"(1) C���� �������;" << endl <<
				"(2) C���� ��������;" << endl <<
				"(3) ��������� ���������;" << endl <<
				"(0) ��������� ������ �� ���������: ";
			cin >> otvet;
			cin.clear();
			system("cls");

			switch (otvet)
			{
			case 0:
				break;
				// ����� �������
			case 1:
				cout << "������� ����� ������� ��������: ";
				cin.clear();
				cin >> newSurname;
				system("cls");
				exampleStudent->ChangeSurname(newSurname);
				break;
				// ����� ��������
			case 2:
				cout << "������� ����� �������� ��������: ";
				cin.clear();
				cin >> newFatherName;
				system("cls");
				exampleStudent->ChangeFatherName(newFatherName);
				break;
				// ��������� ���������
			case 3:
				cout << "������� ����� �����, ���� ������� ������ ������ �� ���������, ��� 0, ���� ������� ������� ��� ���������: ";
				cin.clear();
				cin >> luckySession;
				system("cls");
				exampleStudent->ChangeScholarship(luckySession);
				break;
				// ���������� ������
			default:
				cout << "� �� ���� ������ ������, ������� ��, ��� � ����� ������!" << endl;
				break;
			}
		} while (otvet == 1);

		pointStudents.push_back(exampleStudent);

		cout << "��������� ���� ���������? ������� 1, ���� ��: ";
		cin >> otvet;
		cin.clear();
	} while (otvet != 1);

	return pointStudents;
}

// ���������� ������ (objects)
void RewriteStudents_Obj(vector<Student> students) {
	ofstream in("students.txt"); // �������� ����� ��� ����������
	if (in.is_open())
	{
		for (int i = 0; i < students.size(); i++)
		{
			in << students[i].StrForWrite();

			if (i != students.size() - 1) { // ���� ��� �� ��������� �������
				in << endl;
			}
		}
	}
	else
	{
		cout << "������ ������!" << endl;
	}
	in.close();
}

// ���������� ������ (points)
void RewriteStudents_Points(vector<Student*> students) {
	ofstream in("students.txt"); // �������� ����� ��� ����������
	if (in.is_open())
	{
		for (int i = 0; i < students.size(); i++)
		{
			in << students[i]->StrForWrite();

			if (i != students.size() - 1) { // ���� ��� �� ��������� �������
				in << endl;
			}
		}
	}
	else
	{
		cout << "������ ������!" << endl;
	}
	in.close();
}

// ����� ������� ������ (�������)
void ShowStudents_Obj(vector<Student> students) {
	cout << "���������� ������:" << endl << endl;
	for (int i = 0; i < students.size(); i++)
	{
		cout << "������� �" << i+1 << ":" << endl << endl;
		students[i].ShowInf();
	}
}

// ����� ������� ������ (���������)
void ShowStudents_Points(vector<Student*> students) {
	cout << "���������� ������:" << endl << endl;
	for (int i = 0; i < students.size(); i++)
	{
		cout << "������� �" << i+1 << ":" << endl << endl;
		students[i]->ShowInf();
	}
}

// �������� ������� �������� � ����
void AddArrayStudents_Obj(vector<Student> students) {
	for (int i = 0; i < students.size(); i++)
	{
		AddStudent(students[i]);
	}
}

// �������� ������� ���������� � ����
void AddArrayStudents_Points(vector<Student*> students) {
	for (int i = 0; i < students.size(); i++)
	{
		AddStudent(*students[i]);
	}
}