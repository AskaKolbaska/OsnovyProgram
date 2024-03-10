#include "Zadanie5.h"
#include "ZadLab1.h"
#include "Pr7.h"

// тестирование шаблонных списков
void Pr7() {
	int otvet = 0;
	cout << "—оздать список целых чисел (1) или список студентов (2)? " << endl;
	cin >> otvet;
	switch (otvet)
	{
	// int
	case 1: {
		vector<int> data = CreateData<int>(); // создание вектора данных дл€ ввода в список
		MyList<int> list_int = CreateList<int>(data); // внос данных из вектора в список

		list_int.print();

		break;
	}
	// students
	case 2: {
		MyList<Student> list_student = CreateList<Student>();
		break;
	}
	default:
		cout << "Ќеправильно введен ответ" << endl;
		break;
	}
}
