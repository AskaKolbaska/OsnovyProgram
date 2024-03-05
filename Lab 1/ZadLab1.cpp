#include "Zadanie4.h"
#include "ZadLab1.h"

// �������� ������ ��������
Student CreateOneStudent() {
	int otvet = 0, numberCreditBook = 0;
	string newSurname, newFatherName;
	bool luckySession;

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
		{
			cout << "������� ����� ������� ��������: ";
			cin.clear();
			cin >> newSurname;
			system("cls");
			exampleStudent.ChangeSurname(newSurname);
			break;
		}
		// ����� ��������
		case 2:
		{
			cout << "������� ����� �������� ��������: ";
			cin.clear();
			cin >> newFatherName;
			system("cls");
			exampleStudent.ChangeFatherName(newFatherName);
			break;
		}
		// ��������� ���������
		case 3:
		{
			cout << "������� ����� �����, ���� ������� ������ ������ �� ���������, ��� 0, ���� ������� ������� ��� ���������: ";
			cin.clear();
			cin >> luckySession;
			system("cls");
			exampleStudent.ChangeScholarship(luckySession);
			break;
		}
		default:
		{
			cout << "� �� ���� ������ ������, ������� ��, ��� � ����� ������!" << endl;
			break;
		}
		}
	} while (otvet == 1);

	return exampleStudent;
}
