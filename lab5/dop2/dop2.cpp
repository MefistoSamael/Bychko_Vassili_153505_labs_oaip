/*
Создать двумерный динамический массив вещественных чисел. Определить,
встречаются ли среди них элементы с нулевым значением. Если встречаются такие
элементы, то определить их индексы и общее количество. Переставить элементы этого
массива в обратном порядке и вывести на экран.
Использовать функции.
*/

#include <iostream>
using namespace std;

void check(int& number);//проверка ввода


void birth(const int& str, const int& clmn, int**& array);//создание массива


void death(const int& str, int** array);// удаление массива


void Fill(const int& str, const int& clmn, int** array);//заполнение массива


void Out(const int& str, const int& clmn, int** array);//вывод массива


void search(const int& str, const int& clmn, int** array, int& numz);//поиск нулей


void replace(const int& str, const int& clmn, int** array);//перемещение эллементов массива




int main()
{
	int str = 0;
	cout << "enter numb of str ";
	check(str);
	int clmn = 0;
	cout << "enter numb of clmn ";
	check(clmn);
	int** array = NULL;
	birth(str, clmn, *&array);
	
	Fill(str, clmn, array);
	Out(str, clmn, array);


	int numz = 0;
	search(str, clmn, array, numz);

	replace(str, clmn, array);
	Out(str, clmn, array);
	

	death(str, array);
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


void birth(const int& str, const int& clmn, int**& array)
{
	array = new int* [str];
	for (int i = 0; i < str; i++)
	{
		array[i] = new int[clmn];
	}
}


void death(const int& str, int** array)
{
	for (int i = 0; i < str; i++)
	{
		delete[] array[i];
	}
	delete[] array;
}


void search(const int& str, const int& clmn, int** array, int& numz)
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < clmn; j++)
		{
			if (array[i][j] == 0)
			{
				numz++;
				cout << "index of " << numz << " zero elemnt: (" << i << ";" << j << ")\n";
			}
		}
	}
	if (numz == 0) cout << "there isnt any zero element\n";
	cout << "numb of zero ellements = " << numz << "\n";
}


void replace(const int& str, const int& clmn, int** array)
{
	int numbop = 0;
	for (int i = str - 1; i >= 0; i--)
	{
		for (int j = clmn - 1; j >= 0; j--)
		{
			int temp = array[str - 1 - i][clmn - 1 - j];
			array[str - 1 - i][clmn - 1 - j] = array[i][j];
			array[i][j] = temp;
			numbop++;
			if (numbop == str * clmn / 2) break;
		}
		if (numbop == str * clmn / 2) break;
	}
}
