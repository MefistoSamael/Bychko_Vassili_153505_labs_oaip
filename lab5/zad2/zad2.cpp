/*
Для заданного одномерного массива A из N элементов найти значение минимального
элемента массива и его номер. Рекурсивную функцию применять каждый раз отдельно
для каждой из половин массива. Рекурсивные вызовы заканчивать, когда останется
только один элемент.
*/


#include <iostream> //стек - облатсь в памяти где выполняется программа
#include "..\TrueStaticLib\TrueStaticLib\Header.h"
using namespace std;


int main()
{
	srand(time(NULL));
	int z = 0;
	int k = 0;
	int min1 = 0;
	int min2 = 0;
	int size = 0;
	cout << "enter size of array, size must be even ";
	cin >> size;

	int* array = new int[size];

	for (int i = 0; i < size; i++)
	{
		cout << "enter array[" << i << "] ";
		cin >> array[i];
	}
	min1 = array[0];
	min2 = array[0];
	cout << endl;
	for (int i = 0; i < size; i++) //out func
	{
		cout << array[i] << " ";
	}
	cout << endl;
	int temp = 0;
	int j = 0;

	int* array1 = new int[size / 2];
	int* array2 = new int[size / 2];

	search(array1, size/2,min1, size/2 - 1);
	search(array2, size/ 2, min2, size / 2 -1);
	if (min1 < min2) cout << "min = " << min1;
	else cout << "min = " << min2;

	delete[] array;
	delete[] array1;
	delete[] array2;
	return 0;
}

