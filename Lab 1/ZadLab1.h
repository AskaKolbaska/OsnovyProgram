#pragma once
#include "Zadanie4.h"
#include <list>

using namespace std;

// TODO: ШАБЛОНЫ???

// узел списка
template <class Type=Student> // шаблон
struct MyNode
{
	Type value; // содержимое узла
	MyNode* next; // указатель на следующий элемент

	MyNode(Type _val) : value(_val), next(nullptr) {}
};

// список
template <class Type = Student>
struct MyList {
	struct MyNode<Type>* first; // указатель на первый эл-т списка
	struct MyNode<Type>* last; // указатель на последний эл-т списка

	MyList() : first(nullptr), last(nullptr) {}

	// проверка на пустоту списка
	bool is_empty() {
		return first == nullptr;
	}

	// добавление эл-та в конец списка
	void push_back(Type _val) {
		MyNode<Type>* p = new MyNode<Type>(_val);
		
		// если список пустой
		if (is_empty())
		{
			first = p;
			last = p;
		}
		else {
			last->next = p;
			last = p;
		}
	}

	// удаление первого элемента
	void remove_first() {
		if (is_empty()) return;
		MyNode* p = first;
		first = p->next;
		delete p;
	}

	// удаление последнего элемента
	void remove_last() {
		if (is_empty()) return;
		if (first == last) {
			remove_first();
			return;
		}
		MyNode* p = first;
		while (p->next != last) p = p->next;
		p->next = nullptr;
		delete last;
		last = p;
	}

	// печать всего списка
	void print() {
		MyNode<Type>* p = first;
		if (is_empty())
		{
			cout << "Список пуст!" << endl;
		}
		else if (typeid(p->value) == typeid(Student&)) { // если тип элемента в узле является экземпляром класса Студент, то вызывается метод класса
			while (p)
			{
				p->value.ShowInf();
				cout << endl;
				p = p->next;
			}
			
		}
	}

	// поиск по номеру зачетки
	void FindNode(int numberCreditBook) {
		MyNode<Type>* p = first;
		if (is_empty())
		{
			cout << "Список пуст!" << endl;
		}

		// если тип списка не объекты студенты
		if (typeid(this->first->value) != typeid(Student&))
		{
			cout << "Список не тот!" << endl;
		}
		else {
			bool isShowed = false; // был ли найден студент
			while (p)
			{
				
				if (p->value.ReturnNumberCreditBook() == numberCreditBook)
				{
					p->value.ShowInf();
					isShowed = true;
				}

				cout << endl;
				p = p->next;
			}

			if (!isShowed)
			{
				cout << "Такого в списке нет!" << endl;
			}
		}
	}
};

Student CreateOneStudent();

template <class Type>
MyList<Type> CreateList();

// создание списка
template <class Type = Student>
MyList<Type> CreateList() {
	int otvet;
	MyList<Type> list;

	if (typeid(Type) == typeid(Student))
	{
		do
		{
			// добавление студента в конец списка
			Student stud = CreateOneStudent();
			list.push_back(stud);

			cout << endl << "Закончить ввод студентов? (0) ";
			cin >> otvet;
		} while (otvet != 0);
	}
	else
	{
		do
		{
			// добавление эл-та в конец списка
			cout << "Введите эл-т: ";
			cin >> otvet;
			list.push_back(otvet);

			cout << endl << "Закончить ввод? (0) ";
			cin >> otvet;
		} while (otvet != 0);
	}


	return list;
}
