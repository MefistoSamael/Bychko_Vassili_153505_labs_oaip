#include <iostream>
#include <limits>
using namespace std;

void FillArray(const int& size, int array[]);
void OutArray(const int& size, int array[]);

int main()
{
	int size;
	cout << "enter size of array\n";
	cin >> size;
	//size = 9;
	int max = 0;
	int min = INT_MAX;
	int imax = 0;
	int imin = 0;
	int numofz = 0;
	srand(time(NULL));


	//int* array = new int [size] {100, 2, 3, 4, 5, 6, 1, 9, 10}; 
	int* array = new int[size]; //создание массива

	FillArray(size, array);
	OutArray(size, array);
	//если сломают сделай проверку на равнство всех эллементов массива
	for (int i = 0; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
			imax = i;
		}
		else if (array[i] < min)
		{
			min = array[i];
			imin = i;
		}
	}
	cout << endl << imax << endl;
	cout << imin << endl;
	if (imax < imin)
	{
		for (int i = imax + 1; i < imin; i++)
		{
			array[i] = 0;
			numofz++;
		}
	}
	else
	{
		for (int i = imin + 1; i < imax; i++)
		{
			array[i] = 0;
			numofz++;
		}
	}
	OutArray(size, array);
	int* arraynew = new int[size - numofz];
	if (numofz > size / 2)
	{
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			if (array[i] != 0)
			{
				arraynew[j] = array[i];
				j++;
			}

		}
	}
	

	delete[] array;

	OutArray(size - numofz, arraynew);

	delete[] arraynew;

}


void FillArray(const int& size, int array[])
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand();
	}
	while (true)
	{
		int z = 0;
		here:
		for (int i = 0; i < size; i++)
		{
			int z = 0;
			for (int j = 0; j < size; j++)
			{
				if (array[j] == array[i])
				{
					array[i] = rand();
				}
				z++;
			}
		}
		if (z != 0) goto here;
		else break;
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
