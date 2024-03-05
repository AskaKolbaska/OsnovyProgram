#include "Zadanie1.h"
#include "Pr1.h"
#include "Zadanie2.h"
#include <windows.h>

void Pr2(int otvet) {
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);

	string login = UserName(); // ввод логина

	switch (otvet)
	{
	// запись в файл
	case 1:
		OpenFileWrite(login);
		break;
	// чтение из файла
	case 2:
		ReadStrFromFile();
		break;
	// поиск по логину (!)
	case 3:
		FindUser(login);
		break;
	// очистка файла 
	case 4:
		ClearFile();
		break;
	default:
		cout << "Неправильно введен ответ!" << endl;
		break;
	}
}