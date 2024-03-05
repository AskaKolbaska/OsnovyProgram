#pragma once
#include "Zadanie4.h"
#include <list>

using namespace std;

// TODO: �������???

// ���� ������
template <class Type=Student> // ������
struct MyNode
{
	Type value; // ���������� ����
	MyNode* next; // ��������� �� ��������� �������

	MyNode(Type _val) : value(_val), next(nullptr) {}
};

// ������
template <class Type = Student>
struct MyList {
	struct MyNode<Type>* first; // ��������� �� ������ ��-� ������
	struct MyNode<Type>* last; // ��������� �� ��������� ��-� ������

	MyList() : first(nullptr), last(nullptr) {}

	// �������� �� ������� ������
	bool is_empty() {
		return first == nullptr;
	}

	// ��������� ���-�� ��������� ������
	int size_list() {
		int size = 0;
		MyNode<Type>* p = first;
		if (is_empty())
		{
			cout << "������ ����!" << endl;
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

	// ��������� ������ �������� � ������
	int index_element(MyNode<Type>* element) {
		int index = -1;
		MyNode<Type>* p = first;
		if (is_empty())
		{
			cout << "������ ����!" << endl;
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

	// ���������� ��-�� � ����� ������
	void push_back(Type _val) {
		MyNode<Type>* p = new MyNode<Type>(_val);
		
		// ���� ������ ������
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

	// �������� ������� ��������
	void remove_first() {
		if (is_empty()) return;
		MyNode<Type>* p = first;
		first = p->next;
		delete p;
	}

	// �������� ���������� ��������
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

	// ������ ����� ������
	void print() {
		cout << endl << "������:" << endl << endl;
		MyNode<Type>* p = first;
		if (is_empty())
		{
			cout << "������ ����!" << endl;
		}
		else if (typeid(p->value) == typeid(Student&)) { // ���� ��� �������� � ���� �������� ����������� ������ �������, �� ���������� ����� ������
			while (p)
			{
				p->value.ShowInf();
				cout << endl;
				p = p->next;
			}
			
		}
	}

	// ������ ������� ��������
	void print_first() {
		MyNode<Type>* p = first;
		if (is_empty())
		{
			cout << "������ ����!" << endl;
		}
		else if (typeid(p->value) == typeid(Student&)) {
			p->value.ShowInf();
		}
	}

	// ������ ���������� ��������
	void print_last() {
		MyNode<Type>* p = last;
		if (is_empty())
		{
			cout << "������ ����!" << endl;
		}
		else if (typeid(p->value) == typeid(Student&)) {
			p->value.ShowInf();
		}
	}

	// �������� ��-�� �� �������
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

	// ����� �� ������ �������
	void FindNode(int numberCreditBook) {
		MyNode<Type>* p = first;
		if (is_empty())
		{
			cout << "������ ����!" << endl;
		}

		// ���� ��� ������ �� ������� ��������
		if (typeid(this->first->value) != typeid(Student&))
		{
			cout << "������ �� ���!" << endl;
		}
		else {
			bool isShowed = false; // ��� �� ������ �������
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
				cout << "������ � ������ ���!" << endl;
			}
		}
	}

	MyNode<Type>* operator[] (const int index) {
		if (is_empty()) return nullptr;
		MyNode<Type>* p = first;
		for (int i = 0; i < index; i++) {
			p = p->next;
			if (!p) return nullptr;
		}
		return p;
	}
};

Student CreateOneStudent();

template <class Type>
MyList<Type> CreateList();

template <class Type>
void AddElement(MyList<Type>*);

template <class Type>
void RemoveFirstElement(MyList<Type>*);

template <class Type>
void RemoveLastElement(MyList<Type>* list);

template <class Type>
void RemoveElementByIndex(MyList<Type>* list);

template <class Type>
void FindByCreditBook(MyList<Type>* list);

// ������� //

// �������� ������
template <class Type = Student>
MyList<Type> CreateList() {
	int otvet;
	MyList<Type> list;

	if (typeid(Type) == typeid(Student))
	{
		do
		{
			// ���������� �������� � ����� ������
			Student stud = CreateOneStudent();
			list.push_back(stud);

			cout << endl << "��������� ���� ���������? (0) ";
			cin >> otvet;
		} while (otvet != 0);
	}
	else
	{
		do
		{
			// ���������� ��-�� � ����� ������
			cout << "������� ��-�: ";
			cin >> otvet;
			list.push_back(otvet);

			cout << endl << "��������� ����? (0) ";
			cin >> otvet;
		} while (otvet != 0);
	}


	return list;
}

// ���������� �������� � ����� ������
template <class Type = Student>
void AddElement(MyList<Type>* list) {
	cout << endl << "���������� ������ ��������!" << endl << endl;
	if (typeid(Type) == typeid(Student)) {
		Type element = CreateOneStudent();
		list->push_back(element);
	}
}

// �������� ������� ��������
template <class Type = Student>
void RemoveFirstElement(MyList<Type>* list) {
	int otvet = 0;
	list->print_first();
	cout << endl << "�� ����� ������ ������� ���� �������? (1): ";
	cin >> otvet;
	switch (otvet)
	{
	case 1: {
		list->remove_first();
		cout << "�������� ���������!" << endl;
		break;
	}
	default: {
		cout << "�������� ��������!" << endl;
		break;
	}
	}
}

// �������� ���������� ��������
template <class Type = Student>
void RemoveLastElement(MyList<Type>* list) {
	int otvet = 0;
	list->print_last();
	cout << endl << "�� ����� ������ ������� ���� �������? (1): ";
	cin >> otvet;
	switch (otvet)
	{
	case 1: {
		list->remove_last();
		cout << "�������� ���������!" << endl;
		break;
	}
	default: {
		cout << "�������� ��������!" << endl;
		break;
	}
	}
}

// �������� �������� �� ������ ������
template <class Type = Student>
void RemoveElementByIndex(MyList<Type>* list) {
	int size = list->size_list();
	int otvet = 0;
	int index = 0;
	cout << "������ ������: " << size << endl;

	do
	{
		cout << "������� ����� �������� ��� ��������: ";
		cin >> index;

		if (index <= 0 || index > size)
		{
			cout << "����������� ������ ����� ��������!" << endl;
		}
		else {
			cout<< "�� ����� ������ ������� ���� �������? (1): ";
			cin >> otvet;

			switch (otvet)
			{
			case 1: {
				list->remove(index);
				cout << "�������� ���������!" << endl;
				break;
			}
			default: {
				cout << "�������� ��������!" << endl;
				break;
			}
			}
			break;
		}
	} while (true);
	
}

// ����� �� ������ �������
template <class Type = Student>
void FindByCreditBook(MyList<Type>* list) {
	int otvet = 0;
	cout << "������� ����� �������: ";
	cin >> otvet;

	list->FindNode(otvet);
}