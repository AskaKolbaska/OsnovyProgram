#include "Zadanie3.h"
#include <windows.h>

// ���������
void Pr3() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int otvet = 0;
	string newSurname, newFatherName;
	bool luckySession;

	// �������� ���������� ���������
	Student student;

	do
	{ 
		cout << "��� ���������� ������ �������� ������� 1;" << endl
			<< "��� ������ �������� �� ����� ������� 2;" << endl
			<< "��� ������ ������� �������� � ������� ������� 3;" << endl
			<< "��� ��������� ������� ���������� �������� ������� 4;" << endl
			<< "��� ��������� �������� ���������� �������� ������� 5;" << endl
			<< "��� ��������� ������� ��������� � ���������� �������� ������� 6;" << endl
			<< "��� ������ ������� �������� � ���� ������� 7." << endl;
		cin >> otvet;
			switch (otvet)
			{
			// ���� ������ ��������
			case 1:
				student.AddInf();
				break;
			// ������ �������� �� �����
			case 2:
				student = ReadStudentFromFile(student);
				break;
			// ����� ������ � �������
			case 3:
				student.ShowInf();
				break;
			// ��������� �������
			case 4:
				cout << "������� ����� ������� ��������: ";
				cin.clear();
				cin >> newSurname;
				student.ChangeSurname(newSurname);
				break;
			// ��������� ��������
			case 5:
				cout << "������� ����� �������� ��������: ";
				cin.clear();
				cin >> newFatherName;
				student.ChangeFatherName(newFatherName);
				break;
			// ��������� ���������
			case 6:
				cout << "������� ����� �����, ���� ������� ������ ������ �� ���������, ��� 0, ���� ������� ������� ��� ���������: ";
				cin.clear();
				cin >> luckySession;
				student.ChangeScholarship(luckySession);
				break;
			// ������ �������� � ����
			case 7:
				OpenFileWrite(student);
				break;
			default:
				cout << "� �� ���� ������ ������, ������� ��, ��� � ����� ������!" << endl;
				break;
			}
		cout << "������� ���������� ������ �� ����������? ������� 1, ���� ��: ";
		cin.clear();
		cin >> otvet;
	} while (otvet == 1);
}