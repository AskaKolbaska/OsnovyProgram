#include "Zadanie4.h"
#include "ZadLab1.h"

// создание одного студента
Student CreateOneStudent() {
	int otvet = 0, numberCreditBook = 0;
	string newSurname, newFatherName;
	bool luckySession;

	cout << "Создать шаблонного студента? Введите 1, если да: ";
	cin >> otvet;
	cin.clear();

	if (otvet == 1)
	{
		cout << "Введите номер зачетной книжки: ";
		cin >> numberCreditBook;
	}

	// создание шаблона
	Student exampleStudent(numberCreditBook);

	if (otvet != 1)
	{
		exampleStudent = CreateStudentByHands(); // ввод нового студента с клавиатуры
	}
	exampleStudent.ShowInf();

	// действия над созданным студентом студентом
	do
	{
		cout << "Желаете продолжить работу с этими данными? Введите 1, если да: ";
		cin >> otvet;
		cin.clear();

		if (otvet != 1) {
			break;
		}

		cout << "Выберите действие над студентом:" << endl <<
			"(1) Cмена фамилии;" << endl <<
			"(2) Cмена отчества;" << endl <<
			"(3) Изменение стипендии;" << endl <<
			"(0) Закончить работу со студентом: ";
		cin >> otvet;
		cin.clear();
		system("cls");

		switch (otvet)
		{
		case 0:
			break;
		// смена фамилии
		case 1:
		{
			cout << "Введите новую фамилию студента: ";
			cin.clear();
			cin >> newSurname;
			system("cls");
			exampleStudent.ChangeSurname(newSurname);
			break;
		}
		// смена отчества
		case 2:
		{
			cout << "Введите новое отчество студента: ";
			cin.clear();
			cin >> newFatherName;
			system("cls");
			exampleStudent.ChangeFatherName(newFatherName);
			break;
		}
		// изменение стипендии
		case 3:
		{
			cout << "Введите любое число, если студент закрыл сессию на стипендию, или 0, если студент остался без стипендии: ";
			cin.clear();
			cin >> luckySession;
			system("cls");
			exampleStudent.ChangeScholarship(luckySession);
			break;
		}
		default:
		{
			cout << "Я не знаю такого ответа, введите то, что я смогу понять!" << endl;
			break;
		}
		}
	} while (otvet == 1);

	return exampleStudent;
}
