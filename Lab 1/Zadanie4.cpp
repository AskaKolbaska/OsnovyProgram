#include "Zadanie4.h"

// �������� ������ �������� �������
Student CreateStudentByHands() {
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

	Student student(surname, name, fatherName, birthday.tm_mday, birthday.tm_mon, birthday.tm_year,
		numberCreditBook, scholarship);
	return student;
}

// ������ ��������� �� �����
vector<Student> ReadStudentsFromFile() {
	
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

// �������� �������� � ����
void AddStudent(Student student) {
	ofstream in("students.txt", ios::app); // �������� ��� ��������
	if (in.is_open())
	{
		if (isEmpty())
		{
			in << student.StrForWrite();
		}
		else {
			in << endl << student.StrForWrite();
		}
	}
	else
	{
		cout << "������ ������!" << endl;
	}
	
	in.close();
}

// �������� ������� �����
bool isEmpty()
{
	ifstream in("students.txt"); // �������� ����� ��� �������� �� �������
	if (in.peek() == EOF)
	{
		return true; // ���� ����, ���������� ��
	}
	else
	{
		return false;
	}
	in.close();
}

// ���������� ������
void RewriteStudents(vector<Student> students) {
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