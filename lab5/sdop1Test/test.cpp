#include "pch.h"

int F(int n)
{
	if (n % 10 > 0) return n % 10;
	if (n == 0) return 0;
	return F(n / 10);
}

int S(int p, int q)
{
	int sum = 0;
	for (int i = p; i < q + 1; i++)
	{
		sum += F(i);
	}
	return sum;
}


/*
TEST(TestCaseName, TestName) {
	bool a = true;
	int p = ;
	int q = ;
	int test = ;
	int sum = S(p, q);

	if (sum != test)
	{
		a = false;
	}
	EXPECT_TRUE(a);
}
*/

TEST(TestCaseName, Test1) {
	bool a = true;
	int p = 1;
	int q = 10;
	int test = 46;
	int sum = S(p, q);

	if (sum != test)
	{
		a = false;
	}
	EXPECT_TRUE(a);
}

TEST(TestCaseName, Test2) {
	bool a = true;
	int p = 10;
	int q = 20;
	int test = 48;
	int sum = S(p, q);

	if (sum != test)
	{
		a = false;
	}
	EXPECT_TRUE(a);
}

TEST(TestCaseName, Test3) {
	bool a = true;
	int p = 30;
	int q = 40;
	int test = 52;
	int sum = S(p, q);

	if (sum != test)
	{
		a = false;
	}
	EXPECT_TRUE(a);
}

TEST(TestCaseName, Test4) {
	bool a = true;
	int p = 1;
	int q = 1;
	int test = 1;
	int sum = S(p, q);

	if (sum != test)
	{
		a = false;
	}
	EXPECT_TRUE(a);
}

TEST(TestCaseName, Test5) {
	bool a = true;
	int p = 2147483646;
	int q = 2147483646;
	int test = 6;
	int sum = S(p, q);

	if (sum != test)
	{
		a = false;
	}
	EXPECT_TRUE(a);
}

TEST(TestCaseName, Test6) {
	bool a = true;
	int p = 2147483645;
	int q = 2147483645;
	int test = 5;
	int sum = S(p, q);

	if (sum != test)
	{
		a = false;
	}
	EXPECT_TRUE(a);
}

TEST(TestCaseName, Test7) {
	bool a = true;
	int p = 137;
	int q = 137;
	int test = 7;
	int sum = S(p, q);

	if (sum != test)
	{
		a = false;
	}
	EXPECT_TRUE(a);
}



