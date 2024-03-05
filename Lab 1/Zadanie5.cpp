#include "Zadanie4.h"
#include "Zadanie5.h"

// чтение студентов в массив объектов
vector<Student> ReadStudentsFromFile_Obj() {

	string data[8]; // массив для данных из строки (номер зачетки, фамилия, имя, отчество, дата рождения, наличие стипендии)
	string str; // строка из файла
	int numberStr = 0; // количество строк в файле

	vector<Student> students; // массив со студентами

	ifstream out("students.txt");

	if (out.is_open()) {
		// подсчет кол-ва строк в файле
		while (getline(out, str)) {
			numberStr++;
		}

		out.clear();
		out.seekg(0);

		// ввод данных из файла в массив со студентами
		while (getline(out, str)) {
			stringstream ss(str); // создание строкового потока из полученной строки
			string word; // переменная для "слова" из строки

			int i = 0;

			// деление текущей строки по словам
			while (ss >> word) {
				data[i] = word;
				i++;
			}

			// переменная для студента
			Student exampleStud(data[1], data[2], data[3], stoi(data[4]), stoi(data[5]), stoi(data[6]), stoi(data[0]), stoi(data[7]));

			// добавление элемента в вектор students
			students.push_back(exampleStud);
		}
	}
	else {
		cout << "Ошибка открытия файла!" << endl;
	}
	out.close();
	return students;
}

// чтение студентов в массив указателей
vector<Student*> ReadStudentsFromFile_Points() {

	string data[8]; // массив для данных из строки (номер зачетки, фамилия, имя, отчество, дата рождения, наличие стипендии)
	string str; // строка из файла
	int numberStr = 0; // количество строк в файле

	vector<Student*> students; // массив с указателями на студентов

	ifstream out("students.txt");

	if (out.is_open()) {
		// подсчет кол-ва строк в файле
		while (getline(out, str)) {
			numberStr++;
		}

		out.clear();
		out.seekg(0);

		// ввод данных из файла в массив с указателями
		while (getline(out, str)) {
			stringstream ss(str); // создание строкового потока из полученной строки
			string word; // переменная для "слова" из строки

			int i = 0;

			// деление текущей строки по словам
			while (ss >> word) {
				data[i] = word;
				i++;
			}

			// переменная для указателя на студента
			Student* exampleStudent = new Student(data[1], data[2], data[3], stoi(data[4]), stoi(data[5]), stoi(data[6]), stoi(data[0]), stoi(data[7]));
			// Student exampleStud(data[1], data[2], data[3], stoi(data[4]), stoi(data[5]), stoi(data[6]), stoi(data[0]), stoi(data[7]));

			// добавление элемента в вектор students
			students.push_back(exampleStudent);
		}
	}
	else {
		cout << "Ошибка открытия файла!" << endl;
	}
	out.close();
	return students;
}

// создание указателя студента вручную
Student* CreateStudentByHands_Point() {
	// данные для ввода
	string surname, name, fatherName;
	int numberCreditBook;
	bool scholarship;
	tm birthday;

	cout << "Введите фамилию студента: ";
	cin.clear();
	cin >> surname;
	cout << "Введите имя студента: ";
	cin.clear();
	cin >> name;
	cout << "Введите отчество студента: ";
	cin.clear();
	cin >> fatherName;
	cout << "Введите дату рождения студента: " << endl;
	cout << "День: ";
	cin.clear();
	cin >> birthday.tm_mday;
	cout << "Месяц: ";
	cin.clear();
	cin >> birthday.tm_mon;
	cout << "Год: ";
	cin.clear();
	cin >> birthday.tm_year;
	cout << "Введите номер зачетной книжки студента: ";
	cin.clear();
	cin >> numberCreditBook;
	cout << "Учится ли человек на стипендию? Введите 1, если да, и 0, если нет: ";
	cin.clear();
	cin >> scholarship;

	Student* student = new Student(surname, name, fatherName, birthday.tm_mday, birthday.tm_mon, birthday.tm_year,
		numberCreditBook, scholarship);
	return student;
}

