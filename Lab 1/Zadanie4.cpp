#include "Zadanie4.h"

// создание нового студента вручную
Student CreateStudentByHands() {
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

	Student student(surname, name, fatherName, birthday.tm_mday, birthday.tm_mon, birthday.tm_year,
		numberCreditBook, scholarship);
	return student;
}

// чтение студентов из файла
vector<Student> ReadStudentsFromFile() {
	
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

// дозапись студента в файл
void AddStudent(Student student) {
	ofstream in("students.txt", ios::app); // открытие для дозаписи
	if (in.is_open())
	{
		if (isEmpty())
		{
			in << student.StrForWrite();
		}
		else {
			in << endl << student.StrForWrite();
		}
	}
	else
	{
		cout << "Ошибка записи!" << endl;
	}
	
	in.close();
}

// проверка пустоты файла
bool isEmpty()
{
	ifstream in("students.txt"); // открытие файла для проверки на пустоту
	if (in.peek() == EOF)
	{
		return true; // если пуст, возвращает ДА
	}
	else
	{
		return false;
	}
	in.close();
}

// перезапись данных
void RewriteStudents(vector<Student> students) {
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