#include "pch.h"

int search(int a, int b)
{
	while (a <= b >> 1)
	{
		return search(a + a, b);
	}
	return a;
}

int diff(int a, int b)
{
	return a + ~b + 1;
}


bool func(int n,int numb, int i = 0)
{
	for (i = numb; i >= n; )
	{
		i = diff(i, search(n, i));
	}
	if (i == 0) return 0;
	else return 1;
}


TEST(TestCaseName, Test1) {
	bool Y = 1;
	int input = 317;
	bool res = 0;
	bool test = 1;
	res = func(5, input);
	res = func(73, input);
	res = func(151, input);
	if (test != res) Y = 0;

	EXPECT_TRUE(Y);
 
}

TEST(TestCaseName, Test2) {
	bool Y = 1;
	int input = 331;
	bool res = 0;
	bool test = 1;
	res = func(5, input);
	res = func(73, input);
	res = func(151, input);
	if (test != res) Y = 0;

	EXPECT_TRUE(Y);

}

TEST(TestCaseName, Test3) {
	bool Y = 1;
	int input = 3137;
	bool res = 0;
	bool test = 1;
	res = func(5, input);
	res = func(73, input);
	res = func(151, input);
	if (test != res) Y = 0;

	EXPECT_TRUE(Y);

}


