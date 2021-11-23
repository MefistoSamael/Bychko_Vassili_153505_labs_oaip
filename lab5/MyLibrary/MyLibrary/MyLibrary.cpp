#include "pch.h"
#include <iostream>
#include <limits.h>
#include "MyLibrary.h"
using namespace std;

void check(int& number)
{
	while (true)
	{
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "oops, smth went wrong, try again\n";
		}
		else break;
	}
}

void Fill(const int& str, const int& clmn, int** array)
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < clmn; j++)
		{
			cout << "Enter array[" << i << "][" << j << "] ";
			check(array[i][j]);
		}
	}
}

void Out2(const int& str, const int& clmn, int** array)
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < clmn; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void Out(const int& size, int* array)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}

int prod(const int& size, int* array)
{
	int prod = 1;
	for (int i = 0; i < size; i++)
	{
		prod *= array[i];
	}
	return prod;
}

