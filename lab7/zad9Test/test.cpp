#include "pch.h"


void func(int*array, int*array2, int* answer,int size)
{
	for (int j = 0; j < size; j++)
	{
		answer[j] = array[j] + array2[j];
	}
}

TEST(TestCaseName, 1) {
	bool B = 1;

	int input = 99;
	int array[4] = { 1,1,1,1 };
	int array2[4] =  { 2, 0, 1, 2 };
	int answer [4];
	int test[4] = { 3,1,2,3 };
	int size = 4;

	func(array, array2, answer, size);
	for (int i = 0; i < 4; i++)
	{
		if (answer[i] != test[i]) B = 0;
	}


  EXPECT_TRUE(B);
}

TEST(TestCaseName, 2) {
	bool B = 1;

	int input = 9;
	int array[4] = { 1,1 };
	int array2[4] = { 1,2};
	int answer[4];
	int test[4] = { 2,3 };
	int size = 2;

	func(array, array2, answer, size);
	for (int i = 0; i < 2; i++)
	{
		if (answer[i] != test[i]) B = 0;
	}


	EXPECT_TRUE(B);
}

TEST(TestCaseName, 3) {
	bool B = 1;

	int input = 9;
	int array[4] = { 1,1,1,1 };
	int array2[4] = { 1 };
	int answer[4];
	int test[4] = { 1,1,1,2 };

	func(array, array2, answer, 4);
	for (int i = 0; i < 4; i++)
	{
		if (answer[i] != test[i]) B = 0;
	}


	EXPECT_TRUE(B);
}


