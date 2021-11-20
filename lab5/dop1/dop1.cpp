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
using namespace std;

void Fill(const int& str, const int& clmn, int** array);
void Out(const int& str, const int& clmn, int** array);
void Out(const int& size, int* array);
int prod(const int& size, int* array);
void check(int& number);


int main()
{
	cout << "enter numb of str ";
	int str = 0;
	check(str);
	cout << "enter numb of clmn ";
	int clmn = 0;
	check(clmn);


	int** array = new int* [str];
	for (int i = 0; i < str; i++)
	{
		array[i] = new int [clmn];
	}
	Fill(str, clmn, array);
	Out(str, clmn, array);

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
	Out(size, array2);
	cout << "prod = " << prod(size, array2);



	for (int i = 0; i < str; i++)
	{
		delete[] array[i];
	}
	delete[] array;

	delete[] array2;

	return 0;
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

int prod(const int& size, int* array)
{
	int prod = 1;
	for (int i = 0; i < size; i++)
	{
		prod *= array[i];
	}
	return prod;
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

