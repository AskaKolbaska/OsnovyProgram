#include "Lab1.h"
#include "ZadLab1.h"

void Lab1()
{
    MyList<Student> list = CreateList<Student>();
    int otvet = 0;
    
    // TODO: выбор действий со списком
    do
    {
        cout << "Выберите действие со списком:" << endl
            << "Добавление нового элемента в конец списка (1)" << endl
            << "Удаление первого элемента (2)" << endl
            << "Удаление последнего элемента (3)" << endl
            << "Удаление элемента по номеру в списке (4)" << endl
            << "Поиск по списку по номеру зачетной книжки (5)" << endl
            << "Показать весь список (6)" << endl << endl
            << "Завершить работу со списком (0)" << endl;
        cin >> otvet;
        switch (otvet)
        {
        // добавление эл-та в конец списка
        case 1:
        {
            AddElement<Student>(&list);
            break;
        }
        // удаление 1-го элемента
        case 2: {
            RemoveFirstElement<Student>(&list);
            break;
        }
        // удаление последнего эл-та
        case 3: {

        }
        // удаление эл-та по номеру списка
        case 4: {

        }
        // Поиск по списку по номеру зачетной книжки
        case 5: {
            
        }
        // Показать весь список
        case 6: {
            list.print();
        }
        default:
            cout << "Я не знаю такого ответа!" << endl;
            break;
        }
    } while (otvet != 0);

    cout << "Вывод студента с зачеткой 123" << endl << endl;
    list.FindNode(123);
}
