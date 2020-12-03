// vector_lib.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include "vector_lib.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

	int output(char arr[10])
	{
	
		ofstream n("output.csv", ios::app); //Созадю/Открываю файл вывода в формате .csv
		for (int i = 0; i < 10; i++) //Цикл вывода векторов в output.csv
		{

			n << arr[i] << ',';


		}
		n << endl;
		n.close();
		return 0;
	}
