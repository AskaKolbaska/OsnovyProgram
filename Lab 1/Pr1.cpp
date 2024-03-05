#include "Zadanie1.h"

int x = 0, y = 0;
double res = 0;
pair<int, int> p;

void Pr1(int otvet) {
    // ввод данных и разделение из пары
    p = vvodData();
    x = p.first;
    y = p.second;

    switch (otvet)
    {
    case 1:
        res = summa(x, y);
        cout << "Сумма равна: " << res << endl;
        break;
    case 2:
        res = difference(x, y);
        cout << "Разность равна: " << res << endl;
        break;
    case 3:
        res = proisv(x, y);
        cout << "Произведение равно: " << res << endl;
        break;
    case 4:
        if (y != 0) {
            res = delenie(x, y);
            cout << "Деление равно: " << res << endl;
        }
        else {
            cout << "Делить на 0 нельзя!" << endl;
        }
        break;
    default:
        cout << "Неправильно введен ответ!" << endl;
        break;
    }
}
