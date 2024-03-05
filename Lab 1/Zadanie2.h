#pragma once
#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <locale>
#include <sstream>
#include "Zadanie1.h"
#include "Pr1.h"
 
using namespace std;

string UserName();

int choiceActionFile();

void ReadStrFromFile();

void OpenFileWrite(string login);

int OpenFileReadNumber();

void ClearFile();

void FindUser(string login);