#pragma once

#include <math.h>
#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>

using namespace std;

// структура Студент
struct Student
{
	bool isNull = true; // изначально TRUE - ничего нет в структуре
	string surname; // фамилия
	string name; // имя
	string fatherName; // отчество
	tm birthday; // дата рождения
	int numberCreditBook; // номер зачетной книжки
	bool scholarship; // наличие стипендии

	// ввод информации
	void AddInf() {
		isNull = false;
		cout << "Введите фамилию студента: ";
		cin >> surname;
		cout << "Введите имя студента: ";
		cin >> name;
		cout << "Введите отчество студента: ";
		cin >> fatherName;
		cout << "Введите дату рождения студента: " << endl;
		cout << "День: ";
		cin >> birthday.tm_mday;
		cout << "Месяц: ";
		cin >> birthday.tm_mon;
		cout << "Год: ";
		cin >> birthday.tm_year;
		cout << "Введите номер зачетной книжки студента: ";
		cin >> numberCreditBook;
		cout << "Учится ли человек на стипендию? Введите 1, если да, и 0, если нет: ";
		cin >> scholarship;
	}

	// вывод информации
	void ShowInf() {
		cout << "Фамилия: " << surname << endl;
		cout << "Имя: " << name << endl;
		cout << "Отчество: " << fatherName << endl;
		cout << "Дата рождения: " << birthday.tm_mday << "." << birthday.tm_mon << "." << birthday.tm_year << endl;
		cout << "Номер зачетной книжки: " << numberCreditBook << endl;
		if (scholarship)
		{
			cout << "Учится на стипендию." << endl;
		}
		else
		{
			cout << "Учится без стипендии." << endl;
		}
	}

	// смена фамилии
	void ChangeSurname(string newSurname) {
		surname = newSurname;
	}

	// смена отчества
	void ChangeFatherName(string newFatherName) {
		fatherName = newFatherName;
	}

	// изменение информации о стипендии
	void ChangeScholarship(bool luckySession) {
		// если сессия закрыта на 4-5
		if (luckySession) {
			scholarship = true; // есть стипендия
		}
		else {
			scholarship = false; // нет стипендии
		}
	}
};

void OpenFileWrite(Student);

Student ReadStudentFromFile(Student);