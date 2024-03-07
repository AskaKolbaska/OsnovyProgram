#pragma once
#include "Zadanie5.h"
#include "Zadanie4.h"
#include "ZadLab1.h"

//// ����������� true ���� ��� �������
//template <typename Type>
//constexpr enable_if_t<is_same_v<Type, Student>, bool> IsTypeStudent() {
//	return true;
//}
	
void Pr7();

template<typename Type>
constexpr enable_if_t<is_same_v<Type, Student>, vector<Type> > CreateData();

template<typename Type>
constexpr enable_if_t<!is_same_v<Type, Student>, vector<Type> > CreateData();

// ������� //

// �������� ������� ���������
template<typename Type>
constexpr enable_if_t<is_same_v<Type, Student>, vector<Type> > CreateData() {
	int otvet = 0;
	vector<Type> data;
	do
	{
		Student stud = CreateOneStudent();
		data.push_back(stud);

		cout << "��������� ���� �����? (0) ";
		cin >> otvet;
	} while (otvet != 0);

	return data;
}

template<typename Type>
constexpr enable_if_t<!is_same_v<Type, Student>, vector<Type> > CreateData() {
	int otvet = 0;
	Type _data;
	vector<Type> data;
	do
	{
		cout << "������� �������: ";
		cin >> _data;
		data.push_back(_data);

		cout << "��������� ���� �����? (0) ";
		cin >> otvet;
	} while (otvet != 0);

	return data;
}
