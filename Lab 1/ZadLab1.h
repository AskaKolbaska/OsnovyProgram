#pragma once
#include "Zadanie4.h"
#include <list>

using namespace std;

// TODO: �������???

// ���� ������
//template <class Type=Student> // ������
struct MyNode
{
	Student value; // ���������� ����
	MyNode* next; // ��������� �� ��������� �������

	MyNode(Student _val) : value(_val), next(nullptr) {}
};

// TODO: ������
struct MyList {
	struct MyNode* first; // ��������� �� ������ ��-� ������
	struct MyNode* last; // ��������� �� ��������� ��-� ������

	MyList() : first(nullptr), last(nullptr) {}

	// �������� �� ������� ������
	bool is_empty() {
		return first == nullptr;
	}

	// ���������� ��-�� � ����� ������
	void push_back(Student _val) {
		MyNode* p = new MyNode(_val);
		
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

	// ������ ����� ������
	void print() {
		MyNode* p = first;
		if (is_empty())
		{
			cout << "������ ����!" << endl;
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

	// TODO: ����� �� ���������
	MyNode FindNode() {

	}
};

Student CreateOneStudent();

MyList CreateList();