#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <thread>
#include <algorithm>
#include "vector_lib.h"
#include "vector_lib.cpp"
using namespace std;

void p(char v[10])
{
	vector<char> vector[1];
	for (int i = 0; i < 10; i++)
	{
		vector[0].push_back(v[i]);
	}
	int count;
	count = 1;
	while (count != 0 || count < 0)
	{
		count = 0;
		for (int j = 0; j < 10; j++)
		{
			if (j != 9)
			{
				if (vector[0][j + 1] < vector[0][j])
				{
					swap(vector[0][j + 1], vector[0][j]);
					count++;
				}
			}
		}

	}
	char arr[10];
	for (int j = 0; j < 10; j++)
	{

		arr[j] = vector[0][j];
	}
	output(arr);
	
		for (int j = 0; j < vector[0].size(); j++)
		{
			cout << setw(5) << vector[0][j];
		}
	cout << endl;
}

int main()
{
	char c;
	ifstream f("input.txt"); //Открываю файл
	vector<char> v_n[10];
	for (int i = 0; i < 10; i++) //Заполняю векторы символами из input.txt
	{
		for (int j = 0; j < 10; j++)
		{
			f >> c;
			v_n[i].push_back(c);
		}
	}
	for (int i = 0; i < 10; i++) //Вывожу заполненный вектор
	{
		for (int j = 0; j < v_n[i].size(); j++)
		{
			cout << setw(5) << v_n[i][j];
		}
		cout << endl;
	}
	f.close(); //Закрываю файл ввода
	char arr[10];
	cout << "----------------------------------------------------\n";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			arr[j] = v_n[i][j];
			if (j == 9)
			{
				thread th (p,arr);
				th.join();
			}
		}
	}
}
