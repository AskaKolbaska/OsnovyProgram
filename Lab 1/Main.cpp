// Lab 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Menu.h"
#include "Pr1.h"
#include "Pr2.h"
#include "Pr3.h"
#include "Pr4.h"
#include "Pr5.h"
#include "Pr6.h"
#include "Lab1.h"
#include "Zadanie1.h"
#include "Zadanie2.h"


int main()
{
    // установка локализации
    setlocale(LC_ALL, "Russian");

    int otvetLab = 0;
    int otvAct = 0;

    do
    {
        // выбор практик или лабораторных
        cout << "Для выбора практик введите 1;" << endl << "для выбора лабораторных введите 2" << endl;
        cin >> otvetLab;
        system("cls");
        switch (otvetLab)
        {
        // выбор практик
        case 1:
        {
            cout << "Выбор практик" << endl << endl;
            // выбор задания
            otvetLab = choice();
            switch (otvetLab)
            {
            // практика 1
            case 1:
            {
                // выбор действия
                otvAct = choiceAction();
                Pr1(otvAct);
                break;
            }
            // практика 2
            case 2:
            {
                otvAct = choiceActionFile();
                Pr2(otvAct);
                break;
            }
            // практика 3
            case 3:
            {
                Pr3();
                break;
            }
            // практика 4
            case 4:
            {
                Pr4();
                break;
            }
            // практика 5
            case 5:
            {
                Pr5();
                break;
            }
            // практика 6
            case 6:
            {
                Pr6();
                break;
            }
            default:
                cout << "Неправильно введен ответ!" << endl;
                break;
            }
            break;
        }
        // выбор лабораторных
        case 2:
        {
            cout << "Выбор лабораторных" << endl << endl;
            // выбор задания
            otvetLab = choice();
            switch (otvetLab)
            {
            // лаба 1
            case 1: {
                Lab1();
                break;
            }
            default:
                break;
            }
            break;
        }
        default:
        {
            cout << "Неправильно введен ответ!" << endl;
            break;
        }
        }
        
        cout << "Выйти из программы? Введите 0, если да" << endl;
        cin.clear();
        cin >> otvetLab;
    } while (otvetLab != 0);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
