#include "Lab1.h"
#include "ZadLab1.h"

void Lab1()
{
    MyList<Student> list = CreateList<Student>();
    int otvet = 0;
    
    // выбор действий со списком
    do
    {
        cout << endl << "Выберите действие со списком:" << endl << endl
            << "Добавление нового элемента в конец списка (1)" << endl
            << "Удаление первого элемента (2)" << endl
            << "Удаление последнего элемента (3)" << endl
            << "Удаление элемента по номеру в списке (4)" << endl
            << "Поиск по списку по номеру зачетной книжки (5)" << endl
            << "Показать весь список (6)" << endl
            << "Сохранить список в файл (7)" << endl << endl
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
            RemoveLastElement<Student>(&list);
            break;
        }
        // удаление эл-та по номеру списка
        case 4: {
            RemoveElementByIndex<Student>(&list);
            break;
        }
        // Поиск по списку по номеру зачетной книжки
        case 5: {
            FindByCreditBook<Student>(&list);
            break;
        }
        // Показать весь список
        case 6: {
            list.is_printed();
            break;
        }
        // сохранение списка в файл
        case 7: {
            WriteList<Student>(&list);
            break;
        }
        default:
            cout << "Я не знаю такого ответа!" << endl;
            break;
        }
    } while (otvet != 0);
}
