#include "pch.h"

void calc(const int& n, long long& sum)
{
	for (int i = 1; i < n + 1; i++)
	{
		if (i % 2 != 0)
		{
			sum += i;
			continue;
		}
		else
		{
			int j = 0;
			for (j = i; j % 2 == 0; )
			{
				j /= 2;
			}
			sum += j;
		}
	}
}


TEST(TestCaseName, Test1) {
	bool a = true;
	long long n = 1;
	long long test = 1;

	long long res = 0;
	calc(n, res);
	if (res != test)
	{
		a = false;
	}
	EXPECT_TRUE(a);
}

TEST(TestCaseName, Test2) {
	bool a = true;
	long long n = 2;
	long long test = 2;

	long long res = 0;
	calc(n, res);
	if (res != test)
	{
		a = false;
	}
	EXPECT_TRUE(a);
}

TEST(TestCaseName, Test3) {
	bool a = true;
	long long n = 7;
	long long test = 21;

	long long res = 0;
	calc(n, res);
	if (res != test)
	{
		a = false;
	}
	EXPECT_TRUE(a);
}


TEST(TestCaseName, Test4) {
	bool a = true;
	long long n = 777;
	long long test = 201537;

	long long res = 0;
	calc(n, res);
	if (res != test)
	{
		a = false;
	}
	EXPECT_TRUE(a);
}

TEST(TestCaseName, Test5) {
	bool a = true;
	long long n = 1000000000;
	long long test = 333333333334181226;

	long long res = 0;
	calc(n, res);
	if (res != test)
	{
		a = false;
	}
	EXPECT_TRUE(a);
}