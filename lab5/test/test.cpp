#include "pch.h"
using namespace std;

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
	int test = 20;
	calc(n, res);
	if (test != res) A = false;
	EXPECT_TRUE(A);
}

