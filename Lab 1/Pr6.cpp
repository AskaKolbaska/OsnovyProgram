#include "Pr6.h"

void Pr6() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "������������ ������!" << endl << endl;

	// �������� ������� ��������� ��� ������
	vector<Student> studentsForAdd = CreateArrayStudents_Obj();

	// �������� ��������� � ����
	AddArrayStudents_Obj(studentsForAdd);
	cout << "������ ���������!" << endl;

	// ������ �� �����
	vector<Student> studentsAfterReading = ReadStudentsFromFile_Obj();

	if (IfWritingSuccesful(studentsForAdd, studentsAfterReading))
	{
		cout << "������ ������ �������!" << endl;
	}
	else {
		cout << "������ �� �������!" << endl;
	}
}

bool IfWritingSuccesful(vector<Student> studentForAdd, vector<Student> studentAfterReading) {
	int kolvoMAX = studentAfterReading.size(); // ������ ������� ��������� ���������
	int kolvoStud = 0; // ������� ��������� ���������

	for (int i = 0; i < kolvoMAX; i++)
	{
		for (int j = 0; j < studentForAdd.size(); j++)
		{
			if (studentForAdd[j] == studentAfterReading[i]) {
				// ���� ������� �� ����� � ������� ��� ������ ��������� � �������� + 1
				kolvoStud += 1;
			}
		}
	}

	if (kolvoStud == studentForAdd.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}