#include "Zadanie5.h"
#include "ZadLab1.h"
#include "Pr7.h"

// ������������ ��������� �������
void Pr7() {
	int otvet = 0;
	cout << "������� ������ ����� ����� (1) ��� ������ ��������� (2)? " << endl;
	cin >> otvet;
	switch (otvet)
	{
	// int
	case 1: {
		vector<int> data = CreateData<int>(); // �������� ������� ������ ��� ����� � ������
		MyList<int> list_int = CreateList<int>(data); // ���� ������ �� ������� � ������

		list_int.print();

		break;
	}
	// students
	case 2: {
		MyList<Student> list_student = CreateList<Student>();
		break;
	}
	default:
		cout << "����������� ������ �����" << endl;
		break;
	}
}
