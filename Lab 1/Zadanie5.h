#pragma once

#include <sstream>
#include <fstream>
#include <iostream>
#include <locale>
#include <Windows.h>
#include <vector>
#include "Zadanie4.h"

using namespace std;

// ������ ��������� � ������ ��������
vector<Student> ReadStudentsFromFile_Obj();

// ������ ��������� � ������ ����������
vector<Student*> ReadStudentsFromFile_Points();

// �������� ��������� �������� �������
Student* CreateStudentByHands_Point();

// �������� ������� �������� ���������
vector<Student> CreateArrayStudents_Obj();

// �������� ������� ���������� �� ���������
vector<Student*> CreateArrayStudents_Points();

// ���������� ������� �������� � ����
void RewriteStudents_Obj(vector<Student>);

// ���������� ������� ���������� � ����
void RewriteStudents_Points(vector<Student*>);

// ����� ������� ������ (�������)
void ShowStudents_Obj(vector<Student>);

// ����� ������� ������ (���������)
void ShowStudents_Points(vector<Student*>);

// �������� ������� �������� � ����
void AddArrayStudents_Obj(vector<Student>);

// �������� ������� ���������� � ����
void AddArrayStudents_Points(vector<Student*>);