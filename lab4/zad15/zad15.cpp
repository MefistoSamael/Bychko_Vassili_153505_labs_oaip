#include <iostream>
using namespace std;

void FillArrayR(const int& size, int* array[]);
void OutArray(const int& size, int* array[]);

int main()
{
	int size = 0;
	int number;
	cout << "enter number\n";
	while (true)
	{
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "oops smth went wrong, try again" << endl;
		}
		else break;
	}

	size = sqrt(number) + 1;


	int** array = new int* [size]; //создание массива
	for (int i = 0; i < size; i++)
	{
		array[i] = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			array[i][j] = 0;
		}
	}
	OutArray(size, array);
	int k = 1;
	array[0][0] = k;
	k++;
	for (int i = 0, j = 0; i < size;)
	{
		i = 0;
		if (array[i][j + 1] == 0)
		{
			j++;
			array[i][j] = k;
			if (k == number)
			{
				cout << i + 1 << " string; " << j + 1 << " clmn";
			}
			k++;
		}
		for (; array[i + 1][j] == 0;)
		{
			i++;
			array[i][j] = k;
			if (k == number)
			{
				cout << i + 1 << " string; " << j + 1 << " clmn";
			}
			k++;
			if (array[i][j - 1] == 0) break;
		}
		while (j > 0)
		{
			j--;
			array[i][j] = k;
			if (k == number)
			{
				cout << i + 1 << " string; " << j + 1 << " clmn";
			}
			k++;
		}
		j = i;
		if (i == size - 1) break;
		continue;
	}



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

