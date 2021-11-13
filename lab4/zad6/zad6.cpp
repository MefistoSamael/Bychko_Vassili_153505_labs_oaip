#include <iostream>
using namespace std;

void FillArrayR(const int& size, int* array[]);
void OutArray(const int& size, int* array[]);

int main()
{
	int size;
	cout << "enter size of array\n";
	//cin >> size;
	size = 3;

	int** array = new int* [size]; //создание массива
	for (int i = 0; i < size; i++)
	{
		array[i] = new int[size];
	}

	FillArrayR(size, array);
	OutArray(size, array);
	int max;
	max = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			max = 0;
			max = array[i][j];
			int k = i;
			for (k; k >= 0; k--)
			{
				int m = j;
				for (m ; m >= 0; m--)
				{
					if (array[k][m] > max) max = array[k][m];
				}
			}
			array[i][j] = max;
		}
	}
	OutArray(size, array);

	for (int i = 0; i < size; i++)// удаление массива
	{
		delete[] array[i];
	}
	delete[] array;

}


void FillArrayR(const int& size, int* array[])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			array[i][j] = rand() % 10;
		}
	}
}
void OutArray(const int& size, int* array[])
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}
