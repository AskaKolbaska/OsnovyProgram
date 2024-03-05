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

// TODO: ������
template <class Type = Student>
struct MyList {
	struct MyNode<Type>* first; // ��������� �� ������ ��-� ������
	struct MyNode<Type>* last; // ��������� �� ��������� ��-� ������

	MyList() : first(nullptr), last(nullptr) {}

	// �������� �� ������� ������
	bool is_empty() {
		return first == nullptr;
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
		MyNode* p = first;
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
		MyNode* p = first;
		while (p->next != last) p = p->next;
		p->next = nullptr;
		delete last;
		last = p;
	}

	// ������ ����� ������
	void print() {
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

	// TODO: ����� �� ������ �������
	MyNode<Type> FindNode(int numberCreditBokk) {
		MyNode<Type>* p = first;
		if (is_empty())
		{
			cout << "������ ����!" << endl;
			return nullptr;
		}

		// ���� ��� ������ �� ������� ��������
		if (typeid(this->first->value) != typeid(Student&))
		{
			cout << "������ �� ���!" << endl;
			return nullptr;
		}
		else {
			
		}
	}
};

Student CreateOneStudent();

template <class Type>
MyList<Type> CreateList();

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
