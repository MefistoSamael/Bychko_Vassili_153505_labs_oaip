#include <iostream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include "pch.h"

int razryad(int a, int i)
{
	return ((a % (int)pow(10, i))) / pow(10, i - 1);
}

void recordinarray(int numb, int* array)
{
	for (int i = 31, j = 0; i >= 0; i--, j++)//запись двоичной записи в массив
	{
		bool y = (bool((1 << i) & numb));
		array[j] = y;
	}
}



bool funk(int numba, int numbb, char* test)
{
	int* TEST = new int[32];

	for (int i = 0; i < 32; i++)
	{
		if (test[i] == '0')
			TEST[i] = 0;
		else
			TEST[i] = 1;
	}

	bool minusa = 0;
	bool minusb = 0;


	if (numba < 0)
	{
		numba = -numba;
		minusa = 1;
	}




	if (numbb < 0)
	{
		numbb = -numbb;
		minusb = 1;
	}

	int numba10 = 0;
	int numbb10 = 0;

	int* arr1 = new int[32];

	int* arr2 = new int[32];

	int* arr3 = new int[32];

	for (int i = 1; 1; i++)
	{
		int n = 0;

		n = razryad(numba, i);//возвращаем разряд

		numba10 += n * pow(2, i - 1);

		if (numba == numba % (int)pow(10, i))
			break;
	}

	if (minusa)
		numba10 = -numba10;



	for (int i = 1; 1; i++)
	{
		int n = 0;

		n = razryad(numbb, i);

		numbb10 += n * pow(2, i - 1);

		if (numbb == numbb % (int)pow(10, i))
			break;
	}

	if (minusb)
		numbb10 = -numbb10;

	recordinarray(numba10, arr1);
	recordinarray(numbb10, arr2);




	//плюс разряд
	int  r = 0;

	for (int i = 31; i >= 0; i--)
	{
		int n = arr1[i] + arr2[i] + r;

		if (n < 2)
		{
			r = 0;
			arr3[i] = n;
		}
		else if (n == 2)
		{
			r = 1;
			n = 0;
			arr3[i] = n;
		}
		else
		{
			r = 1;
			n = 1;
			arr3[i] = n;
		}
	}



	if (arr3[0] == 1)
	{

		for (int i = 31; i > 0; i--)
		{
			if (arr3[i] == 0)
			{
				arr3[i] = 1;
			}
			else
			{
				arr3[i] = 0;
			}
		}
	}






	for (int i = 0; i < 32; i++)
	{
		if (arr3[i] != TEST[i])
			return 0;
	}

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] TEST;

	return true;

}

TEST(TestCaseName, 1)
{
	bool E = 1;

	int inpa = 1;
	int inpb = -1;

	char* test = new char[32];
	test = { "00000000000000000000000000000000" };

	E = funk(inpa, inpb, test);

	EXPECT_TRUE(E);
}

TEST(TestCaseName, 2)
{
	bool E = 1;

	int inpa = 1;
	int inpb = 1;

	char* test = new char[32];
	test = { "00000000000000000000000000000010" };

	E = funk(inpa, inpb, test);

	EXPECT_TRUE(E);
}

TEST(TestCaseName, 3)
{
	bool E = 1;

	int inpa = 111;
	int inpb = 1;

	char* test = new char[32];
	test = { "00000000000000000000000000001000" };

	E = funk(inpa, inpb, test);

	EXPECT_TRUE(E);
}

TEST(TestCaseName, 4)
{
	bool E = 1;

	int inpa = 1000;
	int inpb = -111;

	char* test = new char[32];
	test = { "00000000000000000000000000000001" };

	E = funk(inpa, inpb, test);

	EXPECT_TRUE(E);
}
