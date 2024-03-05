#include "Zadanie3.h"
#include <windows.h>

// структуры
void Pr3() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int otvet = 0;
	string newSurname, newFatherName;
	bool luckySession;

	// создание экземпляра структуры
	Student student;

	do
	{ 
		cout << "Для добавления нового студента введите 1;" << endl
			<< "Для чтения студента из файла введите 2;" << endl
			<< "Для вывода данного студента в консоль введите 3;" << endl
			<< "Для изменения фамилии выбранного студента введите 4;" << endl
			<< "Для изменения отчества выбранного студента введите 5;" << endl
			<< "Для изменения наличия стипендии у выбранного студента введите 6;" << endl
			<< "Для записи данного студента в файл введите 7." << endl;
		cin >> otvet;
			switch (otvet)
			{
			// ввод нового студента
			case 1:
				student.AddInf();
				break;
			// чтение студента из файла
			case 2:
				student = ReadStudentFromFile(student);
				break;
			// вывод данных в консоль
			case 3:
				student.ShowInf();
				break;
			// изменение фамилии
			case 4:
				cout << "Введите новую фамилию студента: ";
				cin.clear();
				cin >> newSurname;
				student.ChangeSurname(newSurname);
				break;
			// изменение отчества
			case 5:
				cout << "Введите новое отчество студента: ";
				cin.clear();
				cin >> newFatherName;
				student.ChangeFatherName(newFatherName);
				break;
			// изменение стипендии
			case 6:
				cout << "Введите любое число, если студент закрыл сессию на стипендию, или 0, если студент остался без стипендии: ";
				cin.clear();
				cin >> luckySession;
				student.ChangeScholarship(luckySession);
				break;
			// запись студента в файл
			case 7:
				OpenFileWrite(student);
				break;
			default:
				cout << "Я не знаю такого ответа, введите то, что я смогу понять!" << endl;
				break;
			}
		cout << "Желаете продолжить работу со студентами? Введите 1, если да: ";
		cin.clear();
		cin >> otvet;
	} while (otvet == 1);
}