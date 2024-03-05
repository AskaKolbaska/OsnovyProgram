#include "Zadanie4.h"

// классы
void Pr4() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int otvet = 0, numberStudent = 0;
	string newSurname, newFatherName;
	bool luckySession;

	do
	{
		cout << "Для чтения студентов из файла введите 1;" << endl
			<< "Для создания нового студента введите 2" << endl;
		cin >> otvet;
		system("cls");
		switch (otvet)
		{
		// чтение студентов из файла
		case 1:
		{
			// чтение студентов из файла и запись их в массив
			vector<Student> students = ReadStudentsFromFile();

			// проверка наличия в массиве данных
			if (students.empty())
			{
				cout << "Ошибка считывания файла!" << endl;
				break;
			}
			else
			{
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
						RewriteStudents(students);
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
		// создание нового студента
		case 2:
		{
			cout << "Создать шаблонного студента? Введите 1, если да: ";
			cin >> otvet;
			cin.clear();
			int numberCreditBook = 0;

			if (otvet == 1)
			{
				cout << "Введите номер зачетной книжки: ";
				cin >> numberCreditBook;
			}

			// создание шаблона
			Student student(numberCreditBook);

			if (otvet != 1)
			{
				student = CreateStudentByHands(); // ввод нового студента с клавиатуры
			}
			student.ShowInf();
			
			// действия над студентом
			do
			{
				cout << "Желаете продолжить работу с этими данными? Введите 1, если да: ";
				cin >> otvet;
				cin.clear();

				if (otvet != 1) {
					break;
				}

				cout << "Выберите действие над студентом:" << endl <<
					"(1) Cмена фамилии;" << endl <<
					"(2) Cмена отчества;" << endl <<
					"(3) Изменение стипендии;" << endl <<
					"(4) Добавить данные в файл;" << endl <<
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
					cout << "Введите новую фамилию студента: ";
					cin.clear();
					cin >> newSurname;
					system("cls");
					student.ChangeSurname(newSurname);
					break;
				// смена отчества
				case 2:
					cout << "Введите новое отчество студента: ";
					cin.clear();
					cin >> newFatherName;
					system("cls");
					student.ChangeFatherName(newFatherName);
					break;
				// изменение стипендии
				case 3:
					cout << "Введите любое число, если студент закрыл сессию на стипендию, или 0, если студент остался без стипендии: ";
					cin.clear();
					cin >> luckySession;
					system("cls");
					student.ChangeScholarship(luckySession);
					break;
				// дозаписать данные
				case 4:
					AddStudent(student);
					cout << "Студент записан!" << endl;
					break;
				default:
					cout << "Я не знаю такого ответа, введите то, что я смогу понять!" << endl;
					break;
				}
			} while (otvet == 1);
			break;
		}	
		default:
			cout << "Я не знаю такого ответа!" << endl;
			break;
		}

		cout << "Желаете продолжить работу со студентами? Введите 1, если да: ";
		cin.clear();
		cin >> otvet;
		system("cls");
	} while (otvet == 1);
}