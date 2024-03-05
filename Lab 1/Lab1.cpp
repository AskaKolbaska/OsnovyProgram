#include "Lab1.h"
#include "ZadLab1.h"

void Lab1()
{
    MyList<Student> list = CreateList<Student>();
    
    // TODO: выбор действий со списком

    cout << "Вывод студента с зачеткой 123" << endl << endl;
    list.FindNode(123);
}
