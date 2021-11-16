#include <iostream>
using namespace std;

char bornb();
void FillArrayR(const int& clmn, const int& str, int* array[]);
void OutArray(const int& clmn, const int& str, int* array[]);
void FillArrayR(const int& clmn, const int& str, char* array[]);
void OutArray(const int& clmn, const int& str, char* array[]);




int main()
{
	int bombs = 0;
	int numbstr = 0;
	int numbclmn = 0;
	cout << "enter number of strings and columns\n";
	while (true)
	{
		cin >> numbstr;
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
		cin >> numbclmn;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "oops smth went wrong, try again" << endl;
		}
		else break;
	}
	
	
	char** array = new char* [numbstr]; //создание массива
	for (int i = 0; i < numbstr; i++)
	{
		array[i] = new char[numbclmn];
	}

	char** array3 = new char* [numbstr]; //создание массива
	for (int i = 0; i < numbstr; i++)
	{
		array3[i] = new char[numbclmn];
	}

	FillArrayR(numbclmn, numbstr, array);
	OutArray(numbclmn, numbstr, array);

	char** array2 = new char* [numbstr+2];//задаем 2 массив
	for (int i = 0; i < numbstr+2; i++)
	{
		array2[i] = new char[numbclmn+2];
	}


	for (int i = 0; i < numbstr+2; i++)//заполняем зрначениям 2 массив
	{
		for (int j = 0; j < numbclmn + 2; j++)
		{
			array2[i][j] = '9';
		}
	}

	for (int i = 1; i < numbstr+1; i++)//переносим значения
	{
		for (int j = 1; j < numbclmn +1; j++)
		{
			array2[i][j] = array[i-1][j-1];
		}
	}

	for (int i = 1; i < numbstr + 1; i++)//перебор 
	{
		for (int j = 1; j < numbclmn + 1; j++)
		{
			bombs = 0;
			if (array2[i][j] != '.')
			{
				array3[i-1][j-1] = '*';
				continue;
			}
			for (int k = i - 1; k < i + 2; k++)//перебор соседей значений
			{
				for (int m = j - 1; m < j + 2; m++)
				{
					if (array2[k][m] == '*') bombs++;
				}
			}
			char gi = 0;
			for (int i = 0; i < 10; i++)
			{
				if (bombs == i) gi = 48 + i;
			}
			array3[i - 1][j - 1] = gi;
		}
	}


	OutArray(numbclmn , numbstr, array3);


	for (int i = 0; i < numbstr; i++)// удаление массива
	{
		delete[] array[i];
	}
	delete[] array;

	for (int i = 0; i < numbstr + 2; i++)
	{
		delete[] array2[i];
	}
	delete[] array2;


	for (int i = 0; i < numbstr; i++)// удаление массива
	{
		delete[] array3[i];
	}
	delete[] array3;
}


void FillArrayR(const int& clmn, const int& str, char* array[])
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < clmn; j++)
		{
			array[i][j] = bornb();
		}
	}
}
void OutArray(const int& clmn, const int& str, char* array[])
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
char bornb()
{
	int g = 0;
	g = rand() % 10;
	if (g == 1) return'*';
	else return '.';
}

