#pragma once

#include <sstream>
#include <fstream>
#include <iostream>
#include <locale>
#include <Windows.h>
#include <vector>

using namespace std;

// КЛАСС СТУДЕНТ
class Student {
private:
	bool isNull = true; // изначально TRUE - ничего нет в экземпляре
	string surname; // фамилия
	string name; // имя
	string fatherName; // отчество
	tm birthday; // дата рождения
	int numberCreditBook; // номер зачетной книжки
	bool scholarship; // наличие стипендии
	

	// изменяет значение поля isNull в случае, если в экземпляре класса что-то появилось
	void ChangeIsNull() {
		isNull = false;
	}

public:
	//bool operator==(Student const& rhs) const;

	// шаблонный студент
	Student(int p_numberCreditBook, string p_surname = "Иванов", string p_name = "Иван", string p_fatherName = "Иванович",
		int p_bDay = 1, int p_bMon = 1, int p_bYear = 2000, bool p_scholarship = 0) {
		surname = p_surname;
		name = p_name;
		fatherName = p_fatherName;
		birthday.tm_mday = p_bDay;
		birthday.tm_mon = p_bMon;
		birthday.tm_year = p_bYear;
		numberCreditBook = p_numberCreditBook;
		scholarship = p_scholarship;
		ChangeIsNull();
	}

	// конструктор
	Student(string p_surname, string p_name, string p_fatherName,
		int p_bDay, int p_bMon, int p_bYear, int p_numberCreditBook, bool p_scholarship) {
		surname = p_surname;
		name = p_name;
		fatherName = p_fatherName;
		birthday.tm_mday = p_bDay;
		birthday.tm_mon = p_bMon;
		birthday.tm_year = p_bYear;
		numberCreditBook = p_numberCreditBook;
		scholarship = p_scholarship;
		ChangeIsNull();
	}

	bool operator==(const Student& rhs) const {
		return (isNull == rhs.isNull) &&
			(surname == rhs.surname) &&
			(name == rhs.name) &&
			(fatherName == rhs.fatherName) &&
			(birthday.tm_mday == rhs.birthday.tm_mday) &&
			(birthday.tm_mon == rhs.birthday.tm_mon) &&
			(birthday.tm_year == rhs.birthday.tm_year) &&
			(numberCreditBook == rhs.numberCreditBook) &&
			(scholarship == rhs.scholarship);
	}

	// строка для записи в файл
	string StrForWrite() {
		string str = to_string(numberCreditBook) + " "
			+ surname + " "
			+ name + " "
			+ fatherName + " "
			+ to_string(birthday.tm_mday) + " "
			+ to_string(birthday.tm_mon) + " "
			+ to_string(birthday.tm_year) + " "
			+ to_string(scholarship);

		return str;
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

// создание нового студента вручную
Student CreateStudentByHands();

// чтение студентов из файла
vector<Student> ReadStudentsFromFile();

// проверка файла на пустоту
bool isEmpty();

// дозапись студента в файл
void AddStudent(Student);

// перезапись данных в файле
void RewriteStudents(vector<Student>);