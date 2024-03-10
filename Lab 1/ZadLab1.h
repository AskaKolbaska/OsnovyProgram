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

	// получение кол-ва элементов списка
	int size_list() {
		int size = 0;
		MyNode<Type>* p = first;
		if (is_empty())
		{
			cout << "Список пуст!" << endl;
			return size;
		}
		else {
			while (p)
			{
				size++;
				p = p->next;
			}
			return size;
		}	
	}

	// получение номера элемента в списке
	int index_element(MyNode<Type>* element) {
		int index = -1;
		MyNode<Type>* p = first;
		if (is_empty())
		{
			cout << "Список пуст!" << endl;
			return index;
		}
		else {
			while (p)
			{
				if (element != p)
				{
					index++;
					p = p->next;
				}
				else {
					break;
				}
			}
			return index;
		}
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
		MyNode<Type>* p = first;
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
		MyNode<Type>* p = first;
		while (p->next != last) p = p->next;
		p->next = nullptr;
		delete last;
		last = p;
	}

	// печать всего списка
	//void print() {
	//	cout << endl << "Список:" << endl << endl;
	//	MyNode<Type>* p = first;
	//	if (is_empty())
	//	{
	//		cout << "Список пуст!" << endl;
	//	}
	//	else if (IsTypeStudent(this)) { // если тип элемента в узле является экземпляром класса Студент, то вызывается метод класса
	//		while (p)
	//		{
	//			p->value.ShowInf();
	//			cout << endl;
	//			p = p->next;
	//		}
	//	}
	//	else if (enable_if_t<!is_same_v<Type, Student>, bool>) {
	//		while (p)
	//		{
	//			cout << p->value << endl;
	//			p = p->next;
	//		}
	//	}
	//}

	enable_if_t<is_same_v<Type, Student>, bool> is_printed() {
		cout << endl << "Список:" << endl << endl;
		MyNode<Type>* p = first;
		if (is_empty())
		{
			cout << "Список пуст!" << endl;
			return false;
		}
		else {
			while (p)
			{
				p->value.ShowInf();
				cout << endl;
				p = p->next;
			}
			return true;
		}
	}

	/*enable_if_t<!is_same_v<Type, Student>, bool> is_printed() {
		cout << endl << "Список:" << endl << endl;
		MyNode<Type>* p = first;
		if (is_empty())
		{
			cout << "Список пуст!" << endl;
			return false;
		}
		else {
			while (p)
			{
				cout << p->value << endl;
				p = p->next;
			}
			return true;
		}
	}*/

	// печать первого элемента
	void print_first() {
		MyNode<Type>* p = first;
		if (is_empty())
		{
			cout << "Список пуст!" << endl;
		}
		else if (typeid(p->value) == typeid(Student&)) {
			p->value.ShowInf();
		}
	}

	// печать последнего элемента
	void print_last() {
		MyNode<Type>* p = last;
		if (is_empty())
		{
			cout << "Список пуст!" << endl;
		}
		else if (typeid(p->value) == typeid(Student&)) {
			p->value.ShowInf();
		}
	}

	// удаление эл-та по индексу
	void remove(int index) {
		if (is_empty()) return;
		
		if (index == 0)
		{
			remove_first();
			return;
		}
		else if (index == this->size_list())
		{
			remove_last();
			return;
		}

		MyNode<Type>* slow = first;
		MyNode<Type>* fast = first->next;
		
		while (fast && this->index_element(fast) != index) {
			fast = fast->next;
			slow = slow->next;
		}
		
		slow->next = fast->next;
		delete fast;
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

	MyNode<Type>* find_el(const int index) {
		if (is_empty()) return nullptr;
		MyNode<Type>* p = first;
		for (int i = 0; i < index; i++) {
			p = p->next;
			if (!p) return nullptr;
		}
		return p;
	}
};

template <class Type>
constexpr enable_if_t<is_same_v<Type, Student>, bool> IsTypeStudent(MyList<Type>*);

//template <class Type>
//constexpr enable_if_t<!is_same_v<Type, Student>, bool> IsTypeStudent(MyList<Type>*);

template <class Type>
void PrintList(MyList<Type>*);

Student CreateOneStudent();

template <class Type>
MyList<Type> CreateList();

template <class Type>
MyList<Type> CreateList(vector<Type>);

template <class Type>
void AddElement(MyList<Type>*);

template <class Type>
void RemoveFirstElement(MyList<Type>*);

template <class Type>
void RemoveLastElement(MyList<Type>*);

template <class Type>
void RemoveElementByIndex(MyList<Type>*);

