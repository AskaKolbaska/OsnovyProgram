#pragma once

#include <sstream>
#include <fstream>
#include <iostream>
#include <locale>
#include <Windows.h>
#include <vector>
#include "Zadanie4.h"

using namespace std;

// чтение студентов в массив объектов
vector<Student> ReadStudentsFromFile_Obj();

// чтение студентов в массив указателей
vector<Student*> ReadStudentsFromFile_Points();

// создание указателя студента вручную
Student* CreateStudentByHands_Point();

// создание массива объектов студентов
vector<Student> CreateArrayStudents_Obj();

// создание массива указателей на студентов
vector<Student*> CreateArrayStudents_Points();

// перезапись массива объектов в файл
void RewriteStudents_Obj(vector<Student>);

// перезапись массива указателей в файл
void RewriteStudents_Points(vector<Student*>);

// вывод массива данных (объекты)
void ShowStudents_Obj(vector<Student>);

// вывод массива данных (указатели)
void ShowStudents_Points(vector<Student*>);

// дозапись массива объектов в файл
void AddArrayStudents_Obj(vector<Student>);

// дозапись массива указателей в файл
void AddArrayStudents_Points(vector<Student*>);