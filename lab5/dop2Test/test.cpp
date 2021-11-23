#include "pch.h"
void search(const int& str, const int& clmn, int** array, int& numz)
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < clmn; j++)
		{
			if (array[i][j] == 0)
			{
				numz++;
			}
		}
	}
}


void replace(const int& str, const int& clmn, int** array)
{
	int numbop = 0;
	for (int i = str - 1; i >= 0; i--)
	{
		for (int j = clmn - 1; j >= 0; j--)
		{
			int temp = array[str - 1 - i][clmn - 1 - j];
			array[str - 1 - i][clmn - 1 - j] = array[i][j];
			array[i][j] = temp;
			numbop++;
			if (numbop == str * clmn / 2) break;
		}
		if (numbop == str * clmn / 2) break;
	}
}


TEST(TestReplace, Test1) {
	bool A = true;
	int** array = new int*[6];
	for (int i = 0; i < 6; i++)
	{
			array[i] = new int[3];
	}
	int m = 1;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			array[i][j] = m;
			m++;
		}

	}
	replace(6, 3, array);
	int** testarray = new int*[6];
	for (int i = 0; i < 6; i++)
	{
		testarray[i] = new int[3];
	}
	m = 18;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			testarray[i][j] = m;
			m--;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (array[i][j] != testarray[i][j]) A = false;
		}
	}
	EXPECT_TRUE(A);
}

TEST(TestZero, Test1) {
	bool A = true;
	int** array = new int* [6];
	for (int i = 0; i < 6; i++)
	{
		array[i] = new int[3];
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			array[i][j] = rand() % 10;
			if (array[i][j] == 2) array[i][j] = 0;
		}
	}
	int test = 3;
	int res = 0;
	search(6, 3, array, res);
	if (test != res) A = false;
	EXPECT_TRUE(A);	


	
}