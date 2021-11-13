#include <iostream>
using namespace std;

void inarray(const int& size, double* array[]);
void outarray(const int& size, double* array[]);

int main()
{
	double sum = 0;
	int size;
	size = 0;
	cout << "enter size of array" << endl;
	cin >> size;
	cout << "randomize number in array? (Y or N) " << endl;
	char choice;
	cin >> choice;
	if (choice == 'Y') srand(time(NULL));



	double** array = new double* [size];//создание двумерного массива
	for (int i = 0; i < size; i++)
	{
		array[i] = new double[size];
	}
	inarray(size, array); //ввод массива
	outarray(size,array);// вывод массива


	double** arrN = new double* [size + 2];//создание нового массива
	for (int i = 0; i < size + 2; i++)
	{
		arrN[i] = new double[size + 2];
	}
	for (int i = 0; i < size + 2; i++)// заполнение циферками
	{
		for (int j = 0; j < size + 2; j++)
		{
			arrN[i][j] = 11;
		}
	}
	for (int i = 1; i < size + 1; i++) //копирование значений из старого массива
	{
		for (int j = 1; j < size + 1; j++)
		{
			arrN[i][j] = array[i - 1][j - 1];
		}
	}

	

	for (int i = 0; i < size; i++)//удаление двумерного массива
	{
		delete [] array[i];
	}
	array = arrN;

	cout << endl;
	cout << endl;
	int z = 0;//счётчик лишних циферок

	for (int i = 1; i < size + 1; i++)
	{
		for (int j = 1; j < size + 1; j++)
		{
			z = 0;
			sum = 0;
			int k = i;
			for (k = k - 1; k<i+2; k++)
			{
				int m = j;
				for (m = m - 1 ; m < j + 2; m++)
				{
					if (i == k && m == j) continue;
					if (array[k][m] == 11.0)
					{
						z++;
						continue;
					}
					sum += array[k][m];
				}
			}
			sum /= 8 - z;
			cout << sum << " ";
			
		}
		cout << endl;
	}

	for (int i = 0; i < size; i++)//удаление двумерного массива
	{
		delete[] array[i];
	}
	delete[] array;

	return 0;
}


void inarray(const int& size, double* array[])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			array[i][j] = rand() % 10;
		}
	}
}
void outarray(const int& size, double* array[])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

