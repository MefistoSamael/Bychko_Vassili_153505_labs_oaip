#include <iostream>
using namespace std;

void FillArrayR(const int& str, const int& clmn, int* array[]);
void OutArray(const int& str, const int& clmn, int* array[]);

int main()
{
	srand(time(NULL));
	int str;
	int clmn;
	cout << "enter numb of str and clmn in that order\n";
	while (true)
	{
		cin >> str;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "oops smth went wrong, try again" << endl;
		}
		else break;
	}
	while (true)
	{
		cin >> clmn;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "oops smth went wrong, try again" << endl;
		}
		else break;
	}

	int** array = new int* [str]; //создание массива
	for (int i = 0; i < str; i++)
	{
		array[i] = new int[clmn];
	}

	FillArrayR(str,clmn, array);
	OutArray(str,clmn, array);
	int max;
	max = 0;
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < clmn; j++)
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
	OutArray(str,clmn, array);

	for (int i = 0; i < str; i++)// удаление массива
	{
		delete[] array[i];
	}
	delete[] array;

}


void FillArrayR(const int& str, const int& clmn, int* array[])
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < clmn; j++)
		{
			array[i][j] = rand() % 10;
		}
	}
}
void OutArray(const int& str, const int& clmn, int* array[])
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
