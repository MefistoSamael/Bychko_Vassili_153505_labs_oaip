#include "pch.h"

void calc(long long& k, long long& n, long long& t, long long& prod)
{
	long long cln = n;
	while (true)
	{
		k = k % (long long)pow(10, 9);
		long long g = 1;
		long long x = k;

		while (g < cln)
		{
			g *= 2;
			if (g > cln)
			{
				g /= 2;
				break;
			}
			x = (x * x) % (long long)pow(10, t);
		}

		cln -= g;
		prod = (prod * x) % (long long)pow(10, 9);
		if (cln <= 0)
		{
			break;
		}
	}
	prod = prod % (long long)pow(10, t);

}
/*
TEST(TestCaseName, TestName) {
	bool a = true;
	long long k =;
	long long n =;
	long long t =;
	long long prod = 1;
	long long test = ;

	calc(k, n, t, prod);
	if (prod != test)
	{
		a = false;
	}
	EXPECT_TRUE(a);

}
*/
TEST(TestCaseName, Test1) {
	bool a = true;
	long long k =1;
	long long n =1000;
	long long t =1;
	long long prod = 1;
	long long test = 1;

	calc(k, n, t, prod);
	if (prod != test)
	{
		a = false;
	}
	EXPECT_TRUE(a);

}

TEST(TestCaseName, Test2) {
	bool a = true;
	long long k = 1234;
	long long n = 1234;
	long long t = 4;
	long long prod = 1;
	long long test = 736;

	calc(k, n, t, prod);
	if (prod != test)
	{
		a = false;
	}
	EXPECT_TRUE(a);
}

TEST(TestCaseName, Test3) {
	bool a = true;
	long long k = 999999999999999999;
	long long n = 999999999999999999;
	long long t = 8;
	long long prod = 1;
	long long test = 99999999;

	calc(k, n, t, prod);
	if (prod != test)
	{
		a = false;
	}
	EXPECT_TRUE(a);

}

TEST(TestCaseName, Test4) {
	bool a = true;
	long long k = 2323;
	long long n = 99999999999;
	long long t = 8;
	long long prod = 1;
	long long test = 39087387;

	calc(k, n, t, prod);
	if (prod != test)
	{
		a = false;
	}
	EXPECT_TRUE(a);

}


