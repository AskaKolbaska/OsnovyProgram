#include "Zadanie2.h"
extern int x, y;
extern double res;

// ���� ������ ������������
string UserName() {
	string login;
	cout << "������� �����: ";
	cin >> login;
	return login;
}

// ����� ��������
int choiceActionFile() {
	int otv = 0;
	cout << "�������� �������� (������ � ���� - 1, ������ �� ����� - 2, ����� �� ������ - 3, ������� ����� - 4): ";
	cin >> otv;
	return otv;
}

// ������ ������
void ReadStrFromFile() {
	string str;
	ifstream out("results.txt");
	if (out.is_open()) {
		while (getline(out, str)) {
			cout << str << endl;
		}
	}
	else {
		cout << "�� ���� ������� ����!" << endl;
	}
	out.close();
}

// ������ ������ ������
int OpenFileReadNumber() {
	string data[5]; // ������ ��� ������ �� ������ (����� ������, �����, �, �, ���������)
	string str; // ������ �� �����
	int number = 0; // ���������� ��� ������ ������

	ifstream out("results.txt"); // ����� ����� ��� ������
	
	if (out.is_open()) {
		// ������ ������ ������ �� ���������
		while (getline(out, str)) {
			// �������� ���������� ������ �� ���������� ������
			stringstream ss(str);
			// ���������� ��� "�����" �� ������
			string word;
			int i=0;
			while (ss >> word) {
				data[i] = word;
				i++;
			}
		}
		// ����� ��������� ������
		if (data[0] == "\0") { // ���� ������ ������� ������
			number = 0;
		}
		else { // ���� �� ������ �������
			number = stoi(data[0]);
		}
	}
	else {
		cout << "������ �������� �����!" << endl;
		number = 0;
	}
	out.close();
	return number;
}

// �������� ����� ��� ������
void OpenFileWrite(string login) {
	int numberSession = OpenFileReadNumber(); // ��������� ������ ��������� ������
	int otvet = choiceAction(); // ��������� � ���������� ������ ������ ��� ����������

	// ������ ��������� �� 1-�� ����
	Pr1(otvet);

	ofstream in("results.txt", ios::app); // �������� ����� ��� ���������� ������ � ����� �����
	if (in.is_open())
	{
		in << numberSession + 1 << " " << login << " " << x << " " << y << " " << res << endl;
	}
	in.close();
}

// ������� �����
void ClearFile() {
	ofstream f("results.txt", ios::trunc);
	f.close();
}

// ����� �� ������������
void FindUser(string login) {
	string data[5]; // ������ ��� ������ �� ������ (����� ������, �����, �, �, ���������)
	string str; // ������ �� �����
	int sizeOfMassiv = size(data); // ������ �������

	ifstream out("results.txt"); // ����� ����� ��� ������

	if (out.is_open()) {
		// ������ ������ ������ �� ���������
		while (getline(out, str)) {
			// �������� ���������� ������ �� ���������� ������
			stringstream ss(str);
			// ���������� ��� "�����" �� ������
			string word;
			int i = 0;
			while (ss >> word) {
				data[i] = word;
				i++;
			}
			if (data[1] == login) { // �������� �� ���������� � ��������� ������������� �������
				for (int i = 0; i < sizeOfMassiv; i++)
				{
					cout << data[i] << " ";
				}
				cout << endl;
			}
		}	
	}
	else {
		cout << "���� ����!" << endl;
	}
	out.close();
}