#include <iostream>
using namespace std;

void delel(int& size, int*& array, int nom);
void FillArrayR(const int& size, int array[]);
void OutArray(const int& size, int array[]);

int main()
{
	int size = 0;
	cout << "enter size of array\n";
	//cin >> size;
	size = 9;
	int sizen = size;

	
	int* array = new int [size]; //создание массива

	FillArrayR(size, array);
	OutArray(size, array);

	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (array[j] == array[i])
			{
				delel(size, array, j + 1);
				j--;
			}
		}
	}
	
	

	

	

	OutArray(size, array);
	cout << "\nNew size = " << size;
	delete[] array;
	return 0;
}

void FillArrayR(const int& size, int array[])
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 10;
	}
}
void OutArray(const int& size, int array[])
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
			cout << array[i] << " ";
	}
}
void delel(int& size, int*& array, int numb)
{
	int* newarray = new int[size - 1];
	for (int i = 0, j = 0; i < size; i++, j++)
	{
		if (i == numb - 1) i++;
		newarray[j] = array[i];
	}
	size--;
	delete[] array;
	array = newarray;
}


/*
for (int i = 0; i < size; i++)
{
	k = 0;
	for (int j = i; j < size; j++)
	{
		if (array[i] == array[j])
		{
			k++;
		}

	}
	if (k > 1)
	{
		sizen = sizen - k + 1;
	}
}
k = 0;
int z = 0;

for (int i = 0; i < size; i++)
{
	k = 0;
	for (int j = 0; j < size; j++)
	{
		if (array[i] == array[j])
		{
			k++;
		}
		if (k > 1 && array[i] == array[j])
		{
			continue;
		}
		arraynew[k] = array[i];
		k++;
	}
}*/


