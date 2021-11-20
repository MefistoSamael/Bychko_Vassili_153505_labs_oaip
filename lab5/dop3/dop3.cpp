﻿#include <iostream>
using namespace std;

void check(int& number);//проверка ввода


void birth(const int& str, const int& clmn, int**& array);//создание массива
void birth(const int& size, int*& array);

void death(const int& str, int** array);// удаление массива
void death(int* array);


void Fill(const int& str, const int& clmn, int** array);//заполнение массива


void Out(const int& str, const int& clmn, int** array);//вывод массива
void Out(const int& size, int* array);

void search(const int& str, const int& clmn, int** array, int* array2);//поиск нечетных эллементов


void avg(const int& size, int* array, int& avg);



int main()
{
	cout << "enter numb of str ";
	int str = 0;
	check(str);
	cout << "enter numb of clmn ";
	int clmn = 0;
	check(clmn);
	int** array = NULL;
	birth(str, clmn, array);

	Fill(str, clmn, array);
	Out(str, clmn, array);
	/*
	короче, у нас косяк с размером второго массива, и функицей search. Ее надо будет переписать.
	По поводу размера. Его можно найти следующим образом: пробегаешь изначальный массив и ищешь искомые эллементы.
	Все, я свою задачу выполнил. Иду в арех.
	*/
	int* array2 = NULL;
	birth(str, array2);
	search(str, clmn, array, array2);
	Out(str, array2);
	int aver = 0;
	avg(str, array2, aver);
	cout << "average of new array = " << aver;


	death(str, array);
	death(array2);
	return 0;
}

void check(int& number)
{
	while (true)
	{
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "oops, smth went wrong, try again\n";
		}
		else break;
	}
}


void Fill(const int& str, const int& clmn, int** array)
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < clmn; j++)
		{
			cout << "Enter array[" << i << "][" << j << "] ";
			check(array[i][j]);
		}
	}
	cout << "\n";
}


void Out(const int& str, const int& clmn, int** array)
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < clmn; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void Out(const int& size, int* array)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}

void birth(const int& str, const int& clmn, int**& array)
{
	array = new int* [str];
	for (int i = 0; i < str; i++)
	{
		array[i] = new int[clmn];
	}
}
void birth(const int& size, int*& array)
{
	array = new int[size];
}


void death(const int& str, int** array)
{
	for (int i = 0; i < str; i++)
	{
		delete[] array[i];
	}
	delete[] array;
}
void death(int* array)
{
	delete[] array;
}


void search(const int& str, const int& clmn, int** array, int *array2)
{
	int k = 0;
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < clmn; j++)
		{
			if (clmn % 2 != 0) continue;
			if (array[i][j] % 2 != 0)
			{
				*array[k] = array[i][j];
				k++;
			}
		}
	}
	
}

void avg(const int& size, int* array, int& avg)
{
	int k = 1;
	for (int i = 0; i < size; i++)
	{
		avg += array[i];
		k++;
	}
	avg /= k;
}




