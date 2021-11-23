#include "pch.h"

int prod(const int& size, int* array)
{
	int prod = 1;
	for (int i = 0; i < size; i++)
	{
		prod *= array[i];
	}
	return prod;
}


TEST(TestCaseName, Test1) {
	srand(0);
	bool A = 1;
	int* array = new int[6];
	for (int i = 0; i < 6; i++)
	{
		array[i] = rand() % 5 * 2;
	}
	int res = 1;
	int test = 0;
	res = prod(6, array);
	if (res != test) A = 0;
	EXPECT_TRUE(A);
	

}

TEST(TestCaseName, Test2) {
	srand(1);
	bool A = 1;
	int* array = new int[100];
	for (int i = 0; i < 100; i++)
	{
		array[i] = rand() % 5 * 2;
	}
	int res = 1;
	int test = 0;
	res = prod(6, array);
	if (res != test) A = 0;
	EXPECT_TRUE(A);


}

TEST(TestCaseName, Test3) {
	srand(2);
	bool A = 1;
	int* array = new int[3];
	for (int i = 0; i < 3; i++)
	{
		array[i] = rand() % 5 * 2;
		if (array[i] == 0) array[i] = 1;
	}
	int res = 1;
	int test = 12;
	res = prod(3, array);
	if (res != test) A = 0;
	EXPECT_TRUE(A);


}