template <class Type>
void FindByCreditBook(MyList<Type>*);

template <class Type>
void WriteList(MyList<Type>);

// ФУНКЦИИ //

// является ли список студентами
template <class Type>
constexpr enable_if_t<is_same_v<Type, Student>, bool> IsTypeStudent(MyList<Type> list) {
	return true;
}

//template <class Type>
//constexpr enable_if_t<!is_same_v<Type, Student>, bool> IsTypeStudent(MyList<Type> list) {
//	return false;
//}

template <class Type>
void PrintList(MyList<Type>* list) {
	if (IsTypeStudent(list))
	{
		MyNode<Type>* p = list->first;
		if (list->is_empty())
		{
			cout << "Список пуст!" << endl;
		}
		else
		{
			for (int i = 0; i < list->size_list(); i++)
			{
				
				cout << endl;
				p->next;
			}

			//while (p)
			//{
			//	list.p->value.ShowInf();
			//	cout << endl;
			//	p->next;
			//}
		}
	}
	else
	{
		MyNode<Type>* p = list->first;
		if (list->is_empty())
		{
			cout << "Список пуст!" << endl;
		}
		else
		{
			while (p)
			{
				cout << p->value << endl;
				p->next;
			}
		}
	}
}

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

// создание списка
template <class Type = Student>
MyList<Type> CreateList(vector<Type> data) {
	MyList<Type> list;
	for (int i = 0; i < data.size(); i++)
	{
		list.push_back(data[i]);
	}
	return list;
}

// добавление элемента в конец списка
template <class Type = Student>
void AddElement(MyList<Type>* list) {
	cout << endl << "Добавление нового элемента!" << endl << endl;
	if (typeid(Type) == typeid(Student)) {
		Type element = CreateOneStudent();
		list->push_back(element);
	}
}

// удаление первого элемента
template <class Type = Student>
void RemoveFirstElement(MyList<Type>* list) {
	int otvet = 0;
	list->print_first();
	cout << endl << "Вы точно хотите удалить этот элемент? (1): ";
	cin >> otvet;
	switch (otvet)
	{
	case 1: {
		list->remove_first();
		cout << "Удаление завершено!" << endl;
		break;
	}
	default: {
		cout << "Удаление отменено!" << endl;
		break;
	}
	}
}

// удаление последнего элемента
template <class Type = Student>
void RemoveLastElement(MyList<Type>* list) {
	int otvet = 0;
	list->print_last();
	cout << endl << "Вы точно хотите удалить этот элемент? (1): ";
	cin >> otvet;
	switch (otvet)
	{
	case 1: {
		list->remove_last();
		cout << "Удаление завершено!" << endl;
		break;
	}
	default: {
		cout << "Удаление отменено!" << endl;
		break;
	}
	}
}

// удаление элемента по номеру списка
template <class Type = Student>
void RemoveElementByIndex(MyList<Type>* list) {
	int size = list->size_list();
	int otvet = 0;
	int index = 0;
	cout << "Размер списка: " << size << endl;

	do
	{
		cout << "Введите номер элемента для удаления: ";
		cin >> index;

		if (index <= 0 || index > size)
		{
			cout << "Неправильно выбран номер элемента!" << endl;
		}
		else {
			cout<< "Вы точно хотите удалить этот элемент? (1): ";
			cin >> otvet;

			switch (otvet)
			{
			case 1: {
				list->remove(index);
				cout << "Удаление завершено!" << endl;
				break;
			}
			default: {
				cout << "Удаление отменено!" << endl;
				break;
			}
			}
			break;
		}
	} while (true);
	
}

// поиск по номеру зачетки
template <class Type = Student>
void FindByCreditBook(MyList<Type>* list) {
	int otvet = 0;
	cout << "Введите номер зачетки: ";
	cin >> otvet;

	list->FindNode(otvet);
}

// запись списка в файл
template <class Type = Student>
void WriteList(MyList<Type>* list) {
	ofstream in("list.txt"); // открытие файла для перезаписи
	if (in.is_open())
	{
		MyNode<Type>* p = list->first;
		if (list->is_empty())
		{
			cout << "Список пуст!" << endl;
			return;
		}
		else if (typeid(p->value) == typeid(Student&)) { // если тип элемента в узле является экземпляром класса Студент, то вызывается метод класса
			while (p)
			{
				in << p->value.StrForWrite();
				p = p->next;
				in << endl;
			}

		}
	}
	else
	{
		cout << "Ошибка записи!" << endl;
	}
	cout << "Запись завершена!" << endl;
	in.close();
}