// создание массива объектов студентов
vector<Student> CreateArrayStudents_Obj() {
	int otvet = 0, numberCreditBook = 0;
	string newSurname, newFatherName;
	bool luckySession;

	vector<Student> students;

	// цикл ввода студентов
	do
	{
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
				cout << "Введите новую фамилию студента: ";
				cin.clear();
				cin >> newSurname;
				system("cls");
				exampleStudent.ChangeSurname(newSurname);
				break;
				// смена отчества
			case 2:
				cout << "Введите новое отчество студента: ";
				cin.clear();
				cin >> newFatherName;
				system("cls");
				exampleStudent.ChangeFatherName(newFatherName);
				break;
				// изменение стипендии
			case 3:
				cout << "Введите любое число, если студент закрыл сессию на стипендию, или 0, если студент остался без стипендии: ";
				cin.clear();
				cin >> luckySession;
				system("cls");
				exampleStudent.ChangeScholarship(luckySession);
				break;
				// дозаписать данные
			default:
				cout << "Я не знаю такого ответа, введите то, что я смогу понять!" << endl;
				break;
			}
		} while (otvet == 1);

		students.push_back(exampleStudent);

		cout << "Закончить ввод студентов? Введите 1, если да: ";
		cin >> otvet;
		cin.clear();
	} while (otvet != 1);

	return students;
}

// создание массива указателей на студентов
vector<Student*> CreateArrayStudents_Points() {
	int otvet = 1, numberCreditBook = 0;
	string newSurname, newFatherName;
	bool luckySession;

	//vector<Student> objStudents; // массив объектов
	vector<Student*> pointStudents; // массив указателей

	// цикл ввода студентов
	do
	{
		cout << "Создать шаблонного студента? Введите 1, если да: ";
		cin >> otvet;
		cin.clear();

		if (otvet == 1)
		{
			cout << "Введите номер зачетной книжки: ";
			cin >> numberCreditBook;
		}

		// создание шаблона
		Student* exampleStudent = new Student(numberCreditBook);
		//Student* pointStudent = &exampleStudent;

		if (otvet != 1)
		{
			exampleStudent = CreateStudentByHands_Point(); // ввод нового студента с клавиатуры
		}
		exampleStudent->ShowInf();

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
				cout << "Введите новую фамилию студента: ";
				cin.clear();
				cin >> newSurname;
				system("cls");
				exampleStudent->ChangeSurname(newSurname);
				break;
				// смена отчества
			case 2:
				cout << "Введите новое отчество студента: ";
				cin.clear();
				cin >> newFatherName;
				system("cls");
				exampleStudent->ChangeFatherName(newFatherName);
				break;
				// изменение стипендии
			case 3:
				cout << "Введите любое число, если студент закрыл сессию на стипендию, или 0, если студент остался без стипендии: ";
				cin.clear();
				cin >> luckySession;
				system("cls");
				exampleStudent->ChangeScholarship(luckySession);
				break;
				// дозаписать данные
			default:
				cout << "Я не знаю такого ответа, введите то, что я смогу понять!" << endl;
				break;
			}
		} while (otvet == 1);

		pointStudents.push_back(exampleStudent);

		cout << "Закончить ввод студентов? Введите 1, если да: ";
		cin >> otvet;
		cin.clear();
	} while (otvet != 1);

	return pointStudents;
}

// перезапись данных (objects)
void RewriteStudents_Obj(vector<Student> students) {
	ofstream in("students.txt"); // открытие файла для перезаписи
	if (in.is_open())
	{
		for (int i = 0; i < students.size(); i++)
		{
			in << students[i].StrForWrite();

			if (i != students.size() - 1) { // если это НЕ последний элемент
				in << endl;
			}
		}
	}
	else
	{
		cout << "Ошибка записи!" << endl;
	}
	in.close();
}

// перезапись данных (points)
void RewriteStudents_Points(vector<Student*> students) {
	ofstream in("students.txt"); // открытие файла для перезаписи
	if (in.is_open())
	{
		for (int i = 0; i < students.size(); i++)
		{
			in << students[i]->StrForWrite();

			if (i != students.size() - 1) { // если это НЕ последний элемент
				in << endl;
			}
		}
	}
	else
	{
		cout << "Ошибка записи!" << endl;
	}
	in.close();
}

// вывод массива данных (объекты)
void ShowStudents_Obj(vector<Student> students) {
	cout << "Полученные данные:" << endl << endl;
	for (int i = 0; i < students.size(); i++)
	{
		cout << "Студент №" << i+1 << ":" << endl << endl;
		students[i].ShowInf();
	}
}

// вывод массива данных (указатели)
void ShowStudents_Points(vector<Student*> students) {
	cout << "Полученные данные:" << endl << endl;
	for (int i = 0; i < students.size(); i++)
	{
		cout << "Студент №" << i+1 << ":" << endl << endl;
		students[i]->ShowInf();
	}
}

// дозапись массива объектов в файл
void AddArrayStudents_Obj(vector<Student> students) {
	for (int i = 0; i < students.size(); i++)
	{
		AddStudent(students[i]);
	}
}

// дозапись массива указателей в файл
void AddArrayStudents_Points(vector<Student*> students) {
	for (int i = 0; i < students.size(); i++)
	{
		AddStudent(*students[i]);
	}
}