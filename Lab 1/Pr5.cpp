#include "Zadanie4.h"
#include "Zadanie5.h"

// массивы указателей объектов класса
void Pr5() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int otvet = 0, numberStudent = 0;
	string newSurname, newFatherName;
	bool luckySession;

	do
	{
		cout << "Для чтения студентов из файла введите 1;" << endl
			<< "Для создания новых студентов введите 2" << endl;
		cin >> otvet;
		system("cls");
		switch (otvet)
		{
		// чтение студентов
		case 1:
		{
			cout << "Для создания массива объектов введите 1; " << endl
				<< "Для создания массива указателей на объекты введите 2" << endl;
			cin >> otvet;
			system("cls");
			switch (otvet)
			{
			// чтение в массив объектов
			case 1:
			{
				// чтение студентов в массив объектов
				vector<Student> students = ReadStudentsFromFile_Obj();

				// проверка наличия в массиве данных
				if (students.empty())
				{
					cout << "Ошибка считывания файла!" << endl;
					break;
				}
				else
				{
					// работа с данными
					do
					{
						// вывод количества доступных студентов
						cout << "Кол-во записанных студентов: " << students.size() << endl;

						cout << "Желаете продолжить работу с этими данными? Введите 1, если да: ";
						cin >> otvet;
						cin.clear();

						if (otvet != 1) {
							break;
						}

						// выбор студента
						cout << "Выберите студента: ";
						cin >> numberStudent;
						cin.clear();
						if (numberStudent > students.size() || numberStudent <= 0)
						{
							cout << "Введено неверное число" << endl;
							break;
						}
						cout << endl;
						students[numberStudent - 1].ShowInf();
						cout << endl;

						cout << "Выберите действие над студентом:" << endl <<
							"(1) Cмена фамилии;" << endl <<
							"(2) Cмена отчества;" << endl <<
							"(3) Изменение стипендии;" << endl <<
							"(4) Перезапись данных с введенными изменениями;" << endl <<
							"(0) Закончить работу со студентами: ";
						cin >> otvet;
						cin.clear();
						system("cls");
						switch (otvet)
						{
						case 0:
							break;
							// смена фамилии
						case 1:
						{
							cout << "Введите новую фамилию студента: ";
							cin.clear();
							cin >> newSurname;
							system("cls");
							students[numberStudent - 1].ChangeSurname(newSurname);
							break;
						}
						// смена отчества
						case 2:
						{
							cout << "Введите новое отчество студента: ";
							cin.clear();
							cin >> newFatherName;
							system("cls");
							students[numberStudent - 1].ChangeFatherName(newFatherName);
							break;
						}
						// изменение стипендии
						case 3:
						{
							cout << "Введите любое число, если студент закрыл сессию на стипендию, или 0, если студент остался без стипендии: ";
							cin.clear();
							cin >> luckySession;
							system("cls");
							students[numberStudent - 1].ChangeScholarship(luckySession);
							break;
						}
						// перезапись измененных данных
						case 4:
							RewriteStudents_Obj(students);
							cout << "Данные обновлены!" << endl;
							break;
						default:
							cout << "Я не знаю такого ответа!" << endl;
							break;
						}
					} while (otvet == 1);
				}
				break;
			}
			// чтение в массив указателей
			case 2:
			{
				// чтение студентов в массив указателей
				vector<Student*> students = ReadStudentsFromFile_Points();
				// проверка наличия в массиве данных
				if (students.empty())
				{
					cout << "Ошибка считывания файла!" << endl;
					break;
				}
				else
				{
					// работа с данными
					do
					{
						// вывод количества доступных студентов
						cout << "Кол-во записанных студентов: " << students.size() << endl;

						cout << "Желаете продолжить работу с этими данными? Введите 1, если да: ";
						cin >> otvet;
						cin.clear();

						if (otvet != 1) {
							break;
						}

						// выбор студента
						cout << "Выберите студента: ";
						cin >> numberStudent;
						cin.clear();
						if (numberStudent > students.size() || numberStudent <= 0)
						{
							cout << "Введено неверное число" << endl;
							break;
						}
						cout << endl;
						students[numberStudent - 1]->ShowInf();
						cout << endl;

						cout << "Выберите действие над студентом:" << endl <<
							"(1) Cмена фамилии;" << endl <<
							"(2) Cмена отчества;" << endl <<
							"(3) Изменение стипендии;" << endl <<
							"(4) Перезапись данных с введенными изменениями;" << endl <<
							"(0) Закончить работу со студентами: ";
						cin >> otvet;
						cin.clear();
						system("cls");
						switch (otvet)
						{
						case 0:
							break;
							// смена фамилии
						case 1:
						{
							cout << "Введите новую фамилию студента: ";
							cin.clear();
							cin >> newSurname;
							system("cls");
							students[numberStudent - 1]->ChangeSurname(newSurname);
							break;
						}
						// смена отчества
						case 2:
						{
							cout << "Введите новое отчество студента: ";
							cin.clear();
							cin >> newFatherName;
							system("cls");
							students[numberStudent - 1]->ChangeFatherName(newFatherName);
							break;
						}
						// изменение стипендии
						case 3:
						{
							cout << "Введите любое число, если студент закрыл сессию на стипендию, или 0, если студент остался без стипендии: ";
							cin.clear();
							cin >> luckySession;
							system("cls");
							students[numberStudent - 1]->ChangeScholarship(luckySession);
							break;
						}
						// перезапись измененных данных
						case 4:
							RewriteStudents_Points(students);
							cout << "Данные обновлены!" << endl;
							break;
						default:
							cout << "Я не знаю такого ответа!" << endl;
							break;
						}
					} while (otvet == 1);
				}
				break;
			}
			default:
				cout << "Я не знаю такого ответа!" << endl;
				break;
			}
			break;
		}
			
		// создание новых студентов
		case 2:
		{
			cout << "Для создания массива объектов введите 1; " << endl
				<< "Для создания массива указателей на объекты введите 2" << endl;
			cin >> otvet;
			system("cls");
			switch (otvet)
			{
			// создание студентов в массив объектов
			case 1:
				
			{
				vector<Student> students = CreateArrayStudents_Obj();

				ShowStudents_Obj(students);

				cout << "Добавить данные в файл? Введите 1, если да" << endl;
				cin.clear();
				cin >> otvet;
				if (otvet == 1)
				{
					AddArrayStudents_Obj(students);
				}
				break;
			}
			// создание студентов в массив указателей
			case 2:
			{
				vector<Student*> students = CreateArrayStudents_Points();
				
				ShowStudents_Points(students);

				cout << "Добавить данные в файл? Введите 1, если да" << endl;
				cin.clear();
				cin >> otvet;
				if (otvet == 1)
				{
					AddArrayStudents_Points(students);
				}
				break;
			}
			default:
				cout << "Я не знаю такого ответа!" << endl;
				break;
			}
		}
		default:
			break;
		}

		cout << "Желаете продолжить работу со студентами? Введите 1, если да: ";
		cin.clear();
		cin >> otvet;
		system("cls");
	} while (otvet == 1);
}