#include "Pr6.h"

void Pr6() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Тестирование записи!" << endl << endl;

	// создание массива студентов для записи
	vector<Student> studentsForAdd = CreateArrayStudents_Obj();

	// дозапись студентов в файл
	AddArrayStudents_Obj(studentsForAdd);
	cout << "Запись завершена!" << endl;

	// чтение из файла
	vector<Student> studentsAfterReading = ReadStudentsFromFile_Obj();

	if (IfWritingSuccesful(studentsForAdd, studentsAfterReading))
	{
		cout << "Запись прошла успешно!" << endl;
	}
	else {
		cout << "Запись не удалась!" << endl;
	}
}

bool IfWritingSuccesful(vector<Student> studentForAdd, vector<Student> studentAfterReading) {
	int kolvoMAX = studentAfterReading.size(); // размер вектора считанных студентов
	int kolvoStud = 0; // счетчик совпавших студентов

	for (int i = 0; i < kolvoMAX; i++)
	{
		for (int j = 0; j < studentForAdd.size(); j++)
		{
			if (studentForAdd[j] == studentAfterReading[i]) {
				// если студент из файла и студент для записи совпадают к счетчику + 1
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