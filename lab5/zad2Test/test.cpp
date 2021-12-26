#include "pch.h"

void search(int* array, int size, int& min, int k)
{
	if (min > array[k]) min = array[k];
	k--;

	if (k == 0)
	{
		return;
	}
	search(array, size, min, k);
}

TEST(TestCaseName, Test1) {
	bool A = 1;
	int* array = new int[7];
	for (int i = 0; i < 7; i++)
	{
		array[i] = rand();
	}
	int test = 41;
	int res = array[0];
	search(array, 7, res, 6);
	if (res != test) A = 0;
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test2) {
	srand(35);
	bool A = 1;
	int* array = new int[13];
	for (int i = 0; i <13; i++)
	{
		array[i] = rand();
	}
	int test = 152;
	int res = array[0];
	search(array, 13, res, 12);
	if (res != test) A = 0;
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test3) {
	srand(475);
	bool A = 1;
	int* array = new int[4];
	for (int i = 0; i < 4; i++)
	{
		array[i] = rand();
	}
	int test = 1404;
	int res = array[0];
	search(array, 4, res, 3);
	if (res != test) A = 0;
	EXPECT_TRUE(A);
}