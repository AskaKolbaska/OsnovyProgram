#include "Zadanie1.h"

// ����� ��������
int choiceAction() {
	int otv = 0;
	cout << "�������� �������� (����� - 1, ��������� - 2, ��������� - 3, ������� - 4): ";
	cin >> otv;
	return otv;
}

// ���� ������
pair<int, int> vvodData() {
	int x = 0, y = 0;
	cout << "������� �: ";
	cin >> x;
	cout << "������� y: ";
	cin >> y;
	return make_pair(x, y);
}

// ��������
int summa(int x, int y) {
	return x + y;
}

// ���������
int difference(int x, int y) {
	return x - y;
}

// ���������
int proisv(int x, int y) {
	return x * y;
}

// �������
double delenie(double x, double y) {
	return x / y;
}