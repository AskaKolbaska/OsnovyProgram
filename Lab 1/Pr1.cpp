#include "Zadanie1.h"

int x = 0, y = 0;
double res = 0;
pair<int, int> p;

void Pr1(int otvet) {
    // ���� ������ � ���������� �� ����
    p = vvodData();
    x = p.first;
    y = p.second;

    switch (otvet)
    {
    case 1:
        res = summa(x, y);
        cout << "����� �����: " << res << endl;
        break;
    case 2:
        res = difference(x, y);
        cout << "�������� �����: " << res << endl;
        break;
    case 3:
        res = proisv(x, y);
        cout << "������������ �����: " << res << endl;
        break;
    case 4:
        if (y != 0) {
            res = delenie(x, y);
            cout << "������� �����: " << res << endl;
        }
        else {
            cout << "������ �� 0 ������!" << endl;
        }
        break;
    default:
        cout << "����������� ������ �����!" << endl;
        break;
    }
}
