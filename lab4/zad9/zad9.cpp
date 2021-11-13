#include <iostream>
#define a array1
#define b array2
using namespace std;

void FillArrayR(const int& clmn, const int& str, int* array[]);
void OutArray(const int& clmn, const int& str, int* array[]);

int main()
{
	int numbstr = 0;
	int numbclmn = 0;
	cout << "enter number of strings and columns in 1array\n";
	cin >> numbstr;
	cin >> numbclmn;


	int** array1 = NULL; //создание массива
	array1 = (int**) malloc(numbstr * sizeof(int));
	for (int i = 0; i < numbstr; i++)
	{
		array1[i] = (int*)malloc(numbclmn * sizeof(int));
	}

	FillArrayR(numbclmn, numbstr, array1);
	OutArray(numbclmn, numbstr, array1);

	cout << "enter number of strings and columns in 2 array\n";
	int numbstr2 = 0;
	int numbclmn2 = 0;
	//тут должна ыбть проверка на ввод
	cin >> numbstr2;
	cin >> numbclmn2;

	int** array2 = NULL;
	array2 = (int**)malloc(numbstr2 * sizeof(int));
	for (int i = 0; i < numbstr2; i++)
	{
		array2[i] = (int*) malloc(numbclmn2 * sizeof(int));
	}

	FillArrayR(numbclmn2, numbstr2, array2);
	OutArray(numbclmn2, numbstr2, array2);

	int** array3 = NULL;
	array3 = (int**)malloc(numbstr * sizeof(int));
	for (int i = 0; i < numbstr; i++)
	{
		array3[i] = (int*) malloc(numbclmn2 * sizeof(int));
	}

	for (int i = 0; i < numbstr; i++)
	{
		for (int j = 0; j < numbclmn2; j++)
		{
			array3[i][j] = 0;
		}
	}

	OutArray(numbclmn2, numbstr, array3);

	for (int i = 0; i < numbstr; i++)
	{
		for (int j = 0; j < numbstr; j++)
		{
			array3[i][j] = 0;
			for (int k = 0; k < numbclmn2; k++)
			{
				array3[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	OutArray(numbclmn2, numbstr, array3);



	for (int i = 0; i < numbstr; i++)// удаление массива
	{
		free (array1[i]);
	}
	free(array1);

	for (int i = 0; i < numbstr2; i++)// удаление массива
	{
		free(array2[i]);
	}
	free (array2);

	for (int i = 0; i < numbstr; i++)// удаление массива
	{
		free(array3[i]);
	}
	free(array3);

}


void FillArrayR(const int& clmn, const int& str, int* array[])
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < clmn; j++)
		{
			array[i][j] = rand() % 10;
		}
	}
}
void OutArray(const int& clmn, const int& str, int* array[])
{
	cout << endl;
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < clmn; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}
