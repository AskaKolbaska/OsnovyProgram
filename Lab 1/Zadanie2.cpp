#include "Zadanie2.h"
extern int x, y;
extern double res;

// ввод логина пользователя
string UserName() {
	string login;
	cout << "Введите логин: ";
	cin >> login;
	return login;
}

// выбор действия
int choiceActionFile() {
	int otv = 0;
	cout << "Выберите действие (запись в файл - 1, чтение из файла - 2, поиск по логину - 3, очистка файла - 4): ";
	cin >> otv;
	return otv;
}

// чтение строки
void ReadStrFromFile() {
	string str;
	ifstream out("results.txt");
	if (out.is_open()) {
		while (getline(out, str)) {
			cout << str << endl;
		}
	}
	else {
		cout << "Не могу открыть файл!" << endl;
	}
	out.close();
}

// чтение номера сессии
int OpenFileReadNumber() {
	string data[5]; // массив для данных из строки (номер сессии, логин, х, у, результат)
	string str; // строка из файла
	int number = 0; // переменная для номера сессии

	ifstream out("results.txt"); // поток файла для чтения
	
	if (out.is_open()) {
		// чтение каждой строки до последней
		while (getline(out, str)) {
			// создание строкового потока из полученной строки
			stringstream ss(str);
			// переменная для "слова" из строки
			string word;
			int i=0;
			while (ss >> word) {
				data[i] = word;
				i++;
			}
		}
		// номер последней сессии
		if (data[0] == "\0") { // если массив остался пустым
			number = 0;
		}
		else { // если же данные считаны
			number = stoi(data[0]);
		}
	}
	else {
		cout << "Ошибка открытия файла!" << endl;
		number = 0;
	}
	out.close();
	return number;
}

// открытие файла для записи
void OpenFileWrite(string login) {
	int numberSession = OpenFileReadNumber(); // получение номера последней сессии
	int otvet = choiceAction(); // получение с клавиатуры номера задачи для вычисления

	// запуск программы из 1-ой лабы
	Pr1(otvet);

	ofstream in("results.txt", ios::app); // открытие файла для добавления данных в конец файла
	if (in.is_open())
	{
		in << numberSession + 1 << " " << login << " " << x << " " << y << " " << res << endl;
	}
	in.close();
}

// очистка файла
void ClearFile() {
	ofstream f("results.txt", ios::trunc);
	f.close();
}

// поиск по пользователю
void FindUser(string login) {
	string data[5]; // массив для данных из строки (номер сессии, логин, х, у, результат)
	string str; // строка из файла
	int sizeOfMassiv = size(data); // размер массива

	ifstream out("results.txt"); // поток файла для чтения

	if (out.is_open()) {
		// чтение каждой строки до последней
		while (getline(out, str)) {
			// создание строкового потока из полученной строки
			stringstream ss(str);
			// переменная для "слова" из строки
			string word;
			int i = 0;
			while (ss >> word) {
				data[i] = word;
				i++;
			}
			if (data[1] == login) { // проверка на совпадение с введенным пользователем логином
				for (int i = 0; i < sizeOfMassiv; i++)
				{
					cout << data[i] << " ";
				}
				cout << endl;
			}
		}	
	}
	else {
		cout << "Файл пуст!" << endl;
	}
	out.close();
}