using namespace std;
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>
#include "Zadanie3.h"

// запись в файл структуры
void OpenFileWrite(Student student) {
	// если в структуре ничего нет
	if (student.isNull)
	{
		cout << "Ќет данных дл€ записи!" << endl;
	}
	else {
		ofstream in("student.txt"); // открытие файла дл€ перезаписи данных
		if (in.is_open())
		{
			in << student.numberCreditBook << " "
				<< student.surname << " "
				<< student.name << " "
				<< student.fatherName << " "
				<< student.birthday.tm_mday << " " << student.birthday.tm_mon << " " << student.birthday.tm_year << " "
				<< student.scholarship
				<< endl;
		}
		in.close();
		cout << "«апись завершена!" << endl;
	}
}

// чтение из файла структуры
Student ReadStudentFromFile(Student student) {
	string data[8]; // массив дл€ данных из строки (номер зачетки, фамили€, им€, отчество, дата рождени€, наличие стипендии)
	string str; // строка из файла
	ifstream out("student.txt");
	if (out.is_open()) {
		getline(out, str); // получение строки из файла
		stringstream ss(str); // создание строкового потока из полученной строки
		string word; // переменна€ дл€ "слова" из строки
		int i = 0;
		while (ss >> word) {
			data[i] = word;
			i++;
		}

		student.isNull = false;
		student.numberCreditBook = stoi(data[0]);
		student.surname = data[1];
		student.name = data[2];
		student.fatherName = data[3];
		student.birthday.tm_mday = stoi(data[4]);
		student.birthday.tm_mon = stoi(data[5]);
		student.birthday.tm_year = stoi(data[6]);
		student.scholarship = stoi(data[7]);

		cout << "ƒанные считаны!" << endl;
	}
	else {
		cout << "ќшибка открыти€ файла!" << endl;
	}
	out.close();
	// возврат структуры
	return student;
}