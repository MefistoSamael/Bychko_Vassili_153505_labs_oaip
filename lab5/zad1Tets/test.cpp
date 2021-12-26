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
	bool A = true;
	int n = 7;
	long long res = 0;
	int test = 21;
	calc(n, res);
	if (test != res) A = false;
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test2) {
	bool A = true;
	int n = 10e9;
	long long res = 0;
	long long test = 662761484946639900;
	calc(n, res);
	std::cout << "res = " << res;
	if (test != res) A = false;
	EXPECT_TRUE(A);
}
TEST(TestCaseName, Test3) {
	bool A = true;
	int n = 10e9 + 1;
	long long res = 0;
	long long test = 662761486356705309;
	calc(n, res);
	std::cout << "res = " << res;
	if (test != res) A = false;
	EXPECT_TRUE(A);
}
