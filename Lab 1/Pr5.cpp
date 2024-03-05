#include "Zadanie4.h"
#include "Zadanie5.h"

// ������� ���������� �������� ������
void Pr5() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int otvet = 0, numberStudent = 0;
	string newSurname, newFatherName;
	bool luckySession;

	do
	{
		cout << "��� ������ ��������� �� ����� ������� 1;" << endl
			<< "��� �������� ����� ��������� ������� 2" << endl;
		cin >> otvet;
		system("cls");
		switch (otvet)
		{
		// ������ ���������
		case 1:
		{
			cout << "��� �������� ������� �������� ������� 1; " << endl
				<< "��� �������� ������� ���������� �� ������� ������� 2" << endl;
			cin >> otvet;
			system("cls");
			switch (otvet)
			{
			// ������ � ������ ��������
			case 1:
			{
				// ������ ��������� � ������ ��������
				vector<Student> students = ReadStudentsFromFile_Obj();

				// �������� ������� � ������� ������
				if (students.empty())
				{
					cout << "������ ���������� �����!" << endl;
					break;
				}
				else
				{
					// ������ � �������
					do
					{
						// ����� ���������� ��������� ���������
						cout << "���-�� ���������� ���������: " << students.size() << endl;

						cout << "������� ���������� ������ � ����� �������? ������� 1, ���� ��: ";
						cin >> otvet;
						cin.clear();

						if (otvet != 1) {
							break;
						}

						// ����� ��������
						cout << "�������� ��������: ";
						cin >> numberStudent;
						cin.clear();
						if (numberStudent > students.size() || numberStudent <= 0)
						{
							cout << "������� �������� �����" << endl;
							break;
						}
						cout << endl;
						students[numberStudent - 1].ShowInf();
						cout << endl;

						cout << "�������� �������� ��� ���������:" << endl <<
							"(1) C���� �������;" << endl <<
							"(2) C���� ��������;" << endl <<
							"(3) ��������� ���������;" << endl <<
							"(4) ���������� ������ � ���������� �����������;" << endl <<
							"(0) ��������� ������ �� ����������: ";
						cin >> otvet;
						cin.clear();
						system("cls");
						switch (otvet)
						{
						case 0:
							break;
							// ����� �������
						case 1:
						{
							cout << "������� ����� ������� ��������: ";
							cin.clear();
							cin >> newSurname;
							system("cls");
							students[numberStudent - 1].ChangeSurname(newSurname);
							break;
						}
						// ����� ��������
						case 2:
						{
							cout << "������� ����� �������� ��������: ";
							cin.clear();
							cin >> newFatherName;
							system("cls");
							students[numberStudent - 1].ChangeFatherName(newFatherName);
							break;
						}
						// ��������� ���������
						case 3:
						{
							cout << "������� ����� �����, ���� ������� ������ ������ �� ���������, ��� 0, ���� ������� ������� ��� ���������: ";
							cin.clear();
							cin >> luckySession;
							system("cls");
							students[numberStudent - 1].ChangeScholarship(luckySession);
							break;
						}
						// ���������� ���������� ������
						case 4:
							RewriteStudents_Obj(students);
							cout << "������ ���������!" << endl;
							break;
						default:
							cout << "� �� ���� ������ ������!" << endl;
							break;
						}
					} while (otvet == 1);
				}
				break;
			}
			// ������ � ������ ����������
			case 2:
			{
				// ������ ��������� � ������ ����������
				vector<Student*> students = ReadStudentsFromFile_Points();
				// �������� ������� � ������� ������
				if (students.empty())
				{
					cout << "������ ���������� �����!" << endl;
					break;
				}
				else
				{
					// ������ � �������
					do
					{
						// ����� ���������� ��������� ���������
						cout << "���-�� ���������� ���������: " << students.size() << endl;

						cout << "������� ���������� ������ � ����� �������? ������� 1, ���� ��: ";
						cin >> otvet;
						cin.clear();

						if (otvet != 1) {
							break;
						}

						// ����� ��������
						cout << "�������� ��������: ";
						cin >> numberStudent;
						cin.clear();
						if (numberStudent > students.size() || numberStudent <= 0)
						{
							cout << "������� �������� �����" << endl;
							break;
						}
						cout << endl;
						students[numberStudent - 1]->ShowInf();
						cout << endl;

						cout << "�������� �������� ��� ���������:" << endl <<
							"(1) C���� �������;" << endl <<
							"(2) C���� ��������;" << endl <<
							"(3) ��������� ���������;" << endl <<
							"(4) ���������� ������ � ���������� �����������;" << endl <<
							"(0) ��������� ������ �� ����������: ";
						cin >> otvet;
						cin.clear();
						system("cls");
						switch (otvet)
						{
						case 0:
							break;
							// ����� �������
						case 1:
						{
							cout << "������� ����� ������� ��������: ";
							cin.clear();
							cin >> newSurname;
							system("cls");
							students[numberStudent - 1]->ChangeSurname(newSurname);
							break;
						}
						// ����� ��������
						case 2:
						{
							cout << "������� ����� �������� ��������: ";
							cin.clear();
							cin >> newFatherName;
							system("cls");
							students[numberStudent - 1]->ChangeFatherName(newFatherName);
							break;
						}
						// ��������� ���������
						case 3:
						{
							cout << "������� ����� �����, ���� ������� ������ ������ �� ���������, ��� 0, ���� ������� ������� ��� ���������: ";
							cin.clear();
							cin >> luckySession;
							system("cls");
							students[numberStudent - 1]->ChangeScholarship(luckySession);
							break;
						}
						// ���������� ���������� ������
						case 4:
							RewriteStudents_Points(students);
							cout << "������ ���������!" << endl;
							break;
						default:
							cout << "� �� ���� ������ ������!" << endl;
							break;
						}
					} while (otvet == 1);
				}
				break;
			}
			default:
				cout << "� �� ���� ������ ������!" << endl;
				break;
			}
			break;
		}
			
		// �������� ����� ���������
		case 2:
		{
			cout << "��� �������� ������� �������� ������� 1; " << endl
				<< "��� �������� ������� ���������� �� ������� ������� 2" << endl;
			cin >> otvet;
			system("cls");
			switch (otvet)
			{
			// �������� ��������� � ������ ��������
			case 1:
				
			{
				vector<Student> students = CreateArrayStudents_Obj();

				ShowStudents_Obj(students);

				cout << "�������� ������ � ����? ������� 1, ���� ��" << endl;
				cin.clear();
				cin >> otvet;
				if (otvet == 1)
				{
					AddArrayStudents_Obj(students);
				}
				break;
			}
			// �������� ��������� � ������ ����������
			case 2:
			{
				vector<Student*> students = CreateArrayStudents_Points();
				
				ShowStudents_Points(students);

				cout << "�������� ������ � ����? ������� 1, ���� ��" << endl;
				cin.clear();
				cin >> otvet;
				if (otvet == 1)
				{
					AddArrayStudents_Points(students);
				}
				break;
			}
			default:
				cout << "� �� ���� ������ ������!" << endl;
				break;
			}
		}
		default:
			break;
		}

		cout << "������� ���������� ������ �� ����������? ������� 1, ���� ��: ";
		cin.clear();
		cin >> otvet;
		system("cls");
	} while (otvet == 1);
}