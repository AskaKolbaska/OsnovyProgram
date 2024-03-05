#include "Zadanie1.h"

// выбор действия
int choiceAction() {
	int otv = 0;
	cout << "Выберите действие (сумма - 1, вычитание - 2, умножение - 3, деление - 4): ";
	cin >> otv;
	return otv;
}

// ввод данных
pair<int, int> vvodData() {
	int x = 0, y = 0;
	cout << "Введите х: ";
	cin >> x;
	cout << "Введите y: ";
	cin >> y;
	return make_pair(x, y);
}

// сложение
int summa(int x, int y) {
	return x + y;
}

// вычитание
int difference(int x, int y) {
	return x - y;
}

// умножение
int proisv(int x, int y) {
	return x * y;
}

// деление
double delenie(double x, double y) {
	return x / y;
}