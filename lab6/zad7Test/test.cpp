#include "pch.h"

int func(char* str)
{
	int length = 0;
	for (int i = 0; i < strlen(str) - 2; i++)
	{
		for (int g = strlen(str) - 1; g != i; g--)
		{
			if (str[i] != str[g])
			{
				if (strlen(str) - 1 - i > length)
				{
					length = strlen(str) - 1 - i;
				}
				break;
			}
		}
	}

	if (length == 0)
	{
		length = -1;
	}
	return length;

}


TEST(TestCaseName, Test1) {
	bool A = 1;
	int test = 13;
	int res = 0;
	char str[106] = {"aaaaaaaaaaaaab"};
	res = func(str);

	if (test != res) A = 0;
  EXPECT_TRUE(A);
}

TEST(TestCaseName, Test2) {
	bool A = 1;
	int test = 13;
	int res = 0;
	char str[106] = { "baaaaaaaaaaaaa" };
	res = func(str);

	if (test != res) A = 0;
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test3) {
	bool A = 1;
	int test = -1;
	int res = 0;
	char str[106] = { "aaaaaaaaaaaaa" };
	res = func(str);

	if (test != res) A = 0;
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test4) {
	bool A = 1;
	int test = 2;
	int res = 0;
	char str[106] = { "aba" };
	res = func(str);

	if (test != res) A = 0;
	EXPECT_TRUE(A);
}