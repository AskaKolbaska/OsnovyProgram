#include "Zadanie1.h"
#include "Pr1.h"
#include "Zadanie2.h"
#include <windows.h>

void Pr2(int otvet) {
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);

	string login = UserName(); // ���� ������

	switch (otvet)
	{
	// ������ � ����
	case 1:
		OpenFileWrite(login);
		break;
	// ������ �� �����
	case 2:
		ReadStrFromFile();
		break;
	// ����� �� ������ (!)
	case 3:
		FindUser(login);
		break;
	// ������� ����� 
	case 4:
		ClearFile();
		break;
	default:
		cout << "����������� ������ �����!" << endl;
		break;
	}
}