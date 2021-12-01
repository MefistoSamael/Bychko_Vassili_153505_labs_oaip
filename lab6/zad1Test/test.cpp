#include "pch.h"
void search(char *str1, int numb)
{
	int i = 0;
	for (; i < strlen(str1); i++)
	{
		if (str1[i] != ' ') break;
	}


	numb = 0;
	for (; str1[i] != '\0'; )
	{
		int numb1 = 0;
		int numbel = 0;
		int j = i;
		for (; str1[j] != ' ' && str1[j] != '\0'; j++)
		{
			if (str1[j] == '1') numb1++;
			numbel++;
		}
		if (numbel % 2) numb += numb1;
		i = j + 1;
	}
}

TEST(TestCaseName, Test1) {
	bool A = 1;
	char str1[80] = { " 111" };
	int res = 0;
	int test = 3;
	search(str1, res);
	if (res != test) A = 0;
}

TEST(TestCaseName, Test2) {
	bool A = 1;
	char str1[80] = { " 101 1         " };
	int res = 0;
	int test = 3;
	search(str1, res);
	if (res != test) A = 0;
}

TEST(TestCaseName, Test3) {
	bool A = 1;
	char str1[80] = { "   " };
	int res = 1;
	int test = 0;
	search(str1, res);
	if (res != test) A = 0;
}

TEST(TestCaseName, Test4) {
	bool A = 1;
	char str1[80] = { "   " };
	int res = 1;
	int test = 0;
	search(str1, res);
	if (res != test) A = 0;
}

TEST(TestCaseName, Test5) {
	bool A = 1;
	char str1[80] = { " 0111010 1100 1 0  101    " };
	int res = 7;
	int test = 0;
	search(str1, res);
	if (res != test) A = 0;
}
