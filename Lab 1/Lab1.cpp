#include "Lab1.h"
#include "ZadLab1.h"

void Lab1()
{
    MyList<Student> list = CreateList<Student>();
    int otvet = 0;
    
    // TODO: ����� �������� �� �������
    do
    {
        cout << "�������� �������� �� �������:" << endl
            << "���������� ������ �������� � ����� ������ (1)" << endl
            << "�������� ������� �������� (2)" << endl
            << "�������� ���������� �������� (3)" << endl
            << "�������� �������� �� ������ � ������ (4)" << endl
            << "����� �� ������ �� ������ �������� ������ (5)" << endl
            << "�������� ���� ������ (6)" << endl << endl
            << "��������� ������ �� ������� (0)" << endl;
        cin >> otvet;
        switch (otvet)
        {
        // ���������� ��-�� � ����� ������
        case 1:
        {
            AddElement<Student>(&list);
            break;
        }
        // �������� 1-�� ��������
        case 2: {
            RemoveFirstElement<Student>(&list);
            break;
        }
        // �������� ���������� ��-��
        case 3: {

        }
        // �������� ��-�� �� ������ ������
        case 4: {

        }
        // ����� �� ������ �� ������ �������� ������
        case 5: {
            
        }
        // �������� ���� ������
        case 6: {
            list.print();
        }
        default:
            cout << "� �� ���� ������ ������!" << endl;
            break;
        }
    } while (otvet != 0);

    cout << "����� �������� � �������� 123" << endl << endl;
    list.FindNode(123);
}
