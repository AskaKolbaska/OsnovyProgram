#pragma once
#include "Zadanie4.h"
#include <list>

using namespace std;

// TODO: ШАБЛОНЫ???

// узел списка
//template <class Type=Student> // шаблон
struct MyNode
{
	Student value; // содержимое узла
	MyNode* next; // указатель на следующий элемент

	MyNode(Student _val) : value(_val), next(nullptr) {}
};

// TODO: список
struct MyList {
	struct MyNode* first; // указатель на первый эл-т списка
	struct MyNode* last; // указатель на последний эл-т списка

	MyList() : first(nullptr), last(nullptr) {}

	// проверка на пустоту списка
	bool is_empty() {
		return first == nullptr;
	}

	// добавление эл-та в конец списка
	void push_back(Student _val) {
		MyNode* p = new MyNode(_val);
		
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

	// печать всего списка
	void print() {
		MyNode* p = first;
		if (is_empty())
		{
			cout << "Список пуст!" << endl;
		}
		else {
			while (p)
			{
				p->value.ShowInf();
				cout << endl;
				p = p->next;
			}
			cout << endl;
		}
	}

	// TODO: поиск по параметру
	MyNode FindNode() {

	}
};

Student CreateOneStudent();

MyList CreateList();