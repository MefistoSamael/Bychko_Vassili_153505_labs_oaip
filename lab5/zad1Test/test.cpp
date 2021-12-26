#include "pch.h"

void search(int* max, int* str, int* clmn, int** array)
{
	for (int i = 0; i < *str; i++)//search func
	{
		for (int j = 0; j < *clmn; j++)
		{
			if (array[i][j] > *max) *max = array[i][j];
		}
	}
}

TEST(TestCaseName, Test1) {
	
	bool A = 1;
	int str = 7;
	int clmn = 8;
	int test = 32757;
	int** array = new int* [str];
	for (int i = 0; i < str; i++)
	{
		array[i] = new int[clmn];
	}
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < clmn; j++)
		{
			array[i][j] = rand();
		}
	}
	int res = array[0][0];
	search(&res, &str, &clmn, array);
	if (test != res) A = 0;
	EXPECT_TRUE(A);

}

TEST(TestCaseName, Test2) {
	srand(5);
	bool A = 1;
	int str = 6;
	int clmn = 14;
	int test = 32640;
	int** array = new int* [str];
	for (int i = 0; i < str; i++)
	{
		array[i] = new int[clmn];
	}
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < clmn; j++)
		{
			array[i][j] = rand();
		}
	}
	int res = array[0][0];
	search(&res, &str, &clmn, array);
	std::cout << "res = " << res;
	if (test != res) A = 0;
	EXPECT_TRUE(A);

}

TEST(TestCaseName, Test3) {
	srand(137);
	bool A = 1;
	int str = 1;
	int clmn = 5;
	int test = 22311;
	int** array = new int* [str];
	for (int i = 0; i < str; i++)
	{
		array[i] = new int[clmn];
	}
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < clmn; j++)
		{
			array[i][j] = rand();
		}
	}
	int res = array[0][0];
	search(&res, &str, &clmn, array);
	std::cout << "res = " << res;
	if (test != res) A = 0;
	EXPECT_TRUE(A);

}