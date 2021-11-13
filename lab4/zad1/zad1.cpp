#include <iostream>
using namespace std;

int main()
{
	const int k = 10;
	int array[k];
	int j = 0;
	cout << "enter numbers in array"<< endl;
	for (int i = 0; i < k; i++) //ввод
	{
		cin >> array[i];
	}
	for (int i = 0; i < k; i++) //вывод
	{
		cout << array[i] << " ";

	}
	cout << endl;
	for (int i = 0; i < k;i++)//берем i-й член массива
	{
		for (j = 0; j < k; j++)//сравниваем с остальными
		{
			if (i == j) continue;
			if (array[i] == array[j]) //если члены совпадают
			{
				break;
			}
		}
		if (j == k) //если массив был пройден полностью
		{
			cout << array[i] << " ";
		}
	}
	return 0;
} 
