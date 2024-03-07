#pragma once
#include "Zadanie5.h"
#include "Zadanie4.h"
#include "ZadLab1.h"

//// возвращение true если тип студент
//template <typename Type>
//constexpr enable_if_t<is_same_v<Type, Student>, bool> IsTypeStudent() {
//	return true;
//}
	
void Pr7();

template<typename Type>
constexpr enable_if_t<is_same_v<Type, Student>, vector<Type> > CreateData();

template<typename Type>
constexpr enable_if_t<!is_same_v<Type, Student>, vector<Type> > CreateData();

// функции //

// создание вектора элементов
template<typename Type>
constexpr enable_if_t<is_same_v<Type, Student>, vector<Type> > CreateData() {
	int otvet = 0;
	vector<Type> data;
	do
	{
		Student stud = CreateOneStudent();
		data.push_back(stud);

		cout << "Закончить ввод чисел? (0) ";
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
		cout << "Введите элемент: ";
		cin >> _data;
		data.push_back(_data);

		cout << "Закончить ввод чисел? (0) ";
		cin >> otvet;
	} while (otvet != 0);

	return data;
}
