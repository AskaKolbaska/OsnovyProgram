#pragma once

#include <sstream>
#include <fstream>
#include <iostream>
#include <locale>
#include <Windows.h>
#include <vector>

using namespace std;

// ����� �������
class Student {
private:
	bool isNull = true; // ���������� TRUE - ������ ��� � ����������
	string surname; // �������
	string name; // ���
	string fatherName; // ��������
	tm birthday; // ���� ��������
	int numberCreditBook; // ����� �������� ������
	bool scholarship; // ������� ���������
	

	// �������� �������� ���� isNull � ������, ���� � ���������� ������ ���-�� ���������
	void ChangeIsNull() {
		isNull = false;
	}

public:
	//bool operator==(Student const& rhs) const;

	// ��������� �������
	Student(int p_numberCreditBook, string p_surname = "������", string p_name = "����", string p_fatherName = "��������",
		int p_bDay = 1, int p_bMon = 1, int p_bYear = 2000, bool p_scholarship = 0) {
		surname = p_surname;
		name = p_name;
		fatherName = p_fatherName;
		birthday.tm_mday = p_bDay;
		birthday.tm_mon = p_bMon;
		birthday.tm_year = p_bYear;
		numberCreditBook = p_numberCreditBook;
		scholarship = p_scholarship;
		ChangeIsNull();
	}

	// �����������
	Student(string p_surname, string p_name, string p_fatherName,
		int p_bDay, int p_bMon, int p_bYear, int p_numberCreditBook, bool p_scholarship) {
		surname = p_surname;
		name = p_name;
		fatherName = p_fatherName;
		birthday.tm_mday = p_bDay;
		birthday.tm_mon = p_bMon;
		birthday.tm_year = p_bYear;
		numberCreditBook = p_numberCreditBook;
		scholarship = p_scholarship;
		ChangeIsNull();
	}

	bool operator==(const Student& rhs) const {
		return (isNull == rhs.isNull) &&
			(surname == rhs.surname) &&
			(name == rhs.name) &&
			(fatherName == rhs.fatherName) &&
			(birthday.tm_mday == rhs.birthday.tm_mday) &&
			(birthday.tm_mon == rhs.birthday.tm_mon) &&
			(birthday.tm_year == rhs.birthday.tm_year) &&
			(numberCreditBook == rhs.numberCreditBook) &&
			(scholarship == rhs.scholarship);
	}

	// ������ ��� ������ � ����
	string StrForWrite() {
		string str = to_string(numberCreditBook) + " "
			+ surname + " "
			+ name + " "
			+ fatherName + " "
			+ to_string(birthday.tm_mday) + " "
			+ to_string(birthday.tm_mon) + " "
			+ to_string(birthday.tm_year) + " "
			+ to_string(scholarship);

		return str;
	}

	// ����� ����������
	void ShowInf() {
		cout << "�������: " << surname << endl;
		cout << "���: " << name << endl;
		cout << "��������: " << fatherName << endl;
		cout << "���� ��������: " << birthday.tm_mday << "." << birthday.tm_mon << "." << birthday.tm_year << endl;
		cout << "����� �������� ������: " << numberCreditBook << endl;
		if (scholarship)
		{
			cout << "������ �� ���������." << endl;
		}
		else
		{
			cout << "������ ��� ���������." << endl;
		}
	}

	// ����� �������
	void ChangeSurname(string newSurname) {
		surname = newSurname;
	}

	// ����� ��������
	void ChangeFatherName(string newFatherName) {
		fatherName = newFatherName;
	}

	// ��������� ���������� � ���������
	void ChangeScholarship(bool luckySession) {
		// ���� ������ ������� �� 4-5
		if (luckySession) {
			scholarship = true; // ���� ���������
		}
		else {
			scholarship = false; // ��� ���������
		}
	}
};

// �������� ������ �������� �������
Student CreateStudentByHands();

// ������ ��������� �� �����
vector<Student> ReadStudentsFromFile();

// �������� ����� �� �������
bool isEmpty();

// �������� �������� � ����
void AddStudent(Student);

// ���������� ������ � �����
void RewriteStudents(vector<Student>);