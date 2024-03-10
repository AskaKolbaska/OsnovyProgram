#include "Lab1.h"
#include "ZadLab1.h"

void Lab1()
{
    MyList<Student> list = CreateList<Student>();
    int otvet = 0;
    
    // ����� �������� �� �������
    do
    {
        cout << endl << "�������� �������� �� �������:" << endl << endl
            << "���������� ������ �������� � ����� ������ (1)" << endl
            << "�������� ������� �������� (2)" << endl
            << "�������� ���������� �������� (3)" << endl
            << "�������� �������� �� ������ � ������ (4)" << endl
            << "����� �� ������ �� ������ �������� ������ (5)" << endl
            << "�������� ���� ������ (6)" << endl
            << "��������� ������ � ���� (7)" << endl << endl
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
            RemoveLastElement<Student>(&list);
            break;
        }
        // �������� ��-�� �� ������ ������
        case 4: {
            RemoveElementByIndex<Student>(&list);
            break;
        }
        // ����� �� ������ �� ������ �������� ������
        case 5: {
            FindByCreditBook<Student>(&list);
            break;
        }
        // �������� ���� ������
        case 6: {
            list.is_printed();
            break;
        }
        // ���������� ������ � ����
        case 7: {
            WriteList<Student>(&list);
            break;
        }
        default:
            cout << "� �� ���� ������ ������!" << endl;
            break;
        }
    } while (otvet != 0);
}
