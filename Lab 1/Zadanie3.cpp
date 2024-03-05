using namespace std;
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>
#include "Zadanie3.h"

// ������ � ���� ���������
void OpenFileWrite(Student student) {
	// ���� � ��������� ������ ���
	if (student.isNull)
	{
		cout << "��� ������ ��� ������!" << endl;
	}
	else {
		ofstream in("student.txt"); // �������� ����� ��� ���������� ������
		if (in.is_open())
		{
			in << student.numberCreditBook << " "
				<< student.surname << " "
				<< student.name << " "
				<< student.fatherName << " "
				<< student.birthday.tm_mday << " " << student.birthday.tm_mon << " " << student.birthday.tm_year << " "
				<< student.scholarship
				<< endl;
		}
		in.close();
		cout << "������ ���������!" << endl;
	}
}

// ������ �� ����� ���������
Student ReadStudentFromFile(Student student) {
	string data[8]; // ������ ��� ������ �� ������ (����� �������, �������, ���, ��������, ���� ��������, ������� ���������)
	string str; // ������ �� �����
	ifstream out("student.txt");
	if (out.is_open()) {
		getline(out, str); // ��������� ������ �� �����
		stringstream ss(str); // �������� ���������� ������ �� ���������� ������
		string word; // ���������� ��� "�����" �� ������
		int i = 0;
		while (ss >> word) {
			data[i] = word;
			i++;
		}

		student.isNull = false;
		student.numberCreditBook = stoi(data[0]);
		student.surname = data[1];
		student.name = data[2];
		student.fatherName = data[3];
		student.birthday.tm_mday = stoi(data[4]);
		student.birthday.tm_mon = stoi(data[5]);
		student.birthday.tm_year = stoi(data[6]);
		student.scholarship = stoi(data[7]);

		cout << "������ �������!" << endl;
	}
	else {
		cout << "������ �������� �����!" << endl;
	}
	out.close();
	// ������� ���������
	return student;
}