#include "pch.h"

void avg(const int& size, int* array, int& avg)
{
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		avg += array[i];
		k++;
	}
	avg /= k;
}
/*
TEST(TestCaseName, Test1) {
	bool A = true;
	int size = ;
	int* array = new int[] {};
	int test = ;
	int res = 0;
	if (res != test)
	{
	A = false;
	}
	EXPECT_TRUE(A);

}
*/

TEST(TestCaseName, Test1) {
	bool A = true;
	int size = 6;
	int* array = new int[6]{ 1,1,1,1,1,1 };
	int test = 1;
	int res = 0;
	avg(6,array, res);
	if (res != test)
	{
		A = false;
	}
	EXPECT_TRUE(A);
}


TEST(TestCaseName, Test2) {
	bool A = true;
	int* array = new int[3]{83,65, 103};
	int test = 83;
	int res = 0;
	avg(3, array, res);
	if (res != test)
	{
		A = false;
	}
	EXPECT_TRUE(A);

}

TEST(TestCaseName, Test3) {
	bool A = true;
	int* array = new int[4]{ 3,65,9, 147 };
	int test = 56;
	int res = 0;
	avg(4, array, res);
	if (res != test)
	{
		A = false;
	}
	EXPECT_TRUE(A);

}




