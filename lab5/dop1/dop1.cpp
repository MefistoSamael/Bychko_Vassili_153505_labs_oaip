/*
Дан двумерный динамический массив целых чисел А размерностью n  k .
Размерность массива (n = 5, k = 6) ввести с клавиатуры. Значения элементов массива
ввести с клавиатуры. Создать динамический массив из элементов, расположенных на
главной диагонали матрицы и имеющих четное значение. Вычислить произведение
элементов динамического массива.
Созданный массив и результат произведения вывести на экран.
Использовать функции
*/

#include <iostream>
#include "MyLibrary.h"
#include <Windows.h>
using namespace std;



int main()
{
	HINSTANCE load1;
	load1 = LoadLibrary(L"MyLibrary.dll");
	typedef double (*check) (int&);
	check checktrue;
	checktrue = (check)GetProcAddress(load1, "check");


	HINSTANCE load2;
	load2 = LoadLibrary(L"MyLibrary.dll");
	typedef double (*Fill) (const int&, const int&, int**);
	Fill Fil;
	Fil = (Fill)GetProcAddress(load2, "Fill");


	HINSTANCE load3;
	load3 = LoadLibrary(L"MyLibrary.dll");
	typedef double (*Out2) (const int&, const int&, int**);
	Out2 OOut2;
	OOut2 = (Out2)GetProcAddress(load3, "Out2");


	HINSTANCE load4;
	load4 = LoadLibrary(L"MyLibrary.dll");
	typedef double (*Out) (const int&, int*);
	Out OOut;
	OOut = (Out)GetProcAddress(load3, "Out");


	HINSTANCE load5;
	load5 = LoadLibrary(L"MyLibrary.dll");
	typedef double (*prod) (const int&, int*);
	prod pprod;
	pprod = (prod)GetProcAddress(load3, "prod");

	cout << "enter numb of str ";
	int str = 0;
	checktrue(str);
	cout << "enter numb of clmn ";
	int clmn = 0;
	checktrue(clmn);


	int** array = new int* [str];
	for (int i = 0; i < str; i++)
	{
		array[i] = new int [clmn];
	}
	Fil(str, clmn, array);
	OOut2(str, clmn, array);

	int a = 0;
	if (str < clmn) a = str; //находим меньшую "сторону" маторицы, чтобы понять до куда считать
	else a = clmn;
	
	int k = 0;
	for (int i = 0, j = 0; i < a; i++, j++)//считаем количество четных эллементов, чтобы понять длинну нового массива
	{
		if (array[i][j] % 2 == 0) k++;
	}
	if (k == 0)
	{
		cout << "there isnt any honest number";
		return 0;
	}

	int size = k;

	int* array2 = new int[size];
	k = 0;
	for (int i = 0, j = 0; j < a; i++, j++)// заполнение нового массива числами
	{
		if (array[i][j] % 2 == 0)
		{
			array2[k] = array[i][j];
			k++;
		}
	}
	OOut(size, array2);
	cout << "prod = " << pprod(size, array2);



	for (int i = 0; i < str; i++)
	{
		delete[] array[i];
	}
	delete[] array;

	delete[] array2;

	FreeLibrary(load1);
	FreeLibrary(load2);
	FreeLibrary(load3);
	FreeLibrary(load4);
	FreeLibrary(load5);
	return 0;
}

