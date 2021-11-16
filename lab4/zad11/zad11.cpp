#include <iostream>
using namespace std;

void FillArrayR(const int& size, int* array[]);
void OutArray(const int& size, int* array[]);

int main()
{
	int size;
	cout << "enter size of array\n";
	while (true)
	{
		cin >> size;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "oops smth went wrong, try again" << endl;
		}
		else break;
	}

	int*** array = new int** [size]; //создание массива
	for (int i = 0; i < size; i++)
	{
		array[i] = new int* [size];
		for (int j = 0; j < size; j++)
		{
			array[i][j] = new int[size];
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				array[i][j][k] = rand() % 10;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << endl;
			for (int k = 0; k < size; k++)
			{
				cout << array[i][j][k] << " ";
			}
		}
		cout << endl;
	}
	int max1 = 0; //из левого верхнего в правый нижний
	for (int i = 0, j = 0, k = 0; i < size; i++)
	{
		max1 += array[i][j][k];
		j++;
		k++;
	}
	int max2 = 0; //из правого верхнего в левый нижний
	for (int i =size -1 , j = 0, k = size - 1; i >= 0; i--)
	{
		max2 += array[i][j][k];
		j++;
		k--;
	}
	

	int max3 = 0;//из левого нижнего в правый верхний

	for (int i = 0, j = size - 1, k = 0; i <size; i++)
	{
		max3 += array[i][j][k];
		j--;
		k++;
	}
	int max4 = 0;//из правого нижнего в левый верхний
	for (int i = 0, j = size - 1, k = size - 1; i < size; i++)
	{
		max4 += array[i][j][k];
		j--;
		k--;
	}
	if (max1 > max2 && max1 > max3 && max1 > max4)
	{
		cout << "1";
	}
	else if (max2 > max3 && max2 > max4) cout << "2";
	else if (max3 > max4) cout << "3";
	else cout << "4";

	

	for (int i = 0; i < size; i++)// удаление массива
	{
		for (int j = 0; j < size; j++) delete[] array[i][j];
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
