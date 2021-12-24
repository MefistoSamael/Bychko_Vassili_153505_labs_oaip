#include "pch.h"

int fuk(int a)
{
	if (a == 1) return 1;
	return a * fuk(a - 1);
}

int funk(char* str)
{
	int div = 1;
	for (int i = 0; i < strlen(str) - 1; i++)
	{
		if (str[i] == '*') continue;
		int numbl = 1;
		for (int g = i + 1; g < strlen(str); g++)
		{
			if (str[i] == str[g])
			{
				str[g] = '*';
				numbl++;
			}
		}
		div *= fuk(numbl);
	}

	return fuk(strlen(str)) / div;
}

TEST(TestCaseName, Test1) {
	bool A = 1;
	int test = 1;
	int res = 0;
	char str[14] = { "oo" };
	res = funk(str);

	if (test != res) A = 0;
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test2) {
	bool A = 1;
	int test = 1;
	int res = 0;
	char str[14] = { "o" };
	res = funk(str);

	if (test != res) A = 0;
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test3) {
	bool A = 1;
	int test = 120;
	int res = 0;
	char str[14] = { "kosovo" };
	res = funk(str);

	if (test != res) A = 0;
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test4) {
	bool A = 1;
	int test = 12;
	int res = 0;
	char str[14] = { "solo" };
	res = funk(str);

	if (test != res) A = 0;
	EXPECT_TRUE(A);
}



//oo
// 
//o
// 
// kosovo - 120
//