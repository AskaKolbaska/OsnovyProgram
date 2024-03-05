#pragma once

#include <math.h>
#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>

using namespace std;

// ��������� �������
struct Student
{
	bool isNull = true; // ���������� TRUE - ������ ��� � ���������
	string surname; // �������
	string name; // ���
	string fatherName; // ��������
	tm birthday; // ���� ��������
	int numberCreditBook; // ����� �������� ������
	bool scholarship; // ������� ���������

	// ���� ����������
	void AddInf() {
		isNull = false;
		cout << "������� ������� ��������: ";
		cin >> surname;
		cout << "������� ��� ��������: ";
		cin >> name;
		cout << "������� �������� ��������: ";
		cin >> fatherName;
		cout << "������� ���� �������� ��������: " << endl;
		cout << "����: ";
		cin >> birthday.tm_mday;
		cout << "�����: ";
		cin >> birthday.tm_mon;
		cout << "���: ";
		cin >> birthday.tm_year;
		cout << "������� ����� �������� ������ ��������: ";
		cin >> numberCreditBook;
		cout << "������ �� ������� �� ���������? ������� 1, ���� ��, � 0, ���� ���: ";
		cin >> scholarship;
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

void OpenFileWrite(Student);

Student ReadStudentFromFile(Student